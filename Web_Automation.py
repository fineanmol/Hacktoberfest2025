# pip install selenium
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time

driver = webdriver.Chrome("chromedriver.exe")
driver.get("https://www.google.com")
search_box = driver.find_element("name", "q")
search_box.send_keys("Python programming")
search_box.send_keys(Keys.RETURN)

time.sleep(5)
driver.quit()
