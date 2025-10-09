import "./App.css";
import { useEffect, useState } from "react";
import useFetch from "./customHooks/useFetch";

function App() {
  const {data, loading} = useFetch('https://randomuser.me/api/?results=5')

  return (
    <div className="App">
      {loading ? ( 
        <div>Loading...</div>
      ) : (
        data.map((item) => {
          return (
            <div key={item.login.uuid} className="user-card">
              <div className="left-side">
                <img src={item.picture.large} alt={`${item.name.first} ${item.name.last}`} />
              </div>
              <div className="right-side">
                <div className="description">{`Name: ${item.name.title} ${item.name.first} ${item.name.last}`}</div>
                <div className="description">{`Phone: ${item.cell}`}</div>
                <div className="description">{`Email: ${item.email}`}</div>
                <div className="description">{`Address: ${item.location.timezone.description}`}</div>
              </div>
            </div>
          );
        })
      )}
    </div>
  );
}

export default App;
