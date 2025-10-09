import { useEffect, useRef, useState } from "react"

const useDebounce = (value, interval) => {
    const [debouncedValue, setDebouncedValue] = useState(value)
    const lastExecutionTime = useRef(Date.now())

    useEffect(() => {
        const timeElapsed = Date.now() - lastExecutionTime.current

      if(timeElapsed > interval){
        setDebouncedValue(value)
        lastExecutionTime.current = Date.now()
      }else{
        const remainingTime = interval - timeElapsed;
        
        const handler = setTimeout(() => {
            setDebouncedValue(value)
            lastExecutionTime.current = Date.now()
        }, remainingTime);

        return(() => {
            clearTimeout(handler)
        })
      }
    }, [value, interval])
    


    return debouncedValue
}

export default useDebounce