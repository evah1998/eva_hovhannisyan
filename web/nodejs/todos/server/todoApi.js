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
    const id = allTodos.length ? allTodos[allTodos.length - 1]?.id + 1 : 1;
    const newTodo = new Todo({
      id: id,
      userId: req.params.userId,
      title: req.body.title,
    });

    await newTodo.save();

    return res.status(201).json(newTodo);
  } catch (err) {
    return res.status(400).json({ message: 'Something went wrong on todo creating' });
  }
});

app.patch('/update-todo-status/:todoId', async (req, res) => {
  try {
    const todo = await Todo.findOne({id: Number(req.params.todoId)});
    const updatedStatus = Todo.findOneAndUpdate(
      {id: Number(req.params.todoId)},
      {$set: {status: !todo.status}}, null, (err, doc) => {
        if (err&& !doc) {
          throw('Error')
        }
      });
    return res.status(200).json(updatedStatus);
  } catch {
    return res.status(400).json({ message: 'Status not updated'});
  }
});

app.delete('/delete-completed-todos/:userId', async (req, res) => {
  try {
    const deleteTodos = await Todo.deleteMany({userId: Number(req.params.userId), status: true});
    return res.status(200).json(deleteTodos);
  } catch (err) {
    return res.status(400).json({ message: "Can't delete todos"});
  }
});

module.exports = app;
