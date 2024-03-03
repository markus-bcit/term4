from flask import Flask, render_template, request, redirect
import mysql.connector
import bcrypt

app = Flask(__name__)

# MySQL configuration
db = mysql.connector.connect(
    # use only if testing locally
    # host="host.docker.internal",
    host="mysql",
    user="root",
    password="password",
    database="db",
    # use only if testing locally
    # port=3307
    port=3306
)
cursor = db.cursor()

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/submit', methods=['POST'])
def submit():
    name = request.form.get('name')
    password = request.form.get('password')

    # Hash the password
    hashed_password = bcrypt.hashpw(password.encode('utf-8'), b'$2b$12$t4thA0b6kLisrfv8Mp8j7.')

    # Insert data into MySQL with hashed password
    cursor.execute("INSERT INTO users (name, password) VALUES (%s, %s)", (name, hashed_password))
    db.commit()

    return redirect('/')

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
