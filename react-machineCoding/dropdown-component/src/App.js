import './App.css';
import Dropdown from './Components/Dropdown/Dropdown';

function App() {
  
  const data = [
    {
      title: 'Title 01',
      options: [
        'Option 01',
        'Option 02'
      ]
    },
    {
      title: 'Title 02',
      options: [
        'Option 01',
        'Option 02'
      ]
    }
  ]

  return (
    <div className="App">
      {
        data.map((item) => {
          return(<Dropdown componentObject = {item} />)
        })
      }
    </div>
  );
}

export default App;
