const express = require('express');
const users = require('./users.json');

const app = express();

app.get('/users', (req, res) => {
  res.send(JSON.stringify(users));
  res.end();
});

module.exports = app;
