@echo off
setlocal
set ROOT=%~dp0..
set LJ=%ROOT%\tools\luajit\luajit.exe
if exist "%LJ%" (
  "%LJ%" "%~dp0export_computercraft_ti92_ws.lua" %*
) else (
  lua "%~dp0export_computercraft_ti92_ws.lua" %*
)
