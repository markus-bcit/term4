FROM python:3.9

WORKDIR /app

COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

COPY app-code/ /app

EXPOSE 5000

# CMD ["python", "app.py"]
# Add a delay before running the main command
CMD ["sh", "-c", "sleep 10 && python app.py"]
