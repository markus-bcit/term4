@echo off
setlocal

:try
git pull origin main

goto :eof

:catch
echo An error occurred.
pause
ping -n 4 127.0.0.1 >nul
exit /b 1
