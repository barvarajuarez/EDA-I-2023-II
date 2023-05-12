//codigo para implementar operaciones en una lista ligada circular

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * addToEmpty(struct Node* last, int data) {
    if (last != NULL) return last;

    // asiganar memoria al nuevo nodo
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    //se asigna dato al nuevo nodod
    newNode->data=data;

    //se asigna como last al nuevo noddo
    last=newNode;
    
    //se cre enlace a si mismo
    last->next=last;
    return last;
}

//agregar nodo por el frente
struct Node* addFront(struct Node* last, int data) {
    //se revisa si la lista esta vacia
    if (last == NULL) return addToEmpty(last, data);

    //se asigna memoria la nuevo nodo
    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));

    //se agrega dato al nnuevo nodo 
    newNode->data=data;

    //se guarda la direccion del primer nodo actual en el nuevo nodo 
    newNode->next=last->next;

    //se hace al nuevo nodo como la cabeza
    last-> next=newNode;

    return last;
}

//agregar nodo al final 
struct Node* addEnd (struct Node* last, int data) {

    //se revisa si el nodo esta vacio 
    if (last ==NULL) return addToEmpty (last,data);

    //se asugna memoria al nuevo nodo
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    //se agrega dato al nuevo nodo
    newNode->data=data;

    //se alamcena la direccion del nodo cabeza al siguiente del nuevo nodo 
    newNode->next=last->next;

    //se apunta el actual ultimo nodo al nuevo nodo
    last->next=newNode;

    //se hace al nuevo nodo como elitlimo nodo
    last=newNode;
    return last;

}

//inserta nodo despues de un nodod especifico 
struct Node* addAfter(struct Node* last , int data, int item) {

    //se revisa si la lista esta vacia 
    if (last == NULL ) return NULL;

    struct Node*newNode, *p;

    p= last->next;

    do{
        //si se encontro el elmento , se coloca el nuevo nodo despues de el 
        if (p->data==item){
            //se asigna memoria la nuevo nodod 
            newNode=(struct Node*)malloc(sizeof(struct Node));

            //se agrega dato al nodod
            newNode->data=data;

            //se hace como siguiente el nodod actual siguiente del nuevo nodo
            newNode->next= p->next;

            //se pone al nuevo nodo como el siguiente de p 
            p->next =newNode;

            //si p es el ultimo nodod, se hace al nuevo nodo como el ultimo nodo 
            if (p== last) last=newNode;
            return last;
        }

        p=p->next;

    } while (p!= last->next);

    printf ("\El nodo dado no esta presente en la lista");
    return last;
}

//borrar un nodo 
void deleteNode(struct Node** last, int key) {
    //si la lista ligada esta vacia
    if (*last ==NULL) return; 

    //si la lista contiene solo un nodod
    if ((*last) ->data == key && (*last)->next == *last) {
        free (*last);
        *last =NULL;
        return;
    }

    struct Node *temp=*last, *d;

    //si se va a eliminar el ultimo 
    if ((*last) ->data ==key) {

        // encontrar el nodod antes del ultimo nodo
        while (temp ->next !=*last) temp=temp->next;

        //apuntar un nodo temporal al siuiente del uitlmo es decir el primer nodod
        temp ->next = (*last)->next; 
        free (*last); 
        *last = temp->next; 
    }

    // recorrido al nodo que va a ser eliminado 
    while (temp ->next != * last && temp ->next->data != key) {
        temp=temp->next;
    }

    //si el nodod a eliminar se encuentra
    if (temp->next->data == key) {
        d = temp ->next; 
        temp->next = d->next;
        free(d);
    }
}
    void traverse(struct Node* last) {
        struct Node* p; 

        if (last == NULL) {
            printf ("La lsita esta vacia");
            return; 
        }

        p= last->next;

        do {
            printf ("%d ", p->data);
            p=p->next;
        } while (p != last->next);
    }

    int main () {
        struct Node* last = NULL;

        last = addToEmpty(last,6);
        last=addEnd(last,8);
        last=addFront(last,2);

        last = addAfter (last, 10, 2);

        traverse(last);

        deleteNode(&last, 8);

        printf("\n");

        traverse(last);

        return 0;
    }