import { useState, useEffect } from "react";

const useTimer = (hoursEntered, minutesEntered, secondsEntered, started, setStarted) => {
  let totalSecondsInput =
    Number(secondsEntered) +
    Number(minutesEntered * 60) +
    Number(hoursEntered * 3600);
  console.log("totalSecondsInput", totalSecondsInput);
  console.log('started', started)
  const [secondsLeft, setSecondsLeft] = useState(totalSecondsInput);

  useEffect(() => {
    if (!started) return;

    setSecondsLeft(totalSecondsInput);
    let interval = setInterval(() => {
      setSecondsLeft((prev) => {
        if (prev === 1) {
          clearInterval(interval);
          setStarted(false)
          return 0;
        }
        return prev - 1;
      });
    }, 1000);
    return () => clearInterval(interval);
  }, [totalSecondsInput, started]);

  return {
    secondsLeft,
  };
};

export default useTimer;