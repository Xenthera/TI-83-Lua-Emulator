@echo off
setlocal
set ROOT=%~dp0..
set LJ=%ROOT%\tools\luajit\luajit.exe
if not exist "%LJ%" (
  echo Missing %LJ%
  exit /b 1
)
"%LJ%" "%ROOT%\bridge\main.lua" %*
