@echo off
setlocal
cd /d "%~dp0.."
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0package_love.ps1" %*
exit /b %ERRORLEVEL%
