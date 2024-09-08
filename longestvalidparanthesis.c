struct Node{
    int data;
    struct Node* next;
};
void push(struct Node** s1,int index){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = index;
    temp->next = (*s1);
    (*s1) = temp;
}
void pop(struct Node** s1){
    struct Node* temp = (*s1);
    *s1 = (*s1)->next;
    free(temp);
}
int max(int a,int b){
    if(a>=b) return a;
    return b;
}
int longestValidParentheses(char* s) {
    int n = strlen(s);
    struct Node* stack = NULL;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            push(&stack,i);
        }else{
            if(stack!=NULL && s[stack->data]=='('){
                pop(&stack);
            }else{
                push(&stack,i);
            }
        }
    }
    if(stack==NULL) return n;
    int a = n;
    int b = 0;
    int largest = -1000007;
    while(stack!=NULL){
        b = stack->data;
        pop(&stack);
        largest = max(largest,a-b-1);
        a = b;
    }
    largest = max(largest,a);
    return largest;
}

