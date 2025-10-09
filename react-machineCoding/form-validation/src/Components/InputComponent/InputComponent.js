import React from 'react'

const InputComponent = ({type, onChange, name, error}) => {
  return (
    <div className = 'input-holder'>
    <label>{name}</label>
    <input type={type} onChange = {onChange}></input>
    {error.length > 0 && <p>{error}</p>}
    </div>
  )
}

export default InputComponent