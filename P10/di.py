libros = []

def agregar(titulo):
    id = len(libros) + 1
    libro = {'titulo': titulo, 'id': id}
    libros.append(libro)
    print("Libro agregado con éxito.")

def eliminar(titulo):
    eliminados = [libro for libro in libros if libro['titulo'] == titulo]
    if len(eliminados) > 0:
        libros[:] = [libro for libro in libros if libro['titulo'] != titulo]
        print("Libro(s) eliminado(s) con éxito.")
    else:
        print("No se encontró ningún libro con ese título.")

def ordenar():
    opcion = input("Seleccione el criterio de ordenamiento (1 - ID, 2 - Título): ")
    if opcion == "1":
        libros.sort(key=lambda x: x['id'])
    elif opcion == "2":
        libros.sort(key=lambda x: x['titulo'])
    else:
        print("Opción inválida. No se realizó ningún cambio en la biblioteca.")

def ver():
    if len(libros) == 0:
        print("La biblioteca está vacía.")
    else:
        print("Biblioteca:")
        for libro in libros:
            print(f"ID: {libro['id']}, Título: {libro['titulo']}")

def mostrar_menu():
    print("Menú de opciones:")
    print("1 - Agregar libro")
    print("2 - Eliminar libro")
    print("3 - Ordenar biblioteca")
    print("4 - Ver biblioteca")
    print("5 - Salir")

while True:
    mostrar_menu()
    opcion = input("Seleccione una opción: ")

    if opcion == "1":
        titulo = input("Ingrese el título del libro a agregar: ")
        agregar(titulo)
    elif opcion == "2":
        titulo = input("Ingrese el título del libro a eliminar: ")
        eliminar(titulo)
    elif opcion == "3":
        ordenar()
    elif opcion == "4":
        ver()
    elif opcion == "5":
        print("Saliendo del programa.")
        break
    else:
        print("Opción inválida. Por favor, seleccione una opción válida.")