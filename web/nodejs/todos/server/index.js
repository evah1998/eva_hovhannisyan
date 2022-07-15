const express = require('express');
const cors = require('cors');

const todoApi = require('./todoApi');
const userApi = require('./userApi');

const app = express();
const port = 3001;

app.use(cors());
app.use(express.json());
app.use('', todoApi);
app.use('', userApi);

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
