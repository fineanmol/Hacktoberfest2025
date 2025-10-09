import "./App.css";
import useTimer from "./hooks/useTimer";
import { useState } from "react";

function App() {
  const [started, setStarted] = useState(false);
  const [secondsEntered, setSecondsEntered] = useState(0);
  const [minutesEntered, setMinutesEntered] = useState(0);
  const [hoursEntered, setHoursEntered] = useState(0);

  const { secondsLeft } = useTimer(
    hoursEntered,
    minutesEntered,
    secondsEntered,
    started,
    setStarted
  );

  const handleStart = () => setStarted(true);

  const handleReset = () => {
    setStarted(false);
    setHoursEntered(0);
    setMinutesEntered(0);
    setSecondsEntered(0);
  };

  const handleUserInput = (e, type) => {
    let valueEntered = Number(e.target.value);
    if (type === "seconds") setSecondsEntered(valueEntered);
    else if (type === "minutes") setMinutesEntered(valueEntered);
    else if (type === "hours") setHoursEntered(valueEntered);
  };
console.log(secondsLeft)
  return (
    <div className="App">
      {started ? (
        <div>
          <div  className = "div1">
            <p className="text">Hours Left: {Math.floor(secondsLeft / 3600)}</p>
            <p className="text">Minutes Left: {Math.floor((secondsLeft % 3600) / 60)}</p>
            <p className="text">Seconds Left: {secondsLeft % 60}</p>
            <button onClick={handleReset}>Reset</button>

          </div>
        </div>
      ) : (
        <div className = "div2">
          <div>
            <label>H:</label>
            <input
              value={hoursEntered}
              type="text"
              onChange={(e) => handleUserInput(e, "hours")}
            />
          </div>
          <div>
            <label>M:</label>
            <input
              value={minutesEntered}
              type="text"
              onChange={(e) => handleUserInput(e, "minutes")}
            />
          </div>
          <div>
            <label>S:</label>
            <input
              value={secondsEntered}
              type="text"
              onChange={(e) => handleUserInput(e, "seconds")}
            />
          </div>
          <button onClick={handleStart}>Start</button>
        </div>
      )}
    </div>
  );
}

export default App;
