def swap_first_last(num):
    last = num % 10
    
    temp = num
    power = 0
    while temp >= 10:
        temp //= 10
        power += 1
    first = temp

    middle = num % (10**power)
    middle = middle // 10

    result = (last * (10**power)) + (middle * 10) + first
    return result
