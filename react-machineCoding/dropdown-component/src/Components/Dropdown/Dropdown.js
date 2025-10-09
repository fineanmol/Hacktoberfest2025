import React, { useState } from "react";
import "./Dropdown.css";

const Dropdown = ({ componentObject }) => {
  const [clickedHeader, setClickedHeader] = useState("");
  const [clickedOption, setClickedOption] = useState("")

  const headerClick = () => {
    console.log("componentObject", componentObject);
    if(clickedHeader === componentObject.title){
        setClickedHeader("")
    }else{
        setClickedHeader(componentObject.title);
    }
  };

  const handleOptionClick = (options) => {
    setClickedOption(options)
    setClickedHeader('')
  }

  const getReturnOptions = (componentObject) => {
    if (clickedHeader === componentObject.title) {
      let options = [];
      {
        componentObject.options.map((option, index) => {
          options.push(<span key = {index} onClick={() => handleOptionClick(option)}>{option}</span>);
        });
      }
      return options;
    } else {
      return null;
    }
  };

  return (
    <div className="componentTile">
      <div className="componentHeader" onClick={headerClick}>
        {componentObject.title}
      </div>
      <div className="componentOption">{getReturnOptions(componentObject)}</div>
    </div>
  );
};

export default Dropdown;
