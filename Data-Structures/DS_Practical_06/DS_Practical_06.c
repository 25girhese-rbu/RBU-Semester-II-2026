#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Utility to create a new node
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

// Iterative insert into BST
Node* insert(Node* root, int value) {
    Node* newnode = createNode(value);
    if (root == NULL) return newnode;

    Node* parent = NULL;
    Node* current = root;

    while (current != NULL) {
        parent = current;
        if (value < current->data)
            current = current->left;
        else if (value > current->data)
            current = current->right;
        else
            return root; // Ignore duplicates
    }

    if (value < parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;

    return root;
}

// Traversals
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Count non-leaf nodes
int countNonLeaf(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 0;
    return 1 + countNonLeaf(root->left) + countNonLeaf(root->right);
}

// Compute depth (height in terms of edges)
int treeDepth(Node* root) {
    if (!root) return -1;
    int left = treeDepth(root->left);
    int right = treeDepth(root->right);
    return (left > right ? left : right) + 1;
}

int main() {
    Node* root = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nInorder Traversal:   ");
    inorder(root);

    printf("\nPreorder Traversal:  ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\nNon-Leaf Nodes: %d", countNonLeaf(root));
    printf("\nDepth of Tree:  %d\n", treeDepth(root));

    return 0;
}
