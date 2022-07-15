import { useEffect, useState } from "react"
import { Link } from "react-router-dom";

import { SERVER_URL } from '../constants';

function UsersComponent () {
  const [users, setUsers] = useState([]);

  useEffect(() => {
    fetch(`${SERVER_URL}/users`)
      .then((response) => response.json())
      .then((data) => setUsers(data));
  }, []);

  return (
    <div>
      <ul>
        {users.map((user) => (
          <li key={user.id}>
            <Link to={`/users/${user.id}`}>{user.name} {user.surname}</Link>
          </li>
        ))}
      </ul>
    </div>
  );
}

export default UsersComponent
