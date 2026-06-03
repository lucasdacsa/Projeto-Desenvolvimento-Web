vida = int (input("Qual o seu estado de vida atual?"))

if vida >=70 and vida <= 100:
    print("Você estar saudavel")

elif vida >=30 and vida <=70:
    print("Ferido")

elif vida < 20:
    print("Critico!!!")