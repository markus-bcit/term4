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
timeout /t 3 >nul
exit /b 1
