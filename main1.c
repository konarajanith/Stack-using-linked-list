#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define a structure for the stack node
    struct StackNode {
        int value;
        struct StackNode* link;
    };
    
    // Initialize the stack
    struct StackNode* top = NULL;

    // Function to check if the stack is empty
    int stackIsEmpty(struct StackNode* top) {
        return top == NULL;
    }

    // Function to add an element to the stack
    void stackPush(struct StackNode** top, int value) {
        struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
        if (newNode == NULL) {
            printf("\nUnable to allocate memory for new node\n");
            return;
        }
        newNode->value = value;
        newNode->link = *top;
        *top = newNode;
    }

    // Function to remove the top element from the stack
    int stackPop(struct StackNode** top) {
        if (stackIsEmpty(*top)) {
            printf("\nNo element to pop, the stack is empty\n");
            return INT_MIN;
        }
        
        struct StackNode* temp = *top;
        int poppedValue = temp->value;
        *top = (*top)->link;
        free(temp);
        
        return poppedValue;
    }

    // Function to get the top element of the stack without removing it
    int stackTop(struct StackNode* top) {
        if (stackIsEmpty(top)) {
            printf("\nThe stack is empty\n");
            return INT_MIN;
        }
        return top->value;
    }

    // Function to print all elements of the stack (optional)
    void printStack(struct StackNode* top) {
        if (stackIsEmpty(top)) {
            printf("\nThe stack is empty\n");
            return;
        }
        
        struct StackNode* current = top;
        printf("\nStack elements:\n");
        while (current != NULL) {
            printf("%d\n", current->value);
            current = current->link;
        }
    }

    // Push elements onto the stack
    stackPush(&top, 10);
    stackPush(&top, 20);
    stackPush(&top, 30);
    stackPush(&top, 40);

    // Print the top element of the stack
    printf("Top element is %d\n", stackTop(top));

    // Print all elements of the stack
    printStack(top);

    // Remove two elements from the stack
    printf("Popping two elements...\n");
    stackPop(&top);
    stackPop(&top);

    // Print the top element of the stack again
    printf("Top element is %d\n", stackTop(top));

    return 0;
}


