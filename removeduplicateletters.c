#include <stdbool.h>
struct Node{
    char data;
    struct Node* next;
};
void push(struct Node** s1,char data){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = (*s1);
    *s1 = temp;
}
char pop(struct Node** s1){
    struct Node* temp = *s1;
    *s1 = (*s1)->next;
    char data = temp->data;
    free(temp);
    return data;
}
void swap(char* a,char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(char* ans){
    int i=0;
    int n=strlen(ans)-1;
    while(i<n){
        swap(&ans[i],&ans[n]);
        i+=1;
        n-=1;
    }
}
char* removeDuplicateLetters(char* s) {
    struct Node* stack = NULL;
    int frequency[26]={0};
    int n = strlen(s);
    for(int i=0;i<n;i++){
        frequency[s[i]-'a']++;
    }
    bool visited[26]={false};
    char* ans = (char*)malloc((n + 1) * sizeof(char));
    int indx=0;
    for(int i=0;i<n;i++){
        frequency[s[i]-'a']-=1;
        if(visited[s[i]-'a']==true) continue;
        while (stack != NULL && stack->data > s[i] && frequency[stack->data - 'a'] > 0) {
            visited[stack->data - 'a'] = false;
            char popped = pop(&stack);
        }
        push(&stack, s[i]);
        visited[s[i] - 'a'] = true;
    }
    while(stack!=NULL){
        ans[indx++] = pop(&stack);
    }
    ans[indx]='\0';
    printf("%s",ans);
    reverse(ans);
    return ans;
}