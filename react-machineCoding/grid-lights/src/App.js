import { useEffect } from "react";
import { useState } from "react";
import "./App.css";

function App() {
  const [clickedTiles, setClickedTiles] = useState([]);
  const [removeTiles, setRemoveTiles] = useState(false);

  const handleClick = (i) => {
    if (i !== 4 && !clickedTiles.includes(i)) {
      setClickedTiles((prev) => {
        let newTileArray = [...prev, i];
        if (newTileArray.length === 8) {
          setRemoveTiles(true);
        }
        return newTileArray;
      });
    }
  };

  useEffect(() => {
    let interval;

    if (removeTiles) {
      interval = setInterval(() => {
        setClickedTiles((prev) => {
          if (prev.length === 0) {
            clearInterval(interval);
            setRemoveTiles(false);
            return prev;
          }
          let newTileArray = prev.slice(0, -1);
          return newTileArray;
        });
      }, 100);
    }
    return () => clearInterval(interval);
  }, [removeTiles]);

  const renderTiles = () => {
    let cells = [];
    for (let i = 0; i < 9; i++) {
      cells.push(
        <div
          key={i}
          className={
            clickedTiles.includes(i) && i !== 4 ? "tile-filled" : "tile"
          }
          onClick={() => handleClick(i)}
        >
          {`${i + 1}`}
        </div>
      );
    }
    return cells;
  };

  return (
    <div className="App">
      <div className="tileHolder">{renderTiles()}</div>
    </div>
  );
}

export default App;
