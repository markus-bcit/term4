from flask import Flask, request, jsonify
from werkzeug.security import generate_password_hash, check_password_hash
import mysql.connector
import jwt
import datetime
import bcrypt


app = Flask(__name__)

# MySQL configuration
db = mysql.connector.connect(
    host="mysql",
    user="root",
    password="password",
    database="db",
    port=3306
)
cursor = db.cursor()

# Secret key for JWT
app.config['SECRET_KEY'] = b'\xc3\xd6_\xb86\xad1GP\xf9@Y\x14\xc5\xfa\xd9|m\x90\x14\x12\xb48)'

@app.route('/signup', methods=['POST'])
def signup():
    username = request.json.get('name')
    password = request.json.get('password')

    # Check if the username already exists in the database
    cursor.execute("SELECT * FROM users WHERE name = %s", (username,))
    existing_user = cursor.fetchone()

    if existing_user:
        return jsonify({'message': 'Username already exists'}), 400

    # Hash the password before storing it in the database
    hashed_password = bcrypt.hashpw(password.encode('utf-8'), bcrypt.gensalt())

    # Insert the new user into the database
    cursor.execute("INSERT INTO users (name, password) VALUES (%s, %s)", (username, hashed_password))
    db.commit()

    return jsonify({'message': 'User registered successfully'}), 201

@app.route('/login', methods=['POST'])
def login():
    username = request.json.get('name')
    password = request.json.get('password')

    # Retrieve user from database
    cursor.execute("SELECT * FROM users WHERE name = %s", (username,))
    user = cursor.fetchone()
    print(user, password, user[2],password.encode('utf-8'), user[2].encode('utf-8'))
    if user and bcrypt.checkpw(password.encode('utf-8'), user[2].encode('utf-8')):  # Assuming password hash is stored in the database
        # Generate JWT token
        token = jwt.encode({'username': username, 'exp': datetime.datetime.utcnow() + datetime.timedelta(minutes=30)}, app.config['SECRET_KEY'])

        return jsonify({'token': token}), 200
    else:
        return jsonify({'message': 'Invalid username or password'}), 401

@app.route('/validate_token', methods=['POST'])
def validate_token():
    token = request.json.get('token')

    try:
        decoded_token = jwt.decode(token, app.config['SECRET_KEY'], algorithms=['HS256'])
        return jsonify({'message': 'Token is valid', 'username': decoded_token['username']}), 200
    except jwt.ExpiredSignatureError:
        return jsonify({'message': 'Token has expired'}), 401
    except jwt.InvalidTokenError:
        return jsonify({'message': 'Invalid token'}), 401

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8000)