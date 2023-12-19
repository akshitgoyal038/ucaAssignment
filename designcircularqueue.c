

typedef struct {
    int* arr;
    int front;
    int rear;
    int size;
    int count;
} MyCircularQueue;

// Function declarations
MyCircularQueue* myCircularQueueCreate(int k);
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);
bool myCircularQueueDeQueue(MyCircularQueue* obj);
int myCircularQueueFront(MyCircularQueue* obj);
int myCircularQueueRear(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
void myCircularQueueFree(MyCircularQueue* obj);

// Function definitions for myCircularQueueIsFull and myCircularQueueIsEmpty
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->count == obj->size;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->count == 0;
}

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* temp = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    temp->arr = (int*)malloc(sizeof(int) * k);
    temp->front = -1;
    temp->rear = -1;
    temp->size = k;
    temp->count = 0;
    return temp;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        return false;
    } else if (obj->rear == -1) {
        obj->front = 0;
        obj->rear = 0;
        obj->arr[obj->rear] = value;
    } else if (obj->rear == obj->size - 1 && obj->front != 0) {
        obj->rear = 0;
        obj->arr[obj->rear] = value;
    } else {
        obj->rear = obj->rear + 1;
        obj->arr[obj->rear] = value;
    }
    obj->count += 1;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }
    if (obj->front == obj->rear) {
        obj->front = -1;
        obj->rear = -1;
    } else {
        obj->front = (obj->front + 1) % obj->size;
    }
    obj->count -= 1;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->arr[obj->rear];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}


