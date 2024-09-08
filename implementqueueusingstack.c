typedef struct {
    int* arr;
    int front;
    int rear;
    int sz;    
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->arr = (int*)malloc(sizeof(int)*10);
    obj->front = -1;
    obj->rear = -1;
    obj->sz = 0;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    if(obj->front == -1 && obj->rear == -1){
        obj->front++;
        obj->rear++;
        obj->arr[obj->rear] = x;
    }else{
        obj->rear++;
        obj->arr[obj->rear] = x;
    }
    obj->sz++;
}



int myQueuePeek(MyQueue* obj) {
    int ele = obj->arr[obj->front];
    return ele;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->sz == 0;
}

void myQueueFree(MyQueue* obj) {
    free(obj->arr);
}
int myQueuePop(MyQueue* obj) {
    if(myQueueEmpty(obj)) return -1;
    int ele = obj->arr[obj->front];
    obj->front++;

    
    obj->sz--;


    return ele;




}