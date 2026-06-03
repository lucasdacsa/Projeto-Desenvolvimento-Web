from selenium import webdriver
import time
from selenium.webdriver.common.by import By

netflix2 = webdriver.Chrome()

netflix2.get("https://www.netflix.com.br/")

netflix2.maximize_window()


# Encontrar um elemento base na tela
navegador = netflix2.find_element(By.CSS_SELECTOR, ".default-ltr-iqcdef-cache-cf8xw5.e13lj3hn3")
navegador.click()

navegador2 = netflix2.find_element(By.CSS_SELECTOR, ".e136yimv2.default-ltr-iqcdef-cache-13gp4ap")
navegador2.click()

# Dar scroll para colocar o elemento no centro da tela
netflix2.execute_script("arguments[0].scrollIntoView({block: 'center'})", navegador)



# Tempo para visualizar a página do filme carregando
time.sleep(10)