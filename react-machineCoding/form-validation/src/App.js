import logo from "./logo.svg";
import "./App.css";
import InputComponent from "./Components/InputComponent/InputComponent";
import { useState } from "react";

function App() {
  const [userInput, setUserInput] = useState({
    firstName: "",
    lastName: "",
    mobile: "",
    password: "",
  });

  const [errors, setErrors] = useState({
    firstName: "",
    lastName: "",
    mobile: "",
    password: "",
  });

  const isValidValue = () => {
    const errorObj = {
      firstName: "",
      lastName: "",
      mobile: "",
      password: "",
    };

    if (userInput.firstName.length < 5) {
      errorObj.firstName = "Please enter a longer value";
    } else {
      errorObj.firstName = "";
    }

    if (userInput.lastName.length < 2) {
      errorObj.lastName = "Please enter a longer value";
    } else {
      errorObj.lastName = "";
    }

    if (userInput.mobile.length !== 10 || isNaN(userInput.mobile)) {
      errorObj.mobile = "Please enter a valid 10-digit mobile number";
    } else {
      errorObj.mobile = "";
    }


    if (userInput.password.length < 8) {
      errorObj.password = "Please enter a password with at least 8 characters";
    } else {
      errorObj.password = "";
    }


    setErrors(errorObj);

    return !Object.values(errorObj).some((error) => error !== "");
  };

  const handleUserInput = (e, type) => {
    let value = e.target.value;
    let userNewInput = { ...userInput, [type]: value };
    setUserInput(userNewInput);
  };

  const handleSubmit = (e) => {
    e.preventDefault();

    let isValid = isValidValue();
    if (isValid) {
      console.log("Form is valid");
    } else {
      console.log("Form has errors");
    }
  };

  return (
    <div className="App">
      <form onSubmit={handleSubmit}>
        <InputComponent
          name="First Name"
          type="text"
          onChange={(e) => handleUserInput(e, "firstName")}
          error={errors.firstName}
        />

        <InputComponent
          name="Last Name"
          type="text"
          onChange={(e) => handleUserInput(e, "lastName")}
          error={errors.lastName}
        />

        <InputComponent
          name="Mobile"
          type="text"
          onChange={(e) => handleUserInput(e, "mobile")}
          error={errors.mobile}
        />

        <InputComponent
          name="Password"
          type="password"
          onChange={(e) => handleUserInput(e, "password")}
          error={errors.password}
        />

        <button type="submit">Submit</button>
      </form>
    </div>
  );
}

export default App;
