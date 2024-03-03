const express = require('express');
const { MongoClient } = require('mongodb');
const path = require('path');
const mysql = require('mysql');
const bodyParser = require('body-parser'); 
const bcrypt = require('bcrypt');

const app = express();
const port = 3000;

const uri = 'mongodb://user:password@mongodb:27017/analyticsDb';
const client = new MongoClient(uri, { useUnifiedTopology: true });

// MySQL database connection configuration
const db = mysql.createConnection({
  host: 'mysql',
  user: 'root',
  password: 'password',
  database: 'db',
  port: 3306
});

// Connect to MySQL database
db.connect((err) => {
  if (err) {
    console.error('Error connecting to MySQL:', err);
    throw err;
  }
  console.log('Connected to MySQL');
});

app.use(express.static(path.join(__dirname, 'public')));
// Use body-parser middleware to parse incoming request bodies
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
const session = require('express-session');

app.use(session({
  secret: 'your_secret_key',
  resave: false,
  saveUninitialized: true
}));


app.get('/data', async (req, res) => {
  try {
    await client.connect();
    const database = client.db('test');
    const collection = database.collection('data');
    const result = await collection.find({}).toArray();
    res.json(result);
  } catch (error) {
    console.error('Error:', error);
    res.status(500).json({ error: 'Internal server error' });
  } finally {
    await client.close();
  }
});

// Route to serve the home page
app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'public', 'login.html'));
});

// Login route
app.post('/login', async (req, res) => {
  const { name, password } = req.body;

  // Query MySQL database to fetch user
  db.query('SELECT * FROM users WHERE name = ?', [name], (err, results) => {
    if (err) {
      console.error('Error querying database:', err);
      res.status(500).send('Internal server error');
      return;
    }

    if (results.length > 0) {
      const user = results[0];
      if (bcrypt.compareSync(password, user.password)) {
        // Passwords match, store user session
        req.session.userId = user.id; // Assuming user.id is the unique identifier for the user
        res.redirect('/dashboard');
      } else {
        // Passwords don't match, redirect to login with error message
        res.redirect('/?error=Invalid credentials');
      }
    } else {
      // User not found, redirect to login with error message
      res.redirect('/?error=User not found');
    }
  });
});

// Middleware to check if the user is logged in
function requireLogin(req, res, next) {
  // Check if the user is authenticated (you can define your authentication logic here)
  if (req.session && req.session.userId) {
    return next(); // User is logged in, proceed to the next middleware
  } else {
    return res.redirect('/'); // User is not logged in, redirect to the login page
  }
}

// Dashboard route with middleware
app.get('/dashboard', requireLogin, (req, res) => {
  res.sendFile(path.join(__dirname, 'public', 'dashboard.html'));
});

app.listen(port, () => {
  console.log(`Node.js app listening at http://localhost:${port}`);
});
