from selenium import webdriver
from selenium.webdriver.common.by import By
import time

driver = webdriver.Chrome()
driver.get("https://www.chatbot.com/")
driver.maximize_window()

time.sleep(5)

def responder(mensagem):
    mensagem = mensagem.lower()

    if "oi" in mensagem:
        return "Olá! Como posso ajudar você hoje?"

    elif "nome" in mensagem:
        return "Eu sou Clia - seu assistente virtual!"

    elif "serviço" in mensagem or "servicos" in mensagem:
        return "Oferecemos atendimento ao cliente, suporte técnico e informações sobre produtos."

    elif "obrigado" in mensagem:
        return "De nada! 😊"

    else:
        return "Desculpe, não entendi sua mensagem."

# Loop do chatbot
while True: # O chatbot continuará respondendo até que o cliente digite "sair"
    msg = input("Cliente: ")  # Recebe a mensagem do cliente
    resposta = responder(msg) # Gera a resposta do chatbot com base na mensagem do cliente
    print("Bot:", resposta) # Imprime a resposta do chatbot