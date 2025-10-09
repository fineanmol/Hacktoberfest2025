import React from "react";
import { Link } from "react-router-dom";
import { useTheme } from "../Context/ThemeContext";

const Home = () => {
  const { theme, toggleTheme } = useTheme();

  return (
    <div
      style={{
        backgroundColor: theme === "dark" ? "black" : "white",
        width: "100vw",
        height: "100vh",
      }}
    >
      <p style={{ color: theme === "dark" ? "white" : "black" }}>Home</p>
      <div>
        <Link to="about">
          <p style={{ color: theme === "dark" ? "white" : "black" }}>
            Visit The About Page
          </p>
        </Link>
        <button onClick={toggleTheme}>Switch Mode</button>
      </div>
    </div>
  );
};

export default Home;
