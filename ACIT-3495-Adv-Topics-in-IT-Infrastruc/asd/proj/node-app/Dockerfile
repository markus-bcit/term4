FROM node:latest

WORKDIR /app

COPY package.json package-lock.json ./
RUN npm install
RUN npm install mysql
RUN npm install express-session
RUN npm install body-parser
RUN npm install bcrypt

COPY . .

EXPOSE 3000

CMD ["sh", "-c", "sleep 10 && node index.js"]