import React, { useState, useEffect } from "react";
import "./Navbar.css";

const Navbar = () => {
  const [clickedItemId, setClickedItemId] = useState(0);
  const [sandwichClicked, setSandwichClicked] = useState(false);
  const [isMobile, setIsMobile] = useState(window.innerWidth < 460);

  const updateIsMobile = () => {
    setIsMobile(window.innerWidth < 460);
  };

  useEffect(() => {
    window.addEventListener("resize", updateIsMobile);
    return () => window.removeEventListener("resize", updateIsMobile);
  }, []);
  console.log("isMobile", isMobile);

  const data = [
    { id: "option01", title: "Option 01" },
    { id: "option02", title: "Option 02" },
    { id: "option03", title: "Option 03" },
    { id: "option04", title: "Option 04" },
    { id: "option05", title: "Option 05" },
  ];

  const handleClick = (clickedId) => {
    setClickedItemId(clickedId);
  };

  const handleSandwichClick = (e) => {
    e.stopPropagation();
    setSandwichClicked(!sandwichClicked);
  };

  const handleOptionClick = (e, clickedId) => {
    e.stopPropagation();
    setClickedItemId(clickedId);
    setSandwichClicked(false);
  };

  const getSandwichOptions = () => {
    let array = [];
    data.map((item) => {
      array.push(
        <div
          key={item.id}
          id={item.id}
          className="sandwichOption"
          style={{backgroundColor: item.id === clickedItemId ? 'lightgrey' : 'whites'}}
          onClick={(e) => handleOptionClick(e, item.id)}
        >
          {item.title}
        </div>
      );
    });
    return array;
  };

  return (
    <div className="navbarContainer">
      <nav>
        {isMobile ? (
          <div
            className="sandwichContainer"
            onClick={(e) => handleSandwichClick(e)}
          >
            <div className="sandwichLayer"></div>
            <div className="sandwichLayer"></div>
            <div className="sandwichLayer"></div>
            <div className="sandwichOptionContainer">
              {sandwichClicked && getSandwichOptions()}
            </div>
          </div>
        ) : (
          data.map((item) => (
            <div
              key={item.id}
              className="navbarOptions"
              id={item.id}
              onClick={() => handleClick(item.id)}
              style={{
                borderBottom:
                  clickedItemId === item.id ? "5px solid black" : "",
              }}
            >
              {item.title}
            </div>
          ))
        )}
      </nav>
    </div>
  );
};

export default Navbar;
