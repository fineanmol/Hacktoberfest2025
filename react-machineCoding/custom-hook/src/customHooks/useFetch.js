import { useEffect, useState } from "react";

const useFetch = (url) => {
    const [data, setData] = useState([]);
    const [loading, setLoading] = useState(true);   
  
    useEffect(() => {
      fetch(url)
        .then((response) => response.json())
        .then((result) => {
          setData(result.results);
          setLoading(false); 
        });
    }, []);

    return {data, loading};
}
export default useFetch;
