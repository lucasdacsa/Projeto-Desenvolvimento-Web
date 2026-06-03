soma = 0 
num = float (input("Digite um numero: \n(0 Para sair) "))

while num != 0:
    num = int (input("Digite outro numero: \n(0 Para sair)"))

    soma += num

print ("A soma total é: ", soma)