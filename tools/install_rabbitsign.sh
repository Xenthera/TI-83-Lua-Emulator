#!/usr/bin/env sh
# Build RabbitSign into tools/bin/ for signing TI-83+/84+ Flash Apps (.8xk).
# Upstream: https://github.com/abbrev/rabbitsign (GPLv3)
set -e
ROOT="$(CDPATH= cd -- "$(dirname "$0")/.." && pwd)"
BIN="$ROOT/tools/bin"
SRC="${RABBITSIGN_SRC:-}"
TMP=""

mkdir -p "$BIN"

if [ -z "$SRC" ]; then
  TMP="$(mktemp -d "${TMPDIR:-/tmp}/rabbitsign.XXXXXX")"
  SRC="$TMP/rabbitsign"
  echo "Cloning abbrev/rabbitsign..."
  git clone --depth 1 https://github.com/abbrev/rabbitsign.git "$SRC"
fi

echo "Building rabbitsign in $SRC ..."
(
  cd "$SRC"
  if [ ! -f Makefile ] || [ ! -f config.h ]; then
    ./configure
  fi
  make -C src rabbitsign
)

cp -f "$SRC/src/rabbitsign" "$BIN/rabbitsign"
chmod +x "$BIN/rabbitsign"
if [ -f "$SRC/src/packxxk" ]; then
  cp -f "$SRC/src/packxxk" "$BIN/packxxk"
  chmod +x "$BIN/packxxk"
fi

if [ -n "$TMP" ]; then
  rm -rf "$TMP"
fi

echo "Installed $BIN/rabbitsign"
"$BIN/rabbitsign" --version
echo "App builds will sign with free key 0104 (real TI-83+/84+ compatible)."
