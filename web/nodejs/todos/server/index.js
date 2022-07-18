const express = require('express');
const cors = require('cors');
const mongoose = require('mongoose');

const todoApi = require('./todoApi');
const userApi = require('./userApi');
const User = require('./models/User');

async function main() {
  try {
    await mongoose.connect('mongodb://localhost:27017/todos')
    console.log('Database connected');
  } catch (err) {
    console.log(err);
  }
}

main();

async function insertUsers() {
  const createUser1 = new User({id: 1, name: "John", surname: "Smith"});
  await createUser1.save();
  const createUser2 = new User({id: 2, name: "James", surname: "Smith"});
  await createUser2.save();
  const createUser3 = new User({id: 3, name: "Robert", surname: "Smith"});
  await createUser3.save();
  const createUser4 = new User({id: 4, name: "Jennifer", surname: "Smith"});
  await createUser4.save();
}

// insertUsers();

const app = express();
const port = 3001;

app.use(cors());
app.use(express.json());
app.use('', todoApi);
app.use('', userApi);

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
