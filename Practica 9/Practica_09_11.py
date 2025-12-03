n = int(input("¿Cuántos números quieres ingresar? "))
lista = []

for i in range(n):
    num = int(input("Número: "))
    lista.append(num)

print("La lista es:", lista)
print("La suma es:", sum(lista))
