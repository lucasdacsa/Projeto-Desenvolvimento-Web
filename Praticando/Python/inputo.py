nome = input("Digite o seu nome: ")
idade = int(input("Digite a sua idade: "))

print (f"\n Olá, {nome}!")

if idade < 18:

    print ("Você é menor de idade. Aproveite seus estudos e se prepare para o futuro! 📚\n")

elif idade >= 18 and idade <= 60:

    print ("Você é adulto! Continue buscando seus objetivos! 💪\n")

else: 
    print ("Você é uma pessoa experiente! Aproveite a vida com sabedoria. 🌟\n")
