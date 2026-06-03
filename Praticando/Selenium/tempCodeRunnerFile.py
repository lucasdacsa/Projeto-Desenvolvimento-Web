from selenium import webdriver
from selenium.webdriver.common.by import By
import time


# Abrir o navegador
driver = webdriver.Chrome()

# Acessar o site
driver.get("https://web.whatsapp.com/")

# Dar tempo para o usuário escanear o QR code
input("Escaneie o QR code e pressione Enter para continuar...")

# Nome do contato ou grupo
contato = "Minha Lua"

# Procurar texto do contato ou grupo
searchbox = driver.find_element(By.CLASS_NAME, "x1iyjqo2.x6ikm8r.x10wlt62.x1n2onr6.xlyipyv.xuxw1ft.x1rg5ohu.x1jchvi3.xjb2p0i.xo1l8bm.x17mssa0.x1ic7a3i._ao3e")

 # Clicar na caixa de pesquisa
searchbox.click()

 # Digitar o nome do contato ou grupo
searchbox.send_keys(contato)

 # clicar no contato ou grupo
contato_encontrado = driver.find_element(By.CLASS_NAME, "_ak8l _ap1_")
contato_encontrado.click()

# Dar tempo para carregar a conversa
time.sleep(5)

def responder (mensagem):
    mensagem = mensagem.lower()

    if "oi" in mensagem:
        resposta = "Olá! Como posso ajudar voçê hoje?"
    elif "Preço" in mensagem:
        return "Nossos preços estão no site "
    elif "tchau" in mensagem:
        return "ate mais!"
    else:
        return "Desculpe, não entendi sua mensagem. Pode reformular?"
    
    


