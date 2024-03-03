const express = require('express');
const { MongoClient } = require('mongodb');
const path = require('path');

const app = express();
const port = 3000;

const uri = 'mongodb://mongodb:27017';
const client = new MongoClient(uri, { useUnifiedTopology: true });

app.use(express.static(path.join(__dirname, 'public')));

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
  res.sendFile(path.join(__dirname, 'public', 'index.html'));
});

app.listen(port, () => {
  console.log(`Node.js app listening at http://localhost:${port}`);
});
