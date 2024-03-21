@echo off
setlocal

:try
git pull origin main

goto :eof

:catch
echo An error occurred.
pause
set /p message='
exit /b 1
