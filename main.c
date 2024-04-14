#include <stdio.h>
#include <stdlib.h>

//!Estructuras dinámicas: PILAS

//1.- Crear una pila
typedef int Item; // Definimos Item como un alias para int

// Definimos una estructura para los nodos de la pila
typedef struct node {
    Item element; // El elemento que se guarda en el nodo
    struct node *next; // Un puntero al siguiente nodo en la pila
}Node;

// Definimos una estructura para la pila
typedef struct {
    Node *top; // Un puntero al nodo superior de la pila
}Stack;

// Función para crear una pila
void createStack(Stack *stack) {
    stack->top = NULL; // Inicializamos la pila con NULL, indicando que la pila está vacía
}

// Función para verificar si la pila está vacía
int isStackEmpty(Stack stack) {
    return (stack.top == NULL); // Si el top es NULL, la pila está vacía
    //1.- Pila vacía
    //0.- Pila con elementos
}

/*2.- Retorna el primer elemento de la pila*/
Item top(Stack *stack) {
    if(isStackEmpty(*stack)) { // Si la pila está vacía, imprime "Underflow" y termina el programa
        puts("Underflow");
        exit(1);
    }
    return stack->top->element; // Si la pila no está vacía, retorna el elemento en el top de la pila
}

//3.- Insertar un elemento a la pila
void insert(Stack *stack, Item element) {
    Node *newNode; // Creamos un nuevo nodo
    newNode = (Node*) malloc(sizeof(Node)); // Asignamos memoria para el nuevo nodo
    newNode -> element = element; // Asignamos el elemento al nuevo nodo
    newNode -> next = stack->top; // El siguiente nodo después del nuevo nodo es el actual top de la pila
    stack->top = newNode; // El nuevo nodo se convierte en el top de la pila
}

//4.- Eliminar un elemento de la pila
void removeFirstNode(Stack *stack) {
    if(isStackEmpty(*stack) == 0) { // Si la pila no está vacía
        Node *f;
        f=stack->top; // Guardamos el nodo superior en f
        stack->top=f->next; // El segundo nodo se convierte en el top de la pila
        free(f); // Liberamos la memoria del nodo superior original
        printf("El elemento superior ha sido eliminado.\n");
    }else printf("La pila está vacía.\n");
}

//5.- Limpiar la pila
void cleanStack(Stack *stack) {
    while(!isStackEmpty(*stack)) { // Mientras la pila no esté vacía
        removeFirstNode(stack); // Eliminamos el nodo superior
    }
}

//6.- Contar el número de elementos en la pila
int sizeStack(Stack stack) {
    Node *f;
    int count = 0;
    for(f=stack.top; f!=NULL; f=f->next) { // Recorremos todos los nodos de la pila
        count++; // Incrementamos el contador por cada nodo
    }
    return count; // Retornamos el contador
}

// Función del menú
int menu() {
    system("clear"); // Limpiamos la consola
    int option;
    printf("********** PILAS **********\n"
    "\n1.- Crear una pila."
    "\n2.- Insertar un elemento en la pila."
    "\n3.- Eliminar un elemento de la pila."
    "\n4.- Tamaño de la pila."
    "\n5.- Limpiar la pila."
    "\n6.- Elemento superior de la pila."
    "\n0.- Salir."
    "\n\nElige una opción: "); 
    scanf("%d", &option); // Leemos la opción del usuario
    return option; // Retornamos la opción
}

int main() {
    Stack stack; // Creamos una pila
    int option, n;
    option = menu(); // Mostramos el menú y obtenemos la opción del usuario
    while (option!=0) { // Mientras la opción no sea 0 (salir)
        switch(option) { // Realizamos una acción diferente dependiendo de la opción
            case 1:
                createStack(&stack); // Creamos una pila
                printf("\nPila creada.");
                getchar();
                break;
            case 2: 
                printf("\nInsertar un elemento: ");
                scanf("%d", &n); // Leemos el elemento del usuario
                insert(&stack, n); // Insertamos el elemento en la pila
                printf("\nElemento insertado.");
                getchar();
                break;
            case 3:
                removeFirstNode(&stack); // Eliminamos el elemento superior de la pila
                getchar();
                break;
            case 4:
                printf("\nTamaño de la pila: %d", sizeStack(stack)); // Imprimimos el tamaño de la pila
                getchar();
                break;
            case 5:
                cleanStack(&stack); // Limpiamos la pila
                printf("\nPila limpiada.");
                getchar();
                break;
            case 6:
                printf("\nElemento superior: %d", top(&stack)); // Imprimimos el elemento superior de la pila
                getchar();
                break;
            default:
                printf("\nSaliendo...");
                system("exit"); // Salimos del programa
                break;
        }
        option = menu(); // Mostramos el menú de nuevo y obtenemos la nueva opción del usuario
    } 
    return 0; // Terminamos el programa
}