import { useEffect, useState } from "react";
import io from 'socket.io-client';

const socket = io('http://localhost:3001');

function App() {
  const [message, setMessage] = useState('');
  const [username, setUsername] = useState('');
  const [messages, setMessages] = useState([]);
  const [showLoginPage, setShowLoginPage] = useState(true);
  const [roomId, setRoomId] = useState('');

  useEffect(() => {
    socket.on('send-broadcast-message', (data) => {
      const messageData = {
        message: data.message,
        username: data.username,
      };

      setMessages([messageData, ...messages]);
    })
  }, [messages]);

  const sendMessage = () => {
    const messageData = {
      message,
      username,
      roomId,
    };

    socket.emit('chat message', messageData);
    setMessages([messageData, ...messages]);
    setMessage('');
  };

  const login = () => {
    if (username && roomId) {
      socket.emit('roomId', roomId);
      setShowLoginPage(false);
    }
  };

  return (
    <div>
      {showLoginPage ? (
        <div>
          <input placeholder="Username" value={username} onChange={(event) => setUsername(event.target.value)} />
          <input placeholder="RoomId" value={roomId} onChange={(event) => setRoomId(event.target.value)} />
          <button onClick={login}>Login</button>
        </div>
      ) : (
        <div>
          <h1>RoomId: {roomId}</h1>
          <input placeholder="Message" value={message} onChange={(event) => setMessage(event.target.value)} />
          <button onClick={sendMessage}>Send message</button>
          <ul>
            {messages.map((message, index) => (
              <li key={index}>{message.username}: {message.message}</li>
            ))}
          </ul>
        </div>
      )}
    </div>
  );
}

export default App;
