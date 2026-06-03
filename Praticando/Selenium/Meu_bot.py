from selenium import webdriver
import time

# Abrir o navegador
navegador = webdriver.Chrome()

# Acessar o site
navegador.get("https://www.hashtagtreinamentos.com")

# Colocar navegador em tela cheia
navegador.maximize_window()

# Selecionar um elemento na tela
botao_verde = navegador.find_element("class name", "botao-verde")

# Clicar no elemento selecionado
botao_verde.click()

# Encontrar varios elementos na tela
botoes = navegador.find_elements("class name", "header__titulo")

for botao in botoes:
    if "assinatura" in botao.text.lower():
        botao.click()
        break

# selecionar uma aba
abas = navegador.window_handles
navegador.switch_to.window(abas[1])

# Navegar para uma pagina diferente
navegador.get("https://www.hashtagtreinamentos.com/pg-inscricao-python-impressionador?fonte=lespera&src=lespy-site&utm_source=site&utm_medium=header&utm_content=link-header-cursos&utm_campaign=programacao&curso=python")

# Dar tempo para o site carregar           
time.sleep(10)