
nivel = int (input("Digite qual o seu nivel: "))

if nivel <10:
    print("Você é um Iniciante!!")

elif nivel > 10 and nivel < 20:
    print("Voçê é um intermediario!!")

elif nivel > 20:
    print("Voçê é um avançado!!")

else: 
    print("Comando invalido.")