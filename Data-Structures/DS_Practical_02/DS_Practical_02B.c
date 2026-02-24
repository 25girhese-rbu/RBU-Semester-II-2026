#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 200

char stack[MAX];
int top = -1;

void push(char c) { if (top < MAX-1) stack[++top] = c; }
char pop(void) { if (top >= 0) return stack[top--]; return '\0'; }
char peek(void) { if (top >= 0) return stack[top]; return '\0'; }
int isEmpty(void) { return top == -1; }

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

/* Simple infix to postfix converter for assignment - concise version */
void infixToPostfix(const char *infix, char *postfix) {
    top = -1;
    int i = 0, j = 0;
    while (infix[i]) {
        char c = infix[i];
        if (c == ' ' || c == '\t') { i++; continue; }
        if (isalnum((unsigned char)c)) { postfix[j++] = c; i++; continue; }
        if (c == '(') { push(c); i++; continue; }
        if (c == ')') {
            while (!isEmpty() && peek() != '(') postfix[j++] = pop();
            if (!isEmpty() && peek() == '(') pop();
            i++; continue;
        }
        while (!isEmpty() && peek() != '(') {
            char topOp = peek();
            int pTop = precedence(topOp);
            int pCur = precedence(c);
            if (pTop > pCur || (pTop == pCur && c != '^')) postfix[j++] = pop();
            else break;
        }
        push(c); i++;
    }
    while (!isEmpty()) { char t = pop(); if (t != '(' && t != ')') postfix[j++] = t; }
    postfix[j] = '\0';
}

int main(void) {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression:\n");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}