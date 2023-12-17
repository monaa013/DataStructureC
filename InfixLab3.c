#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1; 
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push operation
void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Pop operation
char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

// Get the top element of the stack
char peek(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}

// Check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Get the precedence of the operator
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    return -1;
}

// Convert infix expression to postfix expression
void infixToPostfix(char* expression) {
    struct Stack* stack = createStack(strlen(expression));
    int i, k;
    for (i = 0, k = -1; expression[i]; ++i) {
        if (expression[i] >= 'a' && expression[i] <= 'z') {
            expression[++k] = expression[i];
        } else if (expression[i] == '(') {
            push(stack, expression[i]);
        } else if (expression[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                expression[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return; // Invalid expression
            else
                pop(stack);
        } else {
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack))) {
                expression[++k] = pop(stack);
            }
            push(stack, expression[i]);
        }
    }

    while (!isEmpty(stack)) {
        expression[++k] = pop(stack);
    }
    expression[++k] = '\0';
    printf("Postfix expression: %s\n", expression);
    free(stack->array);
    free(stack);
}

int main() {
    char infix[MAX_SIZE];
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Enter infix expression\n");
        printf("2. Display postfix expression\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the infix expression: ");
                scanf("%s", infix);
                break;
            case 2:
                infixToPostfix(infix);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    } while (choice != 3);

    return 0;
}
