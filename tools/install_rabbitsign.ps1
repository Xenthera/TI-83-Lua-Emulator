# Build RabbitSign into tools/bin/rabbitsign.exe for signing TI-83+/84+ Flash Apps.
# Upstream: https://github.com/abbrev/rabbitsign (GPLv3)
#
# Requires: git, gcc (MinGW), make, and Git Bash (for ./configure).
#   scoop install mingw make git
#   (Git for Windows provides bash)
#
# Usage (from repo root):
#   powershell -ExecutionPolicy Bypass -File tools\install_rabbitsign.ps1

$ErrorActionPreference = "Stop"

$Root = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path
$Bin = Join-Path $Root "tools\bin"
New-Item -ItemType Directory -Force -Path $Bin | Out-Null

function Find-GitBash {
  $candidates = @(
    (Join-Path ${env:ProgramFiles} "Git\bin\bash.exe"),
    (Join-Path ${env:ProgramFiles(x86)} "Git\bin\bash.exe")
  )
  if ($env:LOCALAPPDATA) {
    $candidates += (Join-Path $env:LOCALAPPDATA "Programs\Git\bin\bash.exe")
  }
  $cmd = Get-Command bash.exe -ErrorAction SilentlyContinue
  if ($cmd) { $candidates += $cmd.Source }
  foreach ($p in $candidates) {
    if ($p -and (Test-Path -LiteralPath $p)) { return $p }
  }
  return $null
}

foreach ($tool in @("git", "gcc", "make")) {
  if (-not (Get-Command $tool -ErrorAction SilentlyContinue)) {
    throw "Missing '$tool' on PATH. Install MinGW + make + git (e.g. scoop install mingw make git)."
  }
}

$Bash = Find-GitBash
if (-not $Bash) {
  throw "Git Bash not found (needed for ./configure). Install Git for Windows."
}

$Src = $env:RABBITSIGN_SRC
$Tmp = $null
if (-not $Src) {
  $Tmp = Join-Path $env:TEMP ("rabbitsign." + [guid]::NewGuid().ToString("N"))
  $Src = Join-Path $Tmp "rabbitsign"
  Write-Host "Cloning abbrev/rabbitsign..."
  git clone --depth 1 https://github.com/abbrev/rabbitsign.git $Src
  if ($LASTEXITCODE -ne 0) { throw "git clone failed" }
}

$SrcUnix = ($Src -replace "\\", "/")
Write-Host "Building rabbitsign in $Src ..."
& $Bash -lc @"
set -e
cd '$SrcUnix'
if [ ! -f Makefile ] || [ ! -f config.h ]; then
  ./configure
fi
make -C src rabbitsign.exe
"@
if ($LASTEXITCODE -ne 0) { throw "build failed" }

$Built = Join-Path $Src "src\rabbitsign.exe"
if (-not (Test-Path -LiteralPath $Built)) {
  throw "build did not produce src\rabbitsign.exe"
}

$Dest = Join-Path $Bin "rabbitsign.exe"
Copy-Item -Force $Built $Dest

$Pack = Join-Path $Src "src\packxxk.exe"
if (Test-Path -LiteralPath $Pack) {
  Copy-Item -Force $Pack (Join-Path $Bin "packxxk.exe")
}

if ($Tmp) {
  Remove-Item -Recurse -Force $Tmp -ErrorAction SilentlyContinue
}

Write-Host "Installed $Dest"
& $Dest --version
if ($LASTEXITCODE -ne 0) { throw "rabbitsign.exe failed to run" }
Write-Host "App builds will sign with free key 0104 (real TI-83+/84+ compatible)."
