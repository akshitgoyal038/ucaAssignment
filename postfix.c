#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct Node{
   int data;
   struct Node* next;
};
void push(struct Node** s1,int data){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    // temp->next = NULL;
    temp->next = (*s1);
    (*s1) = (temp);
}
int pop(struct Node** s1){
    if(*s1==NULL) return 0;
    struct Node* temp = *s1;
    (*s1) = (*s1)->next;
    return temp->data;
}
int main() {
    int t;
    scanf("%d",&t);
    struct Node* s1 = NULL;
    while(t-- >0){
        char a[10];
        scanf("%s",a);
        while(a[0]!='?'){
            
            if('0'<=a[0] && a[0]<='9'){
                int index = 0;
                int number = 0;
                while(a[index]!='\0'){
                    number = number *10 + (a[index] - '0');
                    index++;
                }
                // printf("%d \n", number);
                push(&s1,number);
            }else{
                int operand = pop(&s1);
                int operand1 = pop(&s1);
                // printf("%d %d \n", operand, operand1);
                if(a[0]=='+'){
                    // printf(" add : %d\n",operand+operand1);
                    push(&s1,operand+operand1);
                }else if(a[0]=='-'){
                    // printf("sub : %d\n",operand1-operand);
                    push(&s1,operand1-operand);
                }else if(a[0]=='*'){
                    // printf("mul : %d\n",operand*operand1);
                    push(&s1,operand*operand1);
                }else{
                    // printf("div : %d\n",operand1/operand);
                    push(&s1,operand1/operand);
                }
            }
            scanf("%s",a);
        }
        int x = pop(&s1);
        printf("%d\n",x);
        free(s1);
    }
    return 0;
}
