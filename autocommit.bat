@echo off
setlocal

:try
set /p message=Enter a message:

git pull origin main
git add .
git commit -m "%message% // %DATE% %TIME%"
git push origin main

goto :eof

:catch
echo An error occurred.
pause
ping -n 4 127.0.0.1 >nul
exit /b 1
