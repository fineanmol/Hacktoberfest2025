import React, { useState } from 'react'
import Button from '../../components/Button/Button'
import Modal from '../../components/Modal/Modal'

const Homepage = () => {
    const [displayModal, setDisplayModal] = useState(false)

    const handleCloseClick = () =>{
        setDisplayModal(false)
    }
    const handleOpenClick = () => {
        setDisplayModal(true)
    }
  return (
    <div>
        <h1>Homepage</h1>
        <Button text = {'Show Modal'} handleClick = {handleOpenClick} />
        {displayModal && <Modal handleClick={handleCloseClick} />}
    </div>
  )
}

export default Homepage