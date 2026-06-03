from selenium import webdriver
import time
from selenium.webdriver.common.by import By

# Abrir site
site_netflix = webdriver.Chrome()
site_netflix.get("https://www.netflix.com/")

site_netflix.maximize_window()

# Imprimir o título do site
print (site_netflix.title)

site_netflix.get("https://www.netflix.com/login")

email = site_netflix.find_element(By.NAME, "userLoginId")
email.send_keys("lucas06ok@hotmail.com")

senha = site_netflix.find_element(By.NAME, "password")
senha.send_keys("12345678")

# Localizar o botão de "Entrar" pelo atributo data-uia e clicar
botao_entrar = site_netflix.find_element(By.XPATH, "//button[@data-uia='login-submit-button']")
botao_entrar.click()

time.sleep(50)