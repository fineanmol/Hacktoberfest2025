import React from 'react';
import Button from '../Button/Button';
import './Modal.css';

const Modal = ({ handleClick }) => {
  return (
    <div className="modalOverlay">
      <div className="modalBody">
        <div className="modalHeader">
          <span>Header</span>
          <Button text="Close" handleClick={handleClick} className="closeButton" />
        </div>
        <div className="modalContent">
          This is the modal content.
        </div>
      </div>
    </div>
  );
};

export default Modal;
