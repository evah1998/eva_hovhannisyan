import { useEffect, useState } from 'react';
import { useParams } from 'react-router-dom';
import { SERVER_URL } from '../constants';

function TodosComponent () {
  const [message, setMessage] = useState('');
  const [todos, setTodos] = useState([]);
  const params = useParams();
  const completedSize = todos.filter((todo) => todo.status).length;

  useEffect(() => {
    fetch(`${SERVER_URL}/users/todos/${params.userId}`)
      .then((response) => response.json())
      .then((data) => setTodos(data));
  }, []);

  const handleChange = event => {
    setMessage(event.target.value);
  }

  const addTodo = () => {
    if (message !== '') {
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
  }

  const changeTodoStatus = (id) => {
    fetch(`${SERVER_URL}/update-todo-status/${id}`, { method: 'PATCH' })
      .then(() => {
        setTodos((prevTodos) => {
          return prevTodos.map((todo) => {
            if (todo.id === id) {
              todo.status = !todo.status;
            }

            return todo;
          });
        });
      })
  }

  const clearTodos = () => {
    fetch(`${SERVER_URL}/delete-completed-todos/${params.userId}`, { method: 'DELETE' })
      .then(() => {
        setTodos(todos.filter((todo) => {
          if (todo.status === true) {
            return false;
          }

          return true;
        }));
      })
  }

  if (todos.length === 0) {
    return <h1>User does not exist</h1>
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
            <input type="checkbox" checked={todo.status} onChange={() => changeTodoStatus(todo.id)} />
            <span>{todo.title} </span>
            <b> status: {todo.status ? 'Done' : 'In progress'}</b>
          </li>
        ))}
      </ul>
      <div>
        <span>{completedSize}/{todos.length} Completed</span>
        <button onClick={clearTodos}>Clear Completed</button>
      </div>
    </div>
  );
}

export default TodosComponent
