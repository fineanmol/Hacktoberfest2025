import React from 'react'

const Button = ({text, handleClick}) => {
  return (
    <button onClick = {handleClick}>
        {text}
    </button>
  )
}

export default Button