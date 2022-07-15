import {useEffect, useState} from 'react';
import { useParams } from 'react-router-dom';
import { SERVER_URL } from '../constants';

function TodosComponent () {
  const [message, setMessage] = useState('');
  const [todos, setTodos] = useState([]);
  const params = useParams();

  useEffect(() => {
    fetch(`${SERVER_URL}/users/todos/${params.userId}`)
      .then((response) => response.json())
      .then((data) => setTodos(data));
  }, []);

  const handleChange = event => {
    setMessage(event.target.value);
  }

  const addTodo = () => {
    fetch(`${SERVER_URL}/user/${params.userId}/create-todo`,
      {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json'
        },
        body: JSON.stringify({ title: message }),
      },
    )
      .then((response) => response.json())
      .then((data) => {
        const newTodo = {
          id: data[data.length - 1].id + 1,
          userId: Number(params.userId),
          title: message,
          status: false,
        };

        setTodos([...todos, newTodo]);
        setMessage('');
      })
    }
    //
    const complitedSize = todos.filter((todo) => todo.status).length

    const clearTodos = () => {
      setTodos(todos.filter((todo) => !todo.status))
    }

  return (
    <div>
      <h1>Todos</h1>
      <div>
        <input onChange={handleChange} value={message} />
        <button onClick={addTodo}>Add</button>
      </div>
      <ul>
        {todos.map((todo) => (
          <li key={todo.id}>
            <input type="checkbox"/>
            <span>{todo.title} </span>
            <b> status: {todo.status ? 'Done' : 'In progress'}</b>
          </li>
        ))}
      </ul>
      <div>
        <span>{complitedSize}/{todos.length} Completed</span>
        <button onClick={clearTodos}>Clear Completed</button>
      </div>
    </div>
  );
}

export default TodosComponent
