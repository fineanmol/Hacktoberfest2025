import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import useThrottle from './hooks/useThrottle'
import './App.css'

function App() {

  const [userInput, setUserInput] = useState('')

  const val = useThrottle(userInput, 5000)
  console.log(val)
  
  const handleChange = (e) => {
    let val = e.target.value
    setUserInput(val)
  }

  return (
    <>
      <div className="card">
        <input 
          type= 'text'
          onChange = {(e) => handleChange(e)}
          placeholder = 'Enter Value'
        />
        <div>Value Entered: {userInput}</div>
        <div>Throttle Entered: {val}</div>
      </div>
    </>
  )
}

export default App
