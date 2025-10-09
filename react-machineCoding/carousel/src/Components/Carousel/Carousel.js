import React from "react";
import { useState } from "react";
import "./Carousel.css";

const Carousel = () => {
  const [activeIndex, setActiveIndex] = useState(0);

  const images = [
    "https://images.pexels.com/photos/417173/pexels-photo-417173.jpeg",
    "https://images.pexels.com/photos/1054218/pexels-photo-1054218.jpeg",
    "https://images.pexels.com/photos/572897/pexels-photo-572897.jpeg",
    "https://images.pexels.com/photos/270756/pexels-photo-270756.jpeg",
  ];

  const handlePrevClick = () => {
    if(activeIndex === 0){
        setActiveIndex((prev) => images.length - 1)
    }else{
        setActiveIndex((prev) => prev - 1)
    }
  }

  const handleNextClick = () => {
    if(activeIndex === images.length -1){
        setActiveIndex((prev) => 0)
    }else{
        setActiveIndex((prev) => prev + 1)
    }
  }

  console.log('activeIndex', activeIndex)

  return (
    <div className="componentContainer">
      <div className="imageContainer">
        <img src={images[activeIndex]} />
        <button onClick={handlePrevClick}>Prev</button>
        <button onClick={handleNextClick}>Next</button>
        <div className="textContainer">
          <span className="text">{`${activeIndex+1} of ${images.length}`}</span>
        </div>
      </div>
    </div>
  );
};

export default Carousel;
