#include <stdio.h>

// --- Function Prototypes ---
void calculator();      // Q1
void checkPosNeg();     // Q2
void findLargest();     // Q3
void printLoop();       // Q4
float findSquare(float n); // Q5
long long factorial(int n);   // Q6 (Recursive)

int main() {
    int choice;
    printf("--- DS 0th Practical: Basic Logic ---\n");
    printf("1. Calculator\n2. Positive/Negative\n3. Largest of 3\n4. Loop 1-10\n5. Square\n6. Factorial\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: calculator(); break;
        case 2: checkPosNeg(); break;
        case 3: findLargest(); break;
        case 4: printLoop(); break;
        case 5: {
            float num;
            printf("Enter number: ");
            scanf("%f", &num);
            printf("Square: %.2f", findSquare(num));
            break;
        }
        case 6: {
            int num;
            printf("Enter number: ");
            scanf("%d", &num);
            printf("Factorial: %d", factorial(num));
            break;
        }
        default: printf("Invalid choice!");
    }
    return 0;
}

// --- Implemented functions below ---

//que1:Write a program to input two numbers and print their sum, sub, mul, div.
void calculator()
{
    int a, b;
    printf("Enter two numbers to perform operations:");
    scanf("%d %d", &a, &b);
    printf("Sum=%d\n", a+b);
    printf("Sub=%d\n", a-b);
    printf("Mul=%d\n", a*b);
    printf("Div=%d\n", a/b);

}

//que2: Write a C program to check whether a number is positive, negative, or zero.
void checkPosNeg()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n > 0)
        printf("Positive\n");
    else if (n < 0)
            printf("Negative\n");
    else
        printf("Zero\n");
   
}

//que3: Write a C program to find the largest of three numbers.
void findLargest()
{
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    if (a >= b && a >= c)
        printf("Largest: %d\n", a);
    else if (b >= a && b >= c)
        printf("Largest: %d\n", b);
    else
         printf("Largest: %d\n", c);
      
  }

//que4: Write a C program to print numbers from 1 to 10 using a loop.
void printLoop()
{
    for(int i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }
    
}

//que5: Write a C program to find the square of a number.
 float findSquare(float num)
{
    return num*num;
}

//que6: Write a C program to calculate the factorial of a number using recursion.
#include <stdio.h>

long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}
