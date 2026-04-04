#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int power;
    struct Node *next;
} Node;

Node* createNode(int coeff, int power) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

void addTerm(Node **head, int coeff, int power) {
    Node *newNode = createNode(coeff, power);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayPolynomial(Node *head) {
    if (head == NULL) {
        printf("Polynomial is empty\n");
        return;
    }
    printf("P(x) = ");
    Node *temp = head;
    int isFirst = 1;
    while (temp != NULL) {
        if (isFirst) {
            printf("%d", temp->coeff);
            isFirst = 0;
        } else {
            if (temp->coeff >= 0) {
                printf(" + %d", temp->coeff);
            } else {
                printf(" - %d", -temp->coeff);
            }
        }
        
        if (temp->power > 0) {
            printf("x^%d", temp->power);
        }
        
        temp = temp->next;
    }
    printf("\n");
}

Node* addPolynomials(Node *poly1, Node *poly2) {
    Node *result = NULL;
    Node *p1 = poly1;
    Node *p2 = poly2;
    while (p1 != NULL && p2 != NULL) {
        if (p1->power > p2->power) {
            addTerm(&result, p1->coeff, p1->power);
            p1 = p1->next;
        }
        else if (p1->power < p2->power) {
            addTerm(&result, p2->coeff, p2->power);
            p2 = p2->next;
        }
        else {
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0) {
                addTerm(&result, sumCoeff, p1->power);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    while (p1 != NULL) {
        addTerm(&result, p1->coeff, p1->power);
        p1 = p1->next;
    }
    
    while (p2 != NULL) {
        addTerm(&result, p2->coeff, p2->power);
        p2 = p2->next;
    }
    
    return result;
}

void deletePolynomial(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    printf("========== POLYNOMIAL ADDITION USING LINKED LIST ==========\n");
    Node *poly1 = NULL;
    printf("Creating Polynomial 1: 2x^2 + 3x + 4\n");
    addTerm(&poly1, 2, 2);
    addTerm(&poly1, 3, 1);
    addTerm(&poly1, 4, 0);
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("\n");
    Node *poly2 = NULL;
    printf("Creating Polynomial 2: 3x^2 + 4x + 3\n");
    addTerm(&poly2, 3, 2);
    addTerm(&poly2, 4, 1);
    addTerm(&poly2, 3, 0);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    printf("\n");
    printf("Adding Polynomial 1 + Polynomial 2...\n");
    printf("(2x^2 + 3x + 4) + (3x^2 + 4x + 3)\n");
    Node *result = addPolynomials(poly1, poly2);
    printf("\nResult (Polynomial 3): ");
    displayPolynomial(result);
    printf("Expected: 5x^2 + 7x + 7\n");
    printf("========== PROGRAM COMPLETED ==========\n");
    return 0;
}
