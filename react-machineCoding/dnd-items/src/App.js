import React, { useState } from "react";
import "./App.css";

const App = () => {
  const data = [
    { id: 1, text: "Div 01" },
    { id: 2, text: "Div 02" },
    { id: 3, text: "Div 03" },
    { id: 4, text: "Div 04" },
    { id: 5, text: "Div 05" },
  ];

  const [items, setItems] = useState(data);
  const [draggedItem, setDraggedItem] = useState(null);

  const handleDrag = (e, index) => {
    e.dataTransfer.effectAllowed = "move";
    setDraggedItem(index);
  };

  const handleDragEnd = () => {
    setDraggedItem(null);
  };
  const handleDragOver = (e) => {
    e.preventDefault();
  };

  const handleDrop = (e, index) => {
    e.preventDefault();
    const draggedOverItem = items[index];
    if (draggedItem === index) return;

    let newItems = items.filter((item, idx) => idx !== draggedItem);
    newItems.splice(index, 0, items[draggedItem]);

    setItems(newItems);
  };
  console.log("items", items);

  return (
    <div className="holder">
      {items.map((item, index) => {
        return (
          <div
            id={item.id}
            className="drag-item"
            draggable
            onDragStart={(e) => handleDrag(e, index)}
            onDragEnd={handleDragEnd}
            onDragOver={(e) => handleDragOver(e, index)}
            onDrop={(e) => handleDrop(e, index)}
          >
            {item.text}
          </div>
        );
      })}
    </div>
  );
};

export default App;
