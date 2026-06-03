from selenium import webdriver
import time
from selenium.webdriver.common.by import By

driver = webdriver.Chrome()

# acessar o site
driver.get("https://www.google.com/")

# localizar a barra de pesquisa
search = driver.find_element("id", "APjFqb")

# escrever na barra
search.send_keys("Netflix")

# enviar pesquisa
search.submit()

# pegar resultados
resultados = driver.find_elements(By.CSS_SELECTOR, "a h3")

# clicar no primeiro resultado
resultados[0].click()

time.sleep(50)