FROM python:3.9

WORKDIR /app

COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

COPY app-code/ /app

EXPOSE 8081

CMD ["sh", "-c", "sleep 10 && python app.py"]