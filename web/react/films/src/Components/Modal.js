import React, {useState} from 'react';
import '../styles/Modal.css';

import img7 from '../img3.jpg';

const Modal = (props) => {
    const[title,setTitle] = useState('')
    const[desc,setDesc] = useState('')

    if (!props.show) {
        return null
    }
    
    const addElement = () => {
        const newFilm = {
            title:title,
            img:img7,
            description:desc
        }  

       props.addElem(newFilm)
    }

    return (
        <div className='modal-container' onClick={props.onClose}>
            <div className='modal-content' onClick={e => e.stopPropagation()}>
                <div className='modal-header'>
                    <h4 className='modal-title'>{props.title}</h4>
                    <button onClick={props.onClose} className='close-modal'>x</button>
                </div>
                <div className='modal-body'>
                    <div className='form-container'>
                        <input type="text" className="input" placeholder="Name"  onChange={(e)=>setTitle(e.target.value)}/>
                        <input type="text" className="input" placeholder="Description"  onChange={(e)=>setDesc(e.target.value)}/>
                        <button className="button-add" onClick = {addElement}>Add</button>
                    </div>
                </div>
            </div>
        </div>
    )
}

export default Modal