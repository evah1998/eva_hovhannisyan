import React, { useEffect, useState } from 'react';
import Film,{list} from '../Components/Film';
import '../styles/App.css';
import Button from '../Components/Buttonn';
import Modal from '../Components/Modal';
import OneFilm from './oneFilm';
  
const Films = () => {
  const[searchText,setSearchText] = useState('')
  const[newElement,setNewElement] = useState(list)
  const [elem,setElem] = useState(list)
  const [show, setShow] = useState(false)

  const searchFilm = (e) => {
    setSearchText(e.target.value)
  }

  useEffect(() =>{
    let filtered = !searchText ? newElement : newElement.filter((e) => e.title.toLowerCase().includes(searchText.toLowerCase()));
    setElem(filtered);
  },[searchText])

  const addElem = (newElement) =>{
    setElem([...elem,newElement]);
    list = elem;
  }

  const deleteElem = (index) => {
    setElem(elem.filter((item , i) => index !== i));
  }

  // const goToElem = (index) => {
  //   setElem(elem.filter((item, i) => index == i));
  // }

  return (
    <div>
      <p id="count">Count: {elem.length}</p>
      <input type="text" className="input" placeholder="Search" onChange={searchFilm}/>
      <Button value= "Add" className="show-modal" onClick = {() => setShow(true)}/>
      <Modal title="Add Film" onClose={() => setShow(false)} show={show} addElem = {addElem}/>
      <Film setElem={setElem} value = {elem} deleteItem = {deleteElem}/> 
      {/* <OneFilm setElem={setElem} value = {elem} gotoItem = {goToElem}/> */}
    </div>
  );
};
  
export default Films;