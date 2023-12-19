#include <stdbool.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

void push(struct Node** s1, char value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = *s1;
    *s1 = temp;
}

void pop(struct Node** s1) {
    if (*s1 == NULL) return;
    struct Node* temp = *s1;
    *s1 = (*s1)->next;
    free(temp);
}

bool isValid(char* s) {
    struct Node* stack = NULL;
    int n = 0;
    while (s[n] != '\0') {
        if (s[n] == '(' || s[n] == '[' || s[n] == '{') {
            push(&stack, s[n]);
        } else {
            if (s[n] == ')') {
                if (stack != NULL && stack->data == '(') {
                    pop(&stack);
                } else {
                    return false;
                }
            } else if (s[n] == '}') {
                if (stack != NULL && stack->data == '{') {
                    pop(&stack);
                } else {
                    return false;
                }
            } else if (s[n] == ']') {
                if (stack != NULL && stack->data == '[') {
                    pop(&stack);
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        n++;
    }
    return stack == NULL; 
}
