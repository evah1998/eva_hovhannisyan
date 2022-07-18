const express = require('express');
const User = require('./models/User');

const app = express();

app.get('/users', async (req, res) => {
  const allUsers = await User.find();

  return res.json(allUsers);
});

module.exports = app;
