import "./App.css";
import { useEffect } from "react";
import { useState } from "react";

function App() {

  const [dataFetched, setDataFetched] = useState(false)
  const [response, setResponse] = useState(null)

  const getWeatherData = (latitude,longitude) => {
    console.log('currentLocation.latitude',latitude, longitude)
    fetch(
      `https://api.openweathermap.org/data/2.5/weather?lat=${latitude}&lon=${longitude}&appid=bf909b4a90c47e810fc156dc73c0ed75`
    )
      .then((response) => response.json())
      .then((result) => {
        console.log("result", result);
        setResponse(result)
        setDataFetched(true)
      });
  };

  const showPosition = (pos) => {
    console.log('poss', pos)
    getWeatherData(pos.coords.latitude, pos.coords.longitude)
  }

  useEffect(() => {
    if(navigator.geolocation){
      let returnPosition = navigator.geolocation.getCurrentPosition(showPosition)
    }
  }, []);


  return (
    <div>
      {dataFetched ? 
        <>
          <div className="city-name">{response.name}</div>
          <div className="description">{`Current Temperature: ${response.main.temp} F`}</div> 
          <div className="description">{`Description: ${response.weather[0].description}`}</div> 
          <div className="description">{`Max Temperature: ${response.main.temp_max} F`}</div> 
          <div className="description">{`Min Temperature: ${response.main.temp_min} F`}</div> 
          <div className="description">{`Humidity: ${response.main.humidity} F`}</div> 
        </>
        : 
        <div>Loading</div>
        }
      </div>
  )
}

export default App;
