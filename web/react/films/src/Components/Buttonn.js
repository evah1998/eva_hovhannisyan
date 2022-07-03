import React from 'react';
import Modal from './Modal';

function Button(props) {
    return (
        <button onClick={props.onClick}> {props.value}</button>
    )
}

export default Button;