@echo off
setlocal
set ROOT=%~dp0..
set LJ=%ROOT%\tools\luajit\luajit.exe
if not exist "%LJ%" set LJ=luajit
set DIST=%ROOT%\dist
set FE=%DIST%\frontends

echo === TI-83+ (in-CC emu) ===
"%LJ%" "%~dp0export_computercraft.lua" %*
if errorlevel 1 exit /b 1

echo.
echo === TI-84+ (in-CC emu) ===
"%LJ%" "%~dp0export_computercraft_ti84.lua" %*
if errorlevel 1 exit /b 1

echo.
echo === TI-89 advanced monitors (in-CC emu) ===
"%LJ%" "%~dp0export_computercraft_ti89.lua" %*
if errorlevel 1 exit /b 1

echo.
echo === TI-92 Plus advanced monitors (in-CC emu) ===
"%LJ%" "%~dp0export_computercraft_ti92.lua" %*
if errorlevel 1 exit /b 1

echo.
echo === Game Boy DMG (in-CC emu) ===
"%LJ%" "%~dp0export_computercraft_gameboy.lua" %*
if errorlevel 1 exit /b 1

echo.
echo === NES (in-CC emu, pixelbox + CC palette) ===
"%LJ%" "%~dp0export_computercraft_nes.lua" %*
if errorlevel 1 exit /b 1

echo.
echo === Game Boy GPU (in-CC emu) ===
"%LJ%" "%~dp0export_computercraft_gameboy_gpu.lua" %*
if errorlevel 1 exit /b 1

echo.
echo === TI-89 GPU (in-CC emu) ===
"%LJ%" "%~dp0export_computercraft_ti89_gpu.lua" %*
if errorlevel 1 exit /b 1

echo.
echo === TI-83+ WebSocket client ===
"%LJ%" "%~dp0export_computercraft_ti83_ws.lua" %*
if errorlevel 1 exit /b 1

echo.
echo === TI-84+ WebSocket client ===
"%LJ%" "%~dp0export_computercraft_ti84_ws.lua" %*
if errorlevel 1 exit /b 1

echo.
echo === TI-89 WebSocket client ===
"%LJ%" "%~dp0export_computercraft_ti89_ws.lua" %*
if errorlevel 1 exit /b 1

echo.
echo === TI-92 Plus WebSocket client ===
"%LJ%" "%~dp0export_computercraft_ti92_ws.lua" %*
if errorlevel 1 exit /b 1

echo.
echo === Game Boy WebSocket client ===
"%LJ%" "%~dp0export_computercraft_gameboy_ws.lua" %*
if errorlevel 1 exit /b 1

echo.
echo === NES WebSocket client ===
"%LJ%" "%~dp0export_computercraft_nes_ws.lua" %*
if errorlevel 1 exit /b 1

echo.
echo === Game Boy GPU WebSocket client ===
"%LJ%" "%~dp0export_computercraft_gameboy_gpu_ws.lua" %*
if errorlevel 1 exit /b 1

echo.
echo === TI-89 GPU WebSocket client ===
"%LJ%" "%~dp0export_computercraft_ti89_gpu_ws.lua" %*
if errorlevel 1 exit /b 1

echo.
echo === Launcher (emu.lua) ===
"%LJ%" "%~dp0export_computercraft_launcher.lua" %*
if errorlevel 1 exit /b 1

echo.
echo === Stage dist\frontends\ for launcher deploy ===
if not exist "%FE%" mkdir "%FE%"
copy /Y "%DIST%\ti83_cc.lua" "%FE%\ti83_cc.lua" >nul
copy /Y "%DIST%\ti84_cc.lua" "%FE%\ti84_cc.lua" >nul
copy /Y "%DIST%\ti89_cc.lua" "%FE%\ti89_cc.lua" >nul
copy /Y "%DIST%\ti92_cc.lua" "%FE%\ti92_cc.lua" >nul
copy /Y "%DIST%\gb_cc.lua" "%FE%\gb_cc.lua" >nul
copy /Y "%DIST%\nes_cc.lua" "%FE%\nes_cc.lua" >nul
copy /Y "%DIST%\nes_cc_ws.lua" "%FE%\nes_cc_ws.lua" >nul
copy /Y "%DIST%\gb_gpu_cc.lua" "%FE%\gb_gpu_cc.lua" >nul
copy /Y "%DIST%\ti89_gpu_cc.lua" "%FE%\ti89_gpu_cc.lua" >nul
copy /Y "%DIST%\ti83_cc_ws.lua" "%FE%\ti83_cc_ws.lua" >nul
copy /Y "%DIST%\ti84_cc_ws.lua" "%FE%\ti84_cc_ws.lua" >nul
copy /Y "%DIST%\ti89_cc_ws.lua" "%FE%\ti89_cc_ws.lua" >nul
copy /Y "%DIST%\ti92_cc_ws.lua" "%FE%\ti92_cc_ws.lua" >nul
copy /Y "%DIST%\gb_cc_ws.lua" "%FE%\gb_cc_ws.lua" >nul
copy /Y "%DIST%\gb_gpu_cc_ws.lua" "%FE%\gb_gpu_cc_ws.lua" >nul
copy /Y "%DIST%\ti89_gpu_cc_ws.lua" "%FE%\ti89_gpu_cc_ws.lua" >nul

echo.
echo Deploy to a CC computer:
echo   emu.lua
echo   frontends\   (contents of dist\frontends\)
echo   ROMs / .gb / .nes carts next to emu.lua
echo.
echo WS bridge examples:
echo   bridge\run.cmd --machine ti84plus --rom rom\ti84p.rom
echo   bridge\run.cmd --machine ti92plus --rom rom\ti92plus.rom
echo   bridge\run.cmd --machine gameboy --rom rom\gb\tetris.gb
echo.
echo NES:
echo   nes_cc --rom mario.nes
echo   bridge\run.cmd --machine nes
echo   nes_cc_ws --url ws://HOST:8765 --rom mario.nes
echo.
echo Then run:  emu
exit /b 0
