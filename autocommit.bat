
set /p message=Enter a message:

git pull origin main
git add .
git commit -m "%message% // %DATE% %TIME%"
git push origin main
