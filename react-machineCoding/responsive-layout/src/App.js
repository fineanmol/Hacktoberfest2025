import logo from "./logo.svg";
import "./App.css";

function App() {
  return (
    <div className="App">
      <header>Header</header>
      <div className="mid-section">
        <div className="left-mid-section">
          <aside>Aside</aside>  
        </div>
        <div className="right-mid-section">
          <div className="right-mid-section-top">
            <div className = 'content-1'>Content-1</div>
          </div>
          <div className="right-mid-section-bottom">
            <div className = 'content-2'>Content-2</div>
            <div className = 'content-3'>Content-3</div>
          </div>
        </div>
      </div>
      <footer>Footer</footer>
    </div>
  );
}

export default App;
