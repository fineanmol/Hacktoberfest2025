import "./App.css";
import { useState, useRef } from "react";
import { useEffect } from "react";

function App() {
  const otpArray = [0, 1, 2, 3];

  const [activeIndex, setActiveIndex] = useState(0);
  const [userInput, setUserInput] = useState(["", "", "", ""]);
  const [displayOTP, setDisplayOTP] = useState(false);
  const inputs = useRef([]);

  const handleInputChange = (e, index) => {
    if (isNaN(Number(e.target.value))) {
      return;
    } else if (activeIndex < otpArray.length) {
      const newUserInput = [...userInput];
      newUserInput[index] = e.target.value;
      setUserInput(newUserInput);
      setActiveIndex((prev) => prev + 1);
    }
  };
  console.log("userInput", userInput);

  useEffect(() => {
    if (activeIndex < otpArray.length) {
      inputs.current[activeIndex].focus();
    }
  }, [activeIndex]);

  const handleOTPSubmit = () => {
    setDisplayOTP(true);
  };

  return (
    <div className="App">
      <div className="otp-holder">
        {otpArray.map((item) => {
          return (
            <div className="otp-digit-holder">
              <input
                style={{ border: activeIndex === item ? "5px solid pink" : "" }}
                disabled={activeIndex !== item}
                className={`digit digit-${item}`}
                type="text"
                onChange={(e) => handleInputChange(e, item)}
                ref={(el) => (inputs.current[item] = el)}
                value={userInput[item]}
              />
            </div>
          );
        })}
      </div>
      <button onClick={handleOTPSubmit}> Submit </button>
      {displayOTP && <div>{`You Entered: ${userInput.join("")}`}</div>}
    </div>
  );
}

export default App;
