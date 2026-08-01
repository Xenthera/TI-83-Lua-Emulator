@echo off
setlocal
cd /d "%~dp0.."
if exist "%~dp0luajit\luajit.exe" (
  "%~dp0luajit\luajit.exe" "%~dp0export_computercraft_launcher.lua" %*
  exit /b %ERRORLEVEL%
)
where luajit >nul 2>&1 && (
  luajit "%~dp0export_computercraft_launcher.lua" %*
  exit /b %ERRORLEVEL%
)
lua "%~dp0export_computercraft_launcher.lua" %*
exit /b %ERRORLEVEL%
