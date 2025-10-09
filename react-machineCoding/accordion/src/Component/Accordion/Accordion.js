import React, { useState } from "react";
import './Accordion.css';

const Accordion = () => {
    const [clickedAccordion, setClickedAccordion] = useState(null);

    const data = [
        {
            header: "Header 01",
            content: "Content 01",
        },
        {
            header: "Header 02",
            content: "Content 02",
        },
        {
            header: "Header 03",
            content: "Content 03",
        },
        {
            header: "Header 04",
            content: "Content 04",
        },
    ];

    const handleHeaderClick = (index) => {
        // Toggle the accordion when the header is clicked
        setClickedAccordion(clickedAccordion === index ? null : index);
    };

    return (
        <div className="componentContainer">
            {data.map((item, index) => (
                <div key={index} className="accordionContainer">
                    <div
                        className="accordionHeader"
                        onClick={() => handleHeaderClick(index)}
                    >
                        {item.header}
                    </div>
                    {clickedAccordion === index && (
                        <div className="accordionBody">{item.content}</div>
                    )}
                </div>
            ))}
        </div>
    );
};

export default Accordion;
