import { useState } from "react";
import "./App.css";
import useTimer from "./hooks/useTimer";

function App() {
  const [active, setActive] = useState(false);
  const [paused, setPaused] = useState(false);
  const [completed, setCompleted] = useState(false);

  const { current } = useTimer(10, active, paused, completed);

  const handleStartOrResumeClick = () => {
    setActive(true);
    setPaused(false);
    setCompleted(false); // Reset the "completed" state
  };

  const handlePauseButtonClick = () => {
    setPaused(true);
  };

  const handleStopButtonClick = () => {
    setCompleted(true);
    setActive(false);
    setPaused(false);
  };

  return (
    <>
      <h1>React Timer</h1>
      <div className="card">
        {/* Start/Resume Button */}
        <button
          onClick={handleStartOrResumeClick}
          disabled={active && !paused} // Disabled when running
        >
          {paused ? "Resume" : "Start"}
        </button>

        {/* Pause Button */}
        <button onClick={handlePauseButtonClick} disabled={!active || paused}>
          Pause
        </button>

        {/* Timer Display */}
        <div>Current: {current}</div>

        {/* Stop Button */}
        <button onClick={handleStopButtonClick} disabled={completed}>
          Stop
        </button>
      </div>
    </>
  );
}

export default App;
