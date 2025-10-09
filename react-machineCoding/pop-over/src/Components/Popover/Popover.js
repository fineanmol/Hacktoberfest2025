import React from "react";
import { useState } from "react";
import "./Popover.css";

const Popover = () => {
  const [showBody, setShowBody] = useState(false);

  const handleHeaderClick = () => {
    setShowBody(!showBody);
  };

  return (
    <div className="componentContainer">
      <button onClick={handleHeaderClick}>Click Here</button>
      {showBody ? (
        <div className="popoverContainer">
          <>
          <div className="triangle"></div>
            <div className="popoverHeader">Header</div>
            <div className="popoverBody">The content is added here</div>
          </>
        </div>
      ) : null}
    </div>
  );
};

export default Popover;
