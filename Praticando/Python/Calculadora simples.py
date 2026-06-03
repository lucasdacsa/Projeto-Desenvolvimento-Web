n1 = float(input("digite o primeiro numero: "))
n2 = float(input("digite o segundo numero: "))
op = input("Escolha uma das operações, (+, -, *, / ")

if(op == "+"):
    
    print(" Resultado:  ",n1 + n2)
elif(op == "-"):

    print("Resultado: ",n1 - n2)

elif(op == "*"):
    print(" Resultado: ", n1 * n2)

elif (op == "/"):
    print("Resultado: ", n1 / n2)

else: print("Comando invalido ")