@echo off
setlocal

:try
git pull origin main

goto :eof

:catch
echo An error occurred.
pause
timeout /t 3 >nul
exit /b 1
