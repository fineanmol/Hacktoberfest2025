import React from 'react';
import './Card.css';

const Card = ({ name, phone, email, address, company }) => {
  return (
    <div className="user-card">
        <div className="description">{`Name: ${name}`}</div>
        <div className="description">{`Phone: ${phone}`}</div>
        <div className="description">{`Email: ${email}`}</div>
        <div className="description">{`Address: ${address}`}</div>
        <div className="description">{`Company: ${company}`}</div>
    </div>
  );
};

export default Card;
