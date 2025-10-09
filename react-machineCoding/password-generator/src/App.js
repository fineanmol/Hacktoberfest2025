import { useState } from "react";
import "./App.css";

function App() {
  const [userInput, setUserInput] = useState({
    length: 0,
    specialChar: false,
    uppercase: false,
    lowercase: false,
    numbers: false,
  });

  const [passwordString, setPasswordString] = useState('')
  const [submitClicked, setSubmitClicked] = useState(false)

  const uppercaseArr = [...Array(26)].map((_, i) => String.fromCharCode(65 + i)); // A-Z
  const lowercaseArr = [...Array(26)].map((_, i) => String.fromCharCode(97 + i)); // a-z
  const numbersArr = [...Array(10)].map((_, i) => i.toString()); // 0-9
  const specialCharArr = "@#$%^&*()".split(""); // Special characters
  

  const onSliderChange = (e) => {
    let newUserInput = { ...userInput, ["length"]: e.target.value };
    setSubmitClicked(false)
    setUserInput(newUserInput);
  };

  const onCheckboxChange = (e, type) => {
    let newUserInput = { ...userInput, [type]: e.target.checked };
    setSubmitClicked(false)
    setUserInput(newUserInput);
  };

  const generatePassword = () => {
    let characterPool = [];
    let {length, uppercase, lowercase, numbers, specialChar} = userInput
    if(uppercase) characterPool.push(uppercaseArr)
    if(lowercase) characterPool.push(lowercaseArr)
    if(specialChar) characterPool.push(specialCharArr)
    if(numbers) characterPool.push(numbersArr)

    let characterPoolFlatList = characterPool.flat()
    console.log('characterPoolFlatList', characterPoolFlatList)

    let passwordString = [];
    while (length > 0) {
      passwordString.push(
        characterPoolFlatList[Math.floor(Math.random() * characterPoolFlatList.length)]
      );
      length--;
    }

    setSubmitClicked(true)
    setPasswordString(passwordString)
  };

  return (
    <div className="App">
      Password Generator
      <div className="config-section">
        <div className="config-option">
          <label>Select Length</label>
          <input
            type="range"
            name="length"
            min="1"
            max="20"
            value={userInput.length}
            onChange={(e) => onSliderChange(e)}
          />
        </div>

        <div className="config-option">
          <label>Special Characters</label>
          <input
            name="specialChar"
            type="checkbox"
            onClick={(e) => onCheckboxChange(e, "specialChar")}
          />
        </div>
        <div className="config-option">
          <label>Lowercase</label>
          <input
            name="lowercase"
            type="checkbox"
            onChange={(e) => onCheckboxChange(e, "lowercase")}
          />
        </div>
        <div className="config-option">
          <label>Uppercase</label>
          <input
            name="uppercase"
            type="checkbox"
            onChange={(e) => onCheckboxChange(e, "uppercase")}
          />
        </div>
        <div className="config-option">
          <label>Numbers</label>
          <input
            name="numbers"
            type="checkbox"
            onChange={(e) => onCheckboxChange(e, "numbers")}
          />
        </div>
      </div>
      <button onClick={() => generatePassword()}>Generate Password</button>
      <div className="passwordHolder">{submitClicked && passwordString}</div>
    </div>
  );
}

export default App;
