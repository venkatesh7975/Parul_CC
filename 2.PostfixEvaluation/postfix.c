#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 200

int stack[MAX];
int top = -1;

// Push
void push(int x) {
    if (top == MAX - 1) {
        printf("Evaluation failed due to errors in the expression.\n");
        exit(0);
    }
    stack[++top] = x;
}

// Pop with error check
int pop() {
    if (top < 0) {
        printf("Evaluation failed due to errors in the expression.\n");
        exit(0);
    }
    return stack[top--];
}

// Check if token is integer (positive or negative)
int isInteger(char *s) {
    if (s[0] == '-' && strlen(s) > 1) {
        for (int i = 1; s[i]; i++) {
            if (!isdigit(s[i])) return 0;
        }
        return 1;
    }
    for (int i = 0; s[i]; i++) {
        if (!isdigit(s[i])) return 0;
    }
    return 1;
}

int main() {
    char expr[500];
    fgets(expr, sizeof(expr), stdin); // Read entire line

    char *token = strtok(expr, " ");

    while (token != NULL) {

        if (isInteger(token)) {
            push(atoi(token));
        }
        else {
            if (top < 1) { 
                printf("Evaluation failed due to errors in the expression.\n");
                return 0;
            }

            int b = pop();
            int a = pop();

            if (strcmp(token, "+") == 0) {
                push(a + b);
            }
            else if (strcmp(token, "-") == 0) {
                push(a - b);
            }
            else if (strcmp(token, "*") == 0) {
                push(a * b);
            }
            else if (strcmp(token, "/") == 0) {
                if (b == 0) {
                    printf("Error: Division by zero.\n");
                    printf("Evaluation failed due to errors in the expression.\n");
                    return 0;
                }
                push(a / b);
            }
            else {
                // Invalid operator
                printf("Evaluation failed due to errors in the expression.\n");
                return 0;
            }
        }

        token = strtok(NULL, " ");
    }

    // Final check
    if (top != 0) {
        printf("Evaluation failed due to errors in the expression.\n");
        return 0;
    }

    printf("%d\n", stack[top]);
    return 0;
}
