@echo off
setlocal

:try
git pull origin main

goto :eof

:catch
echo An error occurred.
pause
exit /b 1
