from flask import Flask, render_template, request, redirect, session
import mysql.connector
import bcrypt
import requests

app = Flask(__name__)
app.debug = True

# MySQL configuration
db = mysql.connector.connect(
    host="mysql",
    user="root",
    password="password",
    database="db",
    port=3306
)
cursor = db.cursor()
AUTH_SERVICE_URL_SIGNUP = 'http://172.20.0.4:8000/signup'
AUTH_SERVICE_URL_LOGIN = 'http://172.20.0.4:8000/login'
app.secret_key = 'your_secret_key'



@app.route('/')
def loginpage():
    return render_template('login.html')

@app.route('/login')
def loginpage2():
    return render_template('login.html')

@app.route('/signup')
def signuppage():
    return render_template('signup.html')


@app.route('/signupreq', methods=['POST'])
def signup():
    name = request.form.get('username')
    password = request.form.get('password')

    # Send login credentials to the authentication service
    response = requests.post(AUTH_SERVICE_URL_SIGNUP, json={'name': name, 'password': password})

    if response.status_code == 200:
        # Redirect to the dashboard or any other appropriate page
        return redirect('/login')
    else:
        # Handle invalid credentials or other errors
        return render_template('signup.html', error='Invalid credentials')

@app.route('/loginreq', methods=['POST'])
def login():
    name = request.form.get('name')
    password = request.form.get('password')

    # Send login credentials to the authentication service
    response = requests.post(AUTH_SERVICE_URL_LOGIN, json={'name': name, 'password': password})

    if response.status_code == 200:
        # If authentication is successful, the auth service will return a token
        token = response.json().get('token')

        # Store the token in the session or cookies for subsequent requests
        session['token'] = token

        # Redirect to the dashboard or any other appropriate page
        
        return redirect('/dashboard')
    else:
        # Handle invalid credentials or other errors
        return render_template('login.html', error='Invalid credentials')


@app.route('/logout', methods=['GET', 'POST'])
def logout():
    # Clear the session data to log the user out
    session.clear()
    # Redirect the user to the login page or any other appropriate page
    return redirect('/')


@app.route('/dashboard')
def dashboard():
    # Check if the user is logged in (token exists in session)
    if 'token' in session:
        return render_template('dashboard.html')
    else:
        # Redirect to the login page if the user is not logged in
        return redirect('/')

# Flask route to handle form submission and insert data into MySQL database
@app.route('/submit_data', methods=['POST'])
def submit_data():
    if request.method == 'POST':
        # Retrieve form data
        data1 = request.form['data1']
        data2 = request.form['data2']
        data3 = request.form['data3']


        # Insert data into the MySQL database
        cursor.execute("INSERT INTO data_entries (data1, data2, data3) VALUES (%s, %s, %s)", (data1, data2, data3))
        db.commit()

        # Optionally, you can redirect the user to another page after data submission
        return redirect('/dashboard')
    else:
        # Handle invalid request method
        return "Method Not Allowed", 405



if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5005)
    
