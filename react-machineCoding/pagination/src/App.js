import { useState, useEffect } from "react";
import "./App.css";

function App() {
  const [data, setData] = useState([]);
  const [activeData, setActiveData] = useState([]);
  const [buttonList, setButtonList] = useState([]);
  const [selectedButton, setSelectedButton] = useState(0); // Track active button

  const DATA_TO_DISPLAY = 10;

  useEffect(() => {
    let array = [];
    for (let i = 0; i < 100; i++) {
      array.push(`Data ${i}`);
    }
    let tempArray = array.slice(0, DATA_TO_DISPLAY);
    setActiveData(tempArray);

    let totalNumberOfButtons = array.length / DATA_TO_DISPLAY;
    let buttonArray = [];
    for (let i = 0; i < totalNumberOfButtons; i++) {
      buttonArray.push(i);
    }

    setData(array);
    setButtonList(buttonArray);
  }, []);

  const handleClick = (index) => {
    let tempData = data.slice(
      index * DATA_TO_DISPLAY,
      index * DATA_TO_DISPLAY + DATA_TO_DISPLAY
    );
    setActiveData(tempData);
    setSelectedButton(index); // Update the selected button
  };

  return (
    <div className="data-holder">
      {activeData.map((data, index) => {
        return (
          <div className="data-item" key={index}>
            {data}
          </div>
        );
      })}
      {buttonList.map((item) => {
        return (
          <button
            key={item}
            onClick={() => handleClick(item)}
            className={item === selectedButton ? "button active" : "button"}
          >
            {item + 1}
          </button>
        );
      })}
    </div>
  );
}

export default App;
