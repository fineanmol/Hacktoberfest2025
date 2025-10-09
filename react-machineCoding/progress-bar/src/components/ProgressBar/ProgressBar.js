import React from 'react'
import './ProgressBar.css'

const ProgressBar = ({width, text}) => {
  return (
    <div className='progressBar'>
        <div className='progressHolder' style={{width:`${width}%`}}>
            {text}
        </div>
    </div>
  )
}

export default ProgressBar