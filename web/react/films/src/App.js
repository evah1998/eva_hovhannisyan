import React, { useEffect, useState } from 'react';
import Navbar from './Components/Navbar/index';
import { BrowserRouter as Router, Routes, Route}
    from 'react-router-dom';
import Home from './pages';
import Films from './pages/films';
import Film from './pages/oneFilm';

export const App = () =>{
  return (
    <div className="App">
      <Router>
        <Navbar />
        <Routes>
          <Route exact path='/home' element={<Home />} />
          <Route exact path='/' element={<Home/>} />
          <Route path='/films' element={<Films/>} />
          <Route path='/film' element={<Film/>} />
        </Routes>
      </Router>
    </div>
  )
}

export default App;