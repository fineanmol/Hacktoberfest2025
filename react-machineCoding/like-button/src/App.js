import { useState } from 'react';
import './App.css';
import Button from './Button/Button';

function App() {
  
  const [loading, setLoading] = useState(false)
  const [error, setError] = useState(null)
  const [liked, setLiked] = useState(false)


  const handleClick = async () => {
    setLoading(true)

    try {
      const response = await fetch(
        "https://www.greatfrontend.com/api/questions/like-button",
        {
          method: "POST",
          headers: { "Content-Type": "application/json" },
          body: JSON.stringify({
            action: liked ? "unlike" : "like",
          }),
        },
      );

      if(response.status === 200){
        setLiked(true)
        setError(null);
      }else{
        const res = await response.json();
        setError(res.message);
        setLiked(false)
        return;
      }
    } catch (error) {        
        setLiked(false)
        setError('An unexpected error occured')
    }finally{
      setLoading(false)
    }
  }
  
  return (
    <div className="App">
      <Button onClick = {handleClick} liked = {liked} loading = {loading} error = {error} />
    </div>
  );
}

export default App;
