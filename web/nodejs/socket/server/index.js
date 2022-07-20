const express = require('express');
const http = require('http');
const app = express();
const server = http.createServer(app);
const port = 3001;

const socket = require('socket.io');

const io = socket(server, {
  cors: {
    origin: "*",
  }
});

io.on('connection', (socket) => {
  socket.on('roomId', (roomId) => {
    socket.join(roomId);
  });

  socket.on('chat message', (data) => {
    const messageData = {
      message: data.message,
      username: data.username,
    };

    socket.to(data.roomId).emit('send-broadcast-message', messageData);
  });
});

server.listen(port, () => console.log(`Server started on http://localhost:${port}`));
