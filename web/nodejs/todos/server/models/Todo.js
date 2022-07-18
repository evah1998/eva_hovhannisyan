const { Schema, model } = require('mongoose');

const todoSchema = new Schema({
  title: {
    type: String,
  },
  status: {
    type: Boolean,
    default: false,
  },
  userId: {
    type: Schema.Types.ObjectId,
    ref: 'User',
  },
});

const Todo = model('Todo', todoSchema);

module.exports = Todo;