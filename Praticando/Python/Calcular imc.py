
# Programa para calcular o IMC (Índice de Massa Corporal)
print ("----CALCULADORA IMC----")

# Entrada de dados
peso = float (input("Digite seu peso: "))
altura = float ( input("Digite sua altura: "))

# Cálculo do IMC
imc = peso / (altura ** 2)

# Exibe o resultado formatado com 2 casas decimais
print ("Seu imc é: ", imc)

# Classificação do IMC
if imc < 18.5:
    print("Você está abaixo do peso.")
elif imc >= 18.5 and imc < 25:
    print("Você está com peso normal. 😊")
elif imc >= 25 and imc < 30:
    print("Você está com sobrepeso.")
elif imc >= 30 and imc < 35:
    print("Obesidade grau I.")
elif imc >= 35 and imc < 40:
    print("Obesidade grau II (severa).")
else:
    print("Obesidade grau III (mórbida). ⚠️")