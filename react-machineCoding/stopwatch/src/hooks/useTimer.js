import { useEffect, useState } from "react";

const useTimer = (initialVal, active, paused, completed) => {
  const [current, setCurrent] = useState(initialVal);

  useEffect(() => {
    let handler;

    if (completed) {
    // Reset when completed
      setCurrent(initialVal); 
    } else if (active && !paused) {
      handler = setInterval(() => {
         // Increment timer
        setCurrent((prev) => prev + 1);
      }, 1000);
    }

    // Clean up interval
    return () => clearInterval(handler); 
  }, [active, paused, completed, initialVal]);

  return { current, setCurrent };
};

export default useTimer;
