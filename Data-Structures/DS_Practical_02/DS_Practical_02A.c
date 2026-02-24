#include <stdio.h>
#include <stdlib.h>

// 1. Declare global variables so all functions can see them
int stack[100];
int top = -1;

void display();

int main() {
    int ch, x;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Push\n2. Pop\n3. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (top == 99) { // Boundary check: isFull
                    printf("Stack Overflow\n");
                } else {
                    printf("Enter an item: ");
                    scanf("%d", &x); // 2. FIX: Added '&' to x
                    stack[++top] = x;
                    display();
                }
                break;
            case 2:
                if (top == -1) { // Boundary check: isEmpty
                    printf("The stack is empty\n");
                } else {
                    printf("Deleted element is %d\n", stack[top--]);
                    display();
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 3);
    return 0;
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        // 3. FIX: Loop downwards from top to 0
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
