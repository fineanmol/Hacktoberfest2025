import { useState } from 'react';
import ProgressBar from './components/ProgressBar/ProgressBar';
import './App.css';
import { useEffect } from 'react';

function App() {
  const [progress, setProgress] = useState(0)

  useEffect(() => {

    const interval = setInterval(() => {
      setProgress((prev) => {
        if(prev >= 100){
          clearInterval(interval)
          return 100;
        }
        return prev + 1 
      })
    }, 100)

    return () => {
      clearInterval(interval)
    }
  }, [])
  

  return (
    <div className="App">
      Progress Bar
      <ProgressBar text = {progress} width={progress} />
    </div>
  );
}

export default App;
