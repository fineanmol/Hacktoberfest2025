import "./App.css";
import { FaStar } from "react-icons/fa";
import { useState } from "react";

function App() {
  const [hoveredIndex, setHoveredIndex] = useState(-1);
  const [clickedIndex, setClickedIndex] = useState(-1);

  const handleHover = (i) => {
    setHoveredIndex(i);
  };

  const handleClick = (i) => {
    setClickedIndex(i);
  };

  const renderStars = () => {
    const stars = [];
    for (let i = 0; i < 5; i++) {
      stars.push(
        <div
          key={i}
          className="starDiv"
          onMouseEnter={() => handleHover(i)}
          onClick={() => handleClick(i)}
        >
          <FaStar
            color={i <= hoveredIndex || i <= clickedIndex ? "yellow" : "lightgrey"}
            size={40}
          />
        </div>
      );
    }
    return stars;
  };

  return (
    <div className="App">
      <div
        className="starContainer"
        onMouseLeave={() => setHoveredIndex(-1)}
      >
        {renderStars()}
      </div>
    </div>
  );
}

export default App;
