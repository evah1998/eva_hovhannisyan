const express = require('express');
const cors = require('cors');
const fs = require('fs');

const users = require('./users.json');
const todos = require('./todos.json');

const app = express();
const port = 3001;

app.use(cors());
app.use(express.json())

app.get('/users', (req, res) => {
  res.send(JSON.stringify(users));
  res.end();
});

app.get('/users/todos/:userId', (req, res) => {
  const userTodos = todos.filter(todo => todo.userId === Number(req.params.userId));
  res.send(JSON.stringify(userTodos));
  res.end();
});

app.post('/user/:userId/create-todo', (req, res) => {
  const newTodo = {
    id: todos[todos.length - 1].id + 1,
    userId: Number(req.params.userId),
    title: req.body.title,
    status: false,
  };

  fs.readFile('todos.json', function (err, data) {
    const json = JSON.parse(data)
    json.push(newTodo);
    fs.writeFile('todos.json', JSON.stringify(json), function() {});
  });

  res.send(JSON.stringify(todos));
  res.end();
});

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
