import React, { useState } from 'react';
import { useEffect } from 'react';
import useDebounce from "../src/hooks/useDebounce"

const App = () => {
    const [inputValue, setInputValue] = useState('');
    const debouncedValue = useDebounce(inputValue, 5000); 

    // throttle and debounce code

    function tempDebounce(func, delay) {
        let handler;
        return function (...args) {
          if (handler) clearTimeout(handler)
          handler = setTimeout(() => {
            func.apply(this, args)
          }, delay);
        }
      }
    
      const tempDebounceLog = tempDebounce((text) => {
        console.log('tempDebounceLog', text)
      }, 4000)
    
    
      function tempThrottle(func, delay){
        let prevCall = 0
        return function(...args){
          const now = new Date()
    
          if(now - prevCall > delay){
            prevCall = now
            func.apply(this, args)
          }
        }
      }
    
      const tempThrottleLog = tempThrottle((text) => {
        console.log('tempThrottleLog', text)
      }, 4000)


      const handleInputChange = (e) => {
        setInputValue(e.target.value)  
        tempDebounceLog(e.target.value)
        tempThrottleLog(e.target.value)
      }

    return (
      <>
        <input
            type="text"
            value={inputValue}
            onChange={(e) => handleInputChange(e)}
            placeholder="Type to search..."
        />
        <div>Debounced Value: {debouncedValue}</div>
        </>
    );
};

export default App;
