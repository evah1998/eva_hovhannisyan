import './App.css';
import UsersComponent from './pages/UsersComponent';
import TodosComponent from './pages/TodosComponent';
import { BrowserRouter, Link, Route, Routes } from 'react-router-dom';

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<UsersComponent/>}/>
        <Route path="/user/:userId" element={<TodosComponent/>}/>
      </Routes>
    </BrowserRouter>
  );
}

export default App;
