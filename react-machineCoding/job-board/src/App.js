import './App.css';
import { useEffect, useState } from 'react';
import Card from './Components/Card/Card';

function App() {
  const [candidates, setCandidates] = useState([]);

  useEffect(() => {
    fetch('https://jsonplaceholder.typicode.com/users') // Updated API endpoint
      .then((response) => response.json())
      .then((result) => {
        setCandidates(result); // Use result directly as the API returns an array
      });
  }, []);

  return (
    <div className="App">
      {candidates.length > 0 ? (
        candidates.map((item) => (
          <Card
            key={item.id} // Add a unique key
            name={item.name}
            phone={item.phone}
            email={item.email}
            address={`${item.address.street}, ${item.address.city}, ${item.address.zipcode}`} // Combine address fields
            company={item.company.name} // Add company name
          />
        ))
      ) : (
        <div>Loading...</div>
      )}
    </div>
  );
}

export default App;
