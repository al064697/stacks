#include <stdio.h>
#include <stdlib.h>

//!Dynamic structures: STACKS

//1.- Create a stack
typedef int Item; 

typedef struct node {
    Item element; 
    struct node *next;
}Node;

typedef struct {
    Node *top;
}Stack;

void createStack(Stack *stack) {
    stack->top = NULL;
}
int isStackEmpty(Stack stack) {
    return (stack.top == NULL);
    //1.- Stack is empty
    //0.- Stack has elements
}

Item top(Stack *stack) { /*2.- Returns the top element of the stack*/
    if(isStackEmpty(*stack)) {
        puts("Underflow");
        exit(1);
    }
    return stack->top->element;
}

void insert(Stack *stack, Item element) { //3.- Insert an element into the stack
    Node *newNode;
    newNode = (Node*) malloc(sizeof(Node));
    newNode -> element = element;
    newNode -> next = stack->top;
    stack->top = newNode;
}

void removeFirstNode(Stack *stack) { //4.- Remove an element from the stack
    if(isStackEmpty(*stack) == 0) {
        Node *f;
        f=stack->top;
        stack->top=f->next;
        free(f);
        printf("The top element is removed.\n");

    }else printf("The stack is empty.\n");
}

void cleanStack(Stack *stack) {  //5.-Clean the stack
    while(!isStackEmpty(*stack)) {
        removeFirstNode(stack);
    }
}

int sizeStack(Stack stack) { //6.- Count the number of elements in the stack
    Node *f;
    int count = 0;
    for(f=stack.top; f!=NULL; f=f->next) {
        count++;
    }
    return count;
}

int menu() { //Menu function
    system("clear");
    int option;
    printf("********** STACKS **********\n"
    "\n1.- Create a stack."
    "\n2.- Insert an element into the stack."
    "\n3.- Remove an element from the stack."
    "\n4.- Stack size."
    "\n5.- Clean the stack."
    "\n6.- Top element of the stack."
    "\n0.- Exit."
    "\n\nChoose an option: "); 
    scanf("%d", &option);
    return option;
}

int main() {
    Stack stack;
    int option, n;
    option = menu();
    while (option!=0) {
        switch(option) {
            case 1:
                createStack(&stack);
                print("\nStack created.");
                getchar();
                break;
            case 2: 
                printf("\nInsert an element: ");
                scanf("%d", &n);
                insert(&stack, n);
                printf("\nElement inserted.");
                getchar();
                break;
            case 3:
                removeFirstNode(&stack);
                getchar();
                break;
            case 4:
                printf("\nStack size: %d", sizeStack(stack));
                getchar();
                break;
            case 5:
                cleanStack(&stack);
                printf("\nStack cleaned.");
                getchar();
                break;
            case 6:
                printf("\nTop element: %d", top(&stack));
                getchar();
                break;
            default:
                printf("\nExiting...");
                system("exit");
                break;
        }
        option = menu();
    } 
    return 0;
}