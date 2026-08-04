#!/usr/bin/env bash
# Package Retro Emulator Studio for Linux or macOS.
# Usage:
#   ./tools/package_love.sh           # auto-detect host OS
#   ./tools/package_love.sh linux
#   ./tools/package_love.sh macos
# Output:
#   dist/linux/RetroStudio/   or   dist/macos/RetroStudio/

set -euo pipefail

LOVE_VERSION="11.5"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
# Repo trees required next to the host (discovery + IDE Tiny-C/ASM toolchain).
SIDECAR_DIRS=(machines cpus framework ui lang asm stdlib projects rom)

TARGET="${1:-}"
if [[ -z "$TARGET" ]]; then
  case "$(uname -s)" in
    Darwin) TARGET="macos" ;;
    Linux)  TARGET="linux" ;;
    *)
      echo "Unknown OS; pass 'linux' or 'macos'" >&2
      exit 1
      ;;
  esac
fi

need() {
  command -v "$1" >/dev/null 2>&1 || {
    echo "Missing required tool: $1" >&2
    exit 1
  }
}

need curl
need unzip

ensure_dir() { mkdir -p "$1"; }

build_love() {
  local staging="$REPO_ROOT/dist/_love_stage"
  local love_out="$REPO_ROOT/dist/RetroStudio.love"
  rm -rf "$staging"
  ensure_dir "$staging"
  cp -a "$REPO_ROOT/frontends/love2d/." "$staging/"
  rm -f "$love_out"
  (
    cd "$staging"
    if command -v zip >/dev/null 2>&1; then
      zip -9 -r "$love_out" . >/dev/null
    else
      # Fallback: Python zipfile
      python3 - <<PY
import zipfile, os
root = "."
out = r"$love_out"
with zipfile.ZipFile(out, "w", zipfile.ZIP_DEFLATED) as z:
    for dirpath, _, files in os.walk(root):
        for f in files:
            p = os.path.join(dirpath, f)
            z.write(p, os.path.relpath(p, root))
PY
    fi
  )
  rm -rf "$staging"
  echo "Built $love_out"
}

mirror_sidecar() {
  local dest="$1"
  local name src dst
  for name in "${SIDECAR_DIRS[@]}"; do
    src="$REPO_ROOT/$name"
    dst="$dest/$name"
    rm -rf "$dst"
    if [[ -d "$src" ]]; then
      echo "  copy $name/"
      mkdir -p "$(dirname "$dst")"
      cp -a "$src" "$dst"
    else
      ensure_dir "$dst"
    fi
  done
  ensure_dir "$dest/saves"
  : > "$dest/saves/.gitkeep"
}

download() {
  local url="$1" out="$2"
  if [[ -f "$out" ]]; then
    return 0
  fi
  echo "Downloading $url ..."
  ensure_dir "$(dirname "$out")"
  curl -fL --retry 3 -o "$out" "$url"
}

package_linux() {
  local out="$REPO_ROOT/dist/linux/RetroStudio"
  local cache="$REPO_ROOT/tools/love/linux"
  local appimage_name="love-${LOVE_VERSION}-x86_64.AppImage"
  local url="https://github.com/love2d/love/releases/download/${LOVE_VERSION}/${appimage_name}"
  local appimage="$cache/$appimage_name"
  local love_out="$REPO_ROOT/dist/RetroStudio.love"

  echo "== RetroStudio Linux package =="
  rm -rf "$out"
  ensure_dir "$out"
  ensure_dir "$cache"

  build_love
  download "$url" "$appimage"
  cp -f "$appimage" "$out/love.AppImage"
  chmod +x "$out/love.AppImage"
  cp -f "$love_out" "$out/RetroStudio.love"

  cat > "$out/run.sh" <<'EOF'
#!/usr/bin/env bash
set -euo pipefail
DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$DIR"
exec "$DIR/love.AppImage" "$DIR/RetroStudio.love" "$@"
EOF
  chmod +x "$out/run.sh"

  # Optional convenience name
  cat > "$out/RetroStudio" <<'EOF'
#!/usr/bin/env bash
exec "$(cd "$(dirname "$0")" && pwd)/run.sh" "$@"
EOF
  chmod +x "$out/RetroStudio"

  echo "Staging sidecar trees..."
  mirror_sidecar "$out"
  echo ""
  echo "Done: $out"
  echo "Run:  $out/run.sh"
}

package_macos() {
  local out="$REPO_ROOT/dist/macos/RetroStudio"
  local cache="$REPO_ROOT/tools/love/macos"
  local zip_name="love-${LOVE_VERSION}-macos.zip"
  local url="https://github.com/love2d/love/releases/download/${LOVE_VERSION}/${zip_name}"
  local zip_path="$cache/$zip_name"
  local love_out="$REPO_ROOT/dist/RetroStudio.love"
  local extract="$cache/extract"

  echo "== RetroStudio macOS package =="
  rm -rf "$out"
  ensure_dir "$out"
  ensure_dir "$cache"

  build_love
  download "$url" "$zip_path"
  rm -rf "$extract"
  ensure_dir "$extract"
  unzip -q "$zip_path" -d "$extract"

  local love_app
  love_app="$(find "$extract" -maxdepth 3 -name 'love.app' -type d | head -n1)"
  if [[ -z "$love_app" ]]; then
    echo "love.app not found in $zip_path" >&2
    exit 1
  fi

  cp -a "$love_app" "$out/RetroStudio.app"
  # Fuse game into Resources (Love Game Distribution)
  cp -f "$love_out" "$out/RetroStudio.app/Contents/Resources/RetroStudio.love"
  # Also as love.love / drop-in for some Love versions that look for a single .love
  cp -f "$love_out" "$out/RetroStudio.app/Contents/Resources/love.love"

  echo "Staging sidecar trees (next to .app)..."
  mirror_sidecar "$out"
  echo ""
  echo "Done: $out"
  echo "Run:  open $out/RetroStudio.app"
}

case "$TARGET" in
  linux) package_linux ;;
  macos|darwin) package_macos ;;
  *)
    echo "Usage: $0 [linux|macos]" >&2
    exit 1
    ;;
esac
