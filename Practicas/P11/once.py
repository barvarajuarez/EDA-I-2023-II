def bin(n):
    if n == 0:
        return "0"
    else:
        return bin(n//2) + str (n%2)

def reverseFibonacci(n):
    a = [0] * n 
    a[0] = 0
    a[1] = 1
    if n <= 0:
        print("ingrese un entero positivo")
    else:
        print("Serie de Fibonacci:")
        for i in range(2, n): 
            a[i] = a[i - 2] + a[i - 1]
        for i in range(n - 1, -1 , -1): 
            print(a[i],end=" ")
            

def menu ():
    print("\nBienvenido, puede realizar las siguientes operaciones: ")
    print("1. Conversión de bases")
    print("2. Serie Fibonacci")
    print("3. Salir")

while True:
    menu()
    opcion = input("Ingrese la opción deseada: ")

    if opcion == '1':
        numero = int(input("\nIngrese un número entero: "))
        binario = bin(numero)
        print("\nEl número binario equivalente es:\n", binario)
    elif opcion== '2' :
        n=int(input("\nIngrese un número entero: "))
        reverse = reverseFibonacci(n)
    elif opcion == '3':
        print("¡Hasta luego!")
        break
    else:
        print("Opción inválida. Por favor, ingrese una opción válida.\n")