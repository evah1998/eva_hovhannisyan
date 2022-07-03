import React, { useState } from 'react';
import '../styles/Film.css';
import Button from './Buttonn';

import img from '../img.jpg'
import img2 from '../img2.jpg'
import img3 from '../img3.jpg'
import img4 from '../img4.jpg'
import img5 from '../img5.jpg'
import img6 from '../img6.jpg'

export const list = [{
    title: 'Polis',
    img: img,
    description: 'description1'
},{
    title: 'Horns',
    img: img2,
    description: 'description2'
},{
    title: 'Black Panther',
    img: img3,
    description: 'description3'
},{
    title: 'Gods of Egypt',
    img: img4,
    description: 'description4'
},{
    title: 'Freedom',
    img: img5,
    description: 'description5'
},{
    title: 'Merrick',
    img: img6,
    description: 'description6'
}];

const Film = (props) => {

    const[delItem, setDelItem] = useState(list)
    
    const listItems = props.value.map((e, index) =>
        <li>
            <h1>{e.title}</h1>
            <img src={e.img}/>
            <p>{e.description}</p>
            <Button value = "Delete" onClick = {() => props.deleteItem(index)} />
        </li>
    );
    return(
        <div className="film-container">
            <ul className="list-group">{listItems}</ul>
        </div>
    )
}

export default Film;