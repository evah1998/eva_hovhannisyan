const express = require('express');
const fs = require('fs');
const todos = require('./todos.json');

const app = express();

app.get('/users/todos/:userId', (req, res) => {
  const userTodos = todos.filter(todo => todo.userId === Number(req.params.userId));
  res.send(JSON.stringify(userTodos));
  res.end();
});

app.post('/user/:userId/create-todo', (req, res) => {
  const userId = Number(req.params.userId);
  const newTodo = {
    id: todos[todos.length - 1].id + 1,
    userId: userId,
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

app.patch('/update-todo-status/:todoId', (req, res) => {
  const todoId = Number(req.params.todoId);

  fs.readFile('todos.json', function (err, data) {
    let json = JSON.parse(data)
    json = json.map((todo) => {
      if (todo.id === todoId) {
        todo.status = !todo.status;
      }

      return todo;
    });

    fs.writeFile('todos.json', JSON.stringify(json), function() {});
  });

  res.end();
});

app.delete('/delete-completed-todos/:userId', (req, res) => {
  const userId = Number(req.params.userId);

  fs.readFile('todos.json', function (err, data) {
    let json = JSON.parse(data)
    json = json.filter((todo) => {
      if (todo.userId === userId && todo.status === true) {
        return false;
      }

      return true;
    });

    fs.writeFile('todos.json', JSON.stringify(json), function() {});
  });

  res.end();
});

module.exports = app;
