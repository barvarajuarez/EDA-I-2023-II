#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

void insertFront(struct Node** head, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = (*head);
  newNode->prev = NULL;
  if ((*head) != NULL)
    (*head)->prev = newNode;
  (*head) = newNode;
}

void insertAfter(struct Node* prev_node, int data) {
  if (prev_node == NULL) {
    printf("Nodo previo no puede ser null");
    return;
  }
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = prev_node->next;
  prev_node->next = newNode;
  newNode->prev = prev_node;
  if (newNode->next != NULL)
    newNode->next->prev = newNode;
}

void insertEnd(struct Node** head, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  struct Node* temp = *head;
  if (*head == NULL) {
    newNode->prev = NULL;
    *head = newNode;
    return;
  }
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = newNode;
  newNode->prev = temp;
}

void deleteNode(struct Node** head, struct Node* del_node) {
  if (*head == NULL || del_node == NULL)
    return;
  if (*head == del_node)
    *head = del_node->next;
  if (del_node->next != NULL)
    del_node->next->prev = del_node->prev;
  if (del_node->prev != NULL)
    del_node->prev->next = del_node->next;
  free(del_node);
}

void displayList(struct Node* node) {
  struct Node* last;
  while (node != NULL) {
    printf("%d->", node->data);
    last = node;
    node = node->next;
  }
  if (node == NULL)
    printf("NULL\n");
}

int main() {
  struct Node* head = NULL;

  int choice = 0;
  int data, position;

  while (choice != 3) {
    printf("\n1. Insertar\n2. Eliminar\n3. Salir\nIngrese la opcion: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\n1. Insertar al inicio\n2. Insertar despues de un nodo\n3. Insertar al final\nIngrese la opcion: ");
        scanf("%d", &position);
        printf("Ingrese el valor del nodo: ");
        scanf("%d", &data);
        switch (position) {
          case 1:
            insertFront(&head, data);
            break;
          case 2:
            printf("Ingrese el valor del nodo previo: ");
            scanf("%d", &position);
            struct Node* temp = head;
            while (temp != NULL && temp->data != position)
              temp = temp->next;
            if (temp == NULL) {
              printf("Nodo previo no encontrado\n");
              break;
            }
            insertAfter(temp, data);
            break;
          case 3:
            insertEnd(&head, data);
            break;
          default:
            printf("Opcion invalida");
            }
    case 2:
    printf("Ingrese el valor del nodo a eliminar: ");
    scanf("%d", &data);
    struct Node* del_node = head;
    while (del_node != NULL && del_node->data != data)
    del_node = del_node->next;
    if (del_node == NULL) {
        printf("Nodo no encontrado\n");
        break;
        }
        deleteNode(&head, del_node);
        printf("Nodo eliminado exitosamente\n");
        break;
    case 3:
    printf("Saliendo del programa...\n");
    break;
    default:
    printf("Opcion invalida\n");
    break;
    }
    displayList(head);
}

return 0;
}
        
        