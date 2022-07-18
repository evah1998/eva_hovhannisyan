const express = require('express');
const fs = require('fs');
const Todo = require('./models/Todo');
const todos = require('./todos.json');

const app = express();

app.get('/users/todos/:userId', async (req, res) => {
  try {
    const userTodos = await Todo.find({ userId: Number(req.params.userId) });
    return res.status(200).json(userTodos);
  } catch (err) {
    return res.status(400).json({ message: 'Bad request' });
  }
});

app.post('/user/:userId/create-todo', async (req, res) => {
  try {
    const allTodos = await Todo.find();
    const newTodo = new Todo({
      id: (allTodos[allTodos.length - 1]?.id + 1) ?? 1,
      userId: req.params.userId,
      title: req.body.title,
    });

    await newTodo.save();

    return res.status(201).json(newTodo);
  } catch (err) {
    return res.status(400).json({ message: 'Something went wrong on todo creating' });
  }
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
