j1_vida = 100
inm_vida = 50

while j1_vida > 0:
    print("voce recebeu dano!")
    j1_vida-= 2
    print("Vida atual:", j1_vida)

    if j1_vida <= 0:
        print("GAME OVER")

