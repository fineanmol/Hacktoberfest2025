import React from "react";
import { useState } from "react";
import "./Question.css";

const Question = () => {
  const questions = [
    {
      question: "What is the capital of France?",
      options: ["Paris", "London", "Berlin", "Madrid"],
      answer: "Paris",
    },
    {
      question: "What is 2 + 2?",
      options: ["3", "4", "5", "6"],
      answer: "4",
    },
    {
      question: "Which planet is known as the Red Planet?",
      options: ["Earth", "Mars", "Jupiter", "Saturn"],
      answer: "Mars",
    },
    {
      question: "What is the largest ocean on Earth?",
      options: ["Atlantic", "Indian", "Arctic", "Pacific"],
      answer: "Pacific",
    },
    {
      question: "Who wrote 'To be, or not to be'?",
      options: ["Shakespeare", "Hemingway", "Tolkien", "Twain"],
      answer: "Shakespeare",
    },
  ];

  const [activeQuestionIndex, setActiveQuestionIndex] = useState(0);
  const [selectedOptions, setSelectedOptions] = useState(Array(questions.length).fill(""));
  const [currentScore, setCurrentScore] = useState(0);
  const [gameComplete, setGameComplete] = useState(false);

  const handleOptionSelect = (selectedOption) => {
    const newSelectedOptions = [...selectedOptions];
    newSelectedOptions[activeQuestionIndex] = selectedOption;
    setSelectedOptions(newSelectedOptions);
  };

  const handlePrevClick = () => {
    setActiveQuestionIndex(activeQuestionIndex - 1);
 
  };

  const handleNextClick = () => {
    if (selectedOptions[activeQuestionIndex] === questions[activeQuestionIndex].answer) {
      setCurrentScore((prev) => prev + 1);
    }
    setActiveQuestionIndex(activeQuestionIndex + 1);
  };
  
  const handleCompleteClick = () => {
    if (selectedOptions[activeQuestionIndex] === questions[activeQuestionIndex].answer) {
      setCurrentScore((prev) => prev + 1);
    }
    setGameComplete(true);
  };

  const handleGameRestart = () => {
    setGameComplete(false);
    setActiveQuestionIndex(0);
    setCurrentScore(0);
    setSelectedOptions(Array(questions.length).fill(""));
  };

  return (
    <div className="game-holder">
      {gameComplete ? (
        <div>
          <span className="score">Your Score: {currentScore}</span>
          <div className="result-holder">
            {questions.map((question, index) => (
              <div key={index} className="result-question">
                <div><strong>{question.question}</strong></div>
                <div>Your Answer: {selectedOptions[index]}</div>
                <div>Correct Answer: {question.answer}</div>
              </div>
            ))}
          </div>
        </div>
      ) : (
        <>
          <div className="question-holder">
            <strong>Question</strong>
            <br />
            {questions[activeQuestionIndex].question}
          </div>
          <div className="option-holder">
            {questions[activeQuestionIndex].options.map((option) => (
              <div
                key={option}
                className="quiz-options"
                style={{
                  backgroundColor: selectedOptions[activeQuestionIndex] === option ? "grey" : "",
                }}
                onClick={() => handleOptionSelect(option)}
              >
                {option}
              </div>
            ))}
          </div>
        </>
      )}
      <div className="button-holder">
        {!gameComplete && (
          <button onClick={handlePrevClick} disabled={activeQuestionIndex === 0}>
            Prev
          </button>
        )}
        {activeQuestionIndex !== questions.length - 1 && !gameComplete && (
          <button onClick={handleNextClick}>Next</button>
        )}
        {activeQuestionIndex === questions.length - 1 && !gameComplete && (
          <button onClick={handleCompleteClick}>Complete Quiz</button>
        )}
        {gameComplete && <button onClick={handleGameRestart}>Restart</button>}
      </div>
    </div>
  );
};

export default Question;
