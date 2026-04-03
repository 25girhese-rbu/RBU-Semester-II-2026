#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node Node;
Node *head = NULL;
// Create a new node
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Insert at beginning
void insertAtBeginning(int data) {
    Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}
// Insert at end
void insertAtEnd(int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
// Insert at position
void insertAtPosition(int data, int pos) {
    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }
    Node *newNode = createNode(data);
    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}
// Delete at beginning
void deleteAtBeginning() {
    if (head == NULL) { printf("List is empty!\n"); return; }
    Node *temp = head;
    head = head->next;
    free(temp);
}
// Delete at end
void deleteAtEnd() {
    if (head == NULL) { printf("List is empty!\n"); return; }
    if (head->next == NULL) { free(head); head = NULL; return; }
    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}
// Delete at position
void deleteAtPosition(int pos) {
    if (head == NULL) { printf("List is empty!\n"); return; }
    if (pos == 1) { deleteAtBeginning(); return; }
    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;
    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}
// Display the list
void display() {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Main 
int main() {

    insertAtBeginning(10);
    printf("After inserting 10 at beginning:  "); 
    display();

    insertAtEnd(20);
    printf("After inserting 20 at end:        "); 
    display();

    insertAtPosition(15, 2);
    printf("After inserting 15 at position 2: "); 
    display();

    insertAtBeginning(5);
    printf("After inserting 5 at beginning:   "); 
    display();

    deleteAtBeginning();
    printf("After deleting at beginning:      "); 
    display();

    deleteAtEnd();
    printf("After deleting at end:            "); 
    display();

    deleteAtPosition(2);
    printf("After deleting at position 2:     "); 
    display();

    return 0;
}