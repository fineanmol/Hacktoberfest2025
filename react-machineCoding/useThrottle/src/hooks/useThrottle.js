import { useEffect, useRef, useState } from "react"

const useThrottle = (input, interval) => {

    const [value, setValue] = useState(input)
    const prevCall = useRef(0)

    useEffect(() => {
        const now = Date.now()
        const rem = interval - (now - prevCall.current)

        let handler;
        if(rem > 0){
            handler  = setTimeout(() => {
                setValue(input)
                prevCall.current = Date.now()
            }, rem);
            
            return(() => clearTimeout(handler))
        }else{
            setValue(input)
            prevCall.current = now
        }

    }, [input, interval])
    

    return value
}

export default useThrottle