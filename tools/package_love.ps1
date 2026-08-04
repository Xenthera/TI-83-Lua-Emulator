# Package Retro Emulator Studio for Windows: fuse Love + stage sidecar trees.
# Usage: powershell -File tools/package_love.ps1
# Output: dist/windows/RetroStudio/

$ErrorActionPreference = "Stop"
$LoveVersion = "11.5"
$LoveZipName = "love-$LoveVersion-win64.zip"
$LoveUrl = "https://github.com/love2d/love/releases/download/$LoveVersion/$LoveZipName"

$RepoRoot = Resolve-Path (Join-Path $PSScriptRoot "..")
$OutDir = Join-Path $RepoRoot "dist\windows\RetroStudio"
$CacheDir = Join-Path $RepoRoot "tools\love\windows"
$LoveZip = Join-Path $CacheDir $LoveZipName
$LoveExtract = Join-Path $CacheDir "love-$LoveVersion-win64"
$Staging = Join-Path $RepoRoot "dist\_love_stage"
$LoveArchive = Join-Path $RepoRoot "dist\RetroStudio.love"

# Repo trees required next to the host (discovery + IDE Tiny-C/ASM toolchain).
$SidecarDirs = @("machines", "cpus", "framework", "ui", "lang", "asm", "stdlib", "projects", "rom")

function Ensure-Dir([string]$Path) {
  if (-not (Test-Path $Path)) {
    New-Item -ItemType Directory -Path $Path | Out-Null
  }
}

function Mirror-Sidecar([string]$Dest) {
  foreach ($name in $SidecarDirs) {
    $src = Join-Path $RepoRoot $name
    $dst = Join-Path $Dest $name
    if (Test-Path $dst) { Remove-Item -Recurse -Force $dst }
    if (Test-Path $src) {
      Write-Host "  copy $name/"
      Copy-Item -Recurse -Force $src $dst
    } else {
      Ensure-Dir $dst
    }
  }
  $saves = Join-Path $Dest "saves"
  Ensure-Dir $saves
  if (-not (Test-Path (Join-Path $saves ".gitkeep"))) {
    Set-Content -Path (Join-Path $saves ".gitkeep") -Value ""
  }
}

Write-Host "== RetroStudio Windows package =="
Write-Host "Repo: $RepoRoot"

# 1) Clean output
if (Test-Path $OutDir) { Remove-Item -Recurse -Force $OutDir }
Ensure-Dir $OutDir
Ensure-Dir $CacheDir
Ensure-Dir (Join-Path $RepoRoot "dist")

# 2) Stage Love frontend (main.lua at archive root) and zip -> .love
if (Test-Path $Staging) { Remove-Item -Recurse -Force $Staging }
Ensure-Dir $Staging
$Frontend = Join-Path $RepoRoot "frontends\love2d"
Copy-Item -Recurse -Force (Join-Path $Frontend "*") $Staging
if (Test-Path $LoveArchive) { Remove-Item -Force $LoveArchive }

# Prefer Compress-Archive (zip); Love needs .zip renamed to .love
$ZipTmp = Join-Path $RepoRoot "dist\RetroStudio.zip"
if (Test-Path $ZipTmp) { Remove-Item -Force $ZipTmp }
Push-Location $Staging
try {
  Compress-Archive -Path * -DestinationPath $ZipTmp -Force
} finally {
  Pop-Location
}
Move-Item -Force $ZipTmp $LoveArchive
Write-Host "Built $LoveArchive"

# 3) Cache / download Love runtime
if (-not (Test-Path $LoveZip)) {
  Write-Host "Downloading $LoveUrl ..."
  Invoke-WebRequest -Uri $LoveUrl -OutFile $LoveZip
}
if (-not (Test-Path (Join-Path $LoveExtract "love.exe"))) {
  if (Test-Path $LoveExtract) { Remove-Item -Recurse -Force $LoveExtract }
  Expand-Archive -Path $LoveZip -DestinationPath $CacheDir -Force
  # Zip may contain a single top folder
  if (-not (Test-Path (Join-Path $LoveExtract "love.exe"))) {
    $found = Get-ChildItem -Path $CacheDir -Recurse -Filter love.exe | Select-Object -First 1
    if ($found) {
      $LoveExtract = $found.DirectoryName
    } else {
      throw "love.exe not found after extracting $LoveZip"
    }
  }
}

# 4) Copy runtime DLLs / licenses, fuse exe
Copy-Item -Force (Join-Path $LoveExtract "*") $OutDir
$LoveExe = Join-Path $OutDir "love.exe"
$Fused = Join-Path $OutDir "RetroStudio.exe"
if (Test-Path $Fused) { Remove-Item -Force $Fused }
cmd /c "copy /b `"$LoveExe`" + `"$LoveArchive`" `"$Fused`" >nul"
if (-not (Test-Path $Fused)) { throw "Failed to fuse RetroStudio.exe" }
Remove-Item -Force $LoveExe
# Drop the unfused love.ico changes if any; keep DLLs
Write-Host "Fused $Fused"

# 5) Mirror sidecar trees next to exe
Write-Host "Staging sidecar trees..."
Mirror-Sidecar $OutDir

# Cleanup staging
if (Test-Path $Staging) { Remove-Item -Recurse -Force $Staging }

Write-Host ""
Write-Host "Done: $OutDir"
Write-Host "Run:  $Fused"
