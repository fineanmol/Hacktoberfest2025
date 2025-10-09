import React, { useState } from 'react';
import './WorkTile.css';

const WorkTile = ({ title, workList, setWorkList }) => {
  const [isEditing, setIsEditing] = useState(false);
  const [newTitle, setNewTitle] = useState(title);

  const handleDelete = (clickedTitle) => {
    let workListFiltered = workList.filter((item) => item !== clickedTitle);
    setWorkList(workListFiltered);
  };

  const handleEdit = () => {
    setIsEditing(true);
  };

  const handleSave = () => {
    let workListUpdated = workList.map((item) => (item === title ? newTitle : item));
    setWorkList(workListUpdated);
    setIsEditing(false);
  };

  const handleCancel = () => {
    setNewTitle(title);
    setIsEditing(false);
  };

  const handleChange = (event) => {
    setNewTitle(event.target.value);
  };

  return (
    <div className='tile'>
      {isEditing ? (
        <>
          <input
            type='text'
            value={newTitle}
            onChange={handleChange}
            className='tileInput'
          />
          <div className='tileButtonContainer'>
            <button onClick={handleSave} className='tileButton saveButton'>Save</button>
            <button onClick={handleCancel} className='tileButton cancelButton'>Cancel</button>
          </div>
        </>
      ) : (
        <>
          <p className='tileTitle'>{title}</p>
          <div className='tileButtonContainer'>
            <button onClick={handleEdit} className='tileButton editButton'>Edit</button>
            <button onClick={() => handleDelete(title)} className='tileButton deleteButton'>Delete</button>
          </div>
        </>
      )}
    </div>
  );
};

export default WorkTile;
