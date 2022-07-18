const { Schema, model } = require('mongoose');

const userSchema = new Schema({
  id: {
    type: Number,
    required: true,
    unique: true,
  },
  name: {
    type: String,
    required: true,
  },
  surname: {
    type: String,
    required: true,
  },
});

const User = model('User', userSchema);

module.exports = User;
