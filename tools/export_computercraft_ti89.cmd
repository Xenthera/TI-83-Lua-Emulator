@echo off
REM Windows launcher — avoids hanging on .lua file-association Invoke-Item.
setlocal
cd /d "%~dp0.."
if exist "%~dp0luajit\luajit.exe" (
  "%~dp0luajit\luajit.exe" "%~dp0export_computercraft_ti89.lua" %*
  exit /b %ERRORLEVEL%
)
where luajit >nul 2>&1 && (
  luajit "%~dp0export_computercraft_ti89.lua" %*
  exit /b %ERRORLEVEL%
)
lua "%~dp0export_computercraft_ti89.lua" %*
exit /b %ERRORLEVEL%
