import "./App.css";
import { Routes, Route } from "react-router-dom";
import Home from "./Pages/Home";
import About from "./Pages/About";
import { ThemeProvider } from "./Context/ThemeContext";

function App() {
  return (
    <>
      <ThemeProvider>
        <Routes>
          <Route path="/" Component={Home} />
          <Route path="/about" Component={About} />
        </Routes>
      </ThemeProvider>
    </>
  );
}

export default App;
