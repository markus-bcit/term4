@echo off
set /p message=

git pull origin main
git add .
git commit -m "%message% // %DATE% %TIME%"
git push origin main
set /p message=