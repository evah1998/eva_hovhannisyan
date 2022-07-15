import UsersComponent from './pages/UsersComponent';
import TodosComponent from './pages/TodosComponent';
import { BrowserRouter, Route, Routes, Navigate} from 'react-router-dom';
import './App.css'

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/users" element={<UsersComponent/>}/>
        <Route path="/users/:userId" element={<TodosComponent/>}/>
        <Route path="*" element={<Navigate to="/users"/>}/>
      </Routes>
    </BrowserRouter>
  );
}

export default App;
