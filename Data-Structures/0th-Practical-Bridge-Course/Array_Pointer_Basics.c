#include <stdio.h>

// Function to swap two numbers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // Que7 & Que8: Read 'n' elements into an array, print them, and calculate sum using Variable Length Arrays
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The elements are:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("Sum of elements: %d\n", sum);

    // Que9: Demonstrate the use of pointers to access and modify variable values
    int num = 10;
    int *ptr = &num;
    printf("\nDemonstrating pointers:\n");
    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Value via pointer: %d\n", *ptr);
    *ptr = 20;
    printf("New value of num after modification via pointer: %d\n", num);

    // Que10: Swap two numbers using pointers
    int x, y;
    printf("\nEnter two numbers to swap: ");
    scanf("%d %d", &x, &y);
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}