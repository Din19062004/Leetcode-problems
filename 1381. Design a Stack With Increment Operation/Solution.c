typedef struct {
    int *array;  //use an array to store all the elements of stack  
    int top;     //index of the top element in stack
    int maxSize; //maximum number of elements in stack
} CustomStack;

CustomStack* customStackCreate(int maxSize) {
    CustomStack *stack = (CustomStack *)malloc(sizeof(CustomStack));
    stack->top = -1; //Stack is empty. 
    stack->maxSize = maxSize;
    stack->array = (int *)malloc(stack->maxSize * (sizeof(int)));
    return stack;    
}

int isFull(CustomStack *stack) {
    return stack->top == stack->maxSize - 1;
    //Stack is Full when index of the top element is maxSize - 1
}

int isNull(CustomStack *stack) {
    return stack->top == -1;
    //Stack is Null when index of the top element is -1
}

void customStackPush(CustomStack* obj, int x) {
    if(isFull(obj)) {
        return;
    }
    obj->array[++obj->top] = x;
}

int customStackPop(CustomStack* obj) {
    if(isNull(obj)) {
        return -1;
    }
    int topElement = obj->array[obj->top--];
    return topElement;
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    if(isNull(obj)) {
        return;
    }
    if(obj->maxSize < k) {
        for(int i = 0; i < obj->maxSize; i++) {
            obj->array[i] = obj->array[i] + val;
        }
    }
    else {
        for(int i = 0; i < k; i++) {
            obj->array[i] = obj->array[i] + val;
        }
    }
}

void customStackFree(CustomStack* obj) {
    if(obj != NULL) {
        if(obj->array != NULL) {
            free(obj->array);
        }
        free(obj);
    }
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 
 * int param_2 = customStackPop(obj);
 
 * customStackIncrement(obj, k, val);
 
 * customStackFree(obj);
*/
