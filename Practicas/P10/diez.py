libros = [ "El Principito" , "Cien años de Soledad", "Romeo y Julieta", "Harry Potter"]

def agregar(titulo):
    id = len(libros) + 1
    libros.append(titulo)
    print("Libro agregado\n")

def eliminar(titulo):
    libros.remove(titulo)
    print("Libro eliminado\n")
    print(libros)

def ordenar(libro):
    libros.sort()
    print(libros)


def mostrar(libros):
    print(libros)



def menu():
    print("Menú de opciones:")
    print("1 - Agregar libro")
    print("2 - Eliminar libro")
    print("3 - Ordenar biblioteca")
    print("4 - Ver biblioteca")
    print("5 - Salir")


while True:
    menu()
    opcion = input("Seleccione una opción: ")

    if opcion == "1":
        titulo = input("Ingrese el título del libro a agregar: ")
        agregar(titulo)
    elif opcion == "2":
        titulo = input("Ingrese el indice del libro a eliminar: ")
        eliminar(titulo)
    elif opcion == "3":
        ordenar(libros)
    elif opcion == "4":
        mostrar(libros)
    elif opcion == "5":
        print("Saliendo del programa.\n")
        break
    else:
        print("Opción inválida. Por favor, seleccione una opción válida.\n")