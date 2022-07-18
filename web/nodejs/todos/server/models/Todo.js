const { Schema, model } = require('mongoose');

const todoSchema = new Schema({
  id: {
    type: Number,
    required: true,
    unique: true,
  },
  title: {
    type: String,
    required: true,
  },
  status: {
    type: Boolean,
    default: false,
  },
  userId: {
    type: Number,
    ref: 'User',
  },
});

const Todo = model('Todo', todoSchema);

module.exports = Todo;