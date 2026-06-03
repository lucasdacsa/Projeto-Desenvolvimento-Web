# Programa com menu interativo

opcao = 0  # variável de controle

while opcao != 4: 
    print("\n---- MENU PRINCIPAL ----")
    print("1 - Dizer olá")
    print("2 - Calcular a soma de dois números")
    print("3 - Mostrar tabuada")
    print("4 - Sair")

    opcao = int(input("Escolha uma opção: "))

    if (opcao == 1):
        print("Olá! Seja muito bem-vindo. 👋")

    elif (opcao == 2):
        n1 = float(input("Digite o primeiro número: "))
        n2 = float(input("Digite o segundo número: "))
        soma = n1 + n2
        print(f"Resultado da soma entre {n1} e {n2} é {soma}")

    elif (opcao == 3):
        num = int(input("Digite um número para ver a tabuada: "))
        for i in range(1, 11):
            print(f"{num} x {i} = {num * i}")

    elif (opcao == 4):
        print("Saindo... 👋")

    else: 
        print("Comando inválido! Tente novamente.")






















"""opcao = 0

while opcao !=4:

    print("Menu de opções")
    print("1- Dizer Olá ")
    print("2- Calcular Soma ")
    print("3- Mostrar Tabuada ")
    print("4- Sair")

    opcao = int (input("Escolha uma opcão: "))

    if (opcao == 1):
        print("Olá Seja Bem Vindo ",opcao)

    elif(opcao == 2):
       a = float (input("Digite o Primeiro Numero: "))
       b = float (input("Digite o Segundo Numero: "))

       print("Soma = ", a + b)

    elif opcao == 3:
       n = int (input("Digite um numero: "))

       for i in range (1, 11):
           print(f"{n} x {i} = {n * i}")

    elif opcao == 4:
        print("Saindo...")

    else: 
        print ("opção invalida.!")"""