#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int isempty(struct stack *top){
    if(top->top == -1){
        return 1;
    }
    return 0;
}
int isfull(struct stack *p){
    if(p->top == p->size-1){
        return 1;
    }
    return 0;
}
void push(struct stack *p, int data){
    if(isfull(p)){
        printf("Stack is overflow");
        return;
    }
    p->top++;
    p->arr[p->top] = data;
    printf("%d pushed into stack",data);
}
int pop(struct stack *p){
    if(isempty(p)){
        printf("Stack is underflow");
        return -1;
    }
    int temp = p->arr[p->top];
    p->top--;
    return temp;
}
int peek(struct stack *p, int i){
    if(p->top-i+1 < 0){
        printf("Invalid input");
        return -1;
    }
    else{
        return p->arr[p->top-i+1];
    }
}
int stackbottom(struct stack*p){
    return p->arr[0];
}
int stacktop(struct stack *p){
    return p->arr[p->top];
}
int main(){
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));
    push(s,8);
    push(s,7);
    push(s,9);
    for(int i = 1; i <= s->top+1; i++)
        printf("\nValue at position %d = %d\n",i,peek(s,i));
    printf("%d\n",stackbottom(s));
    printf("%d",stacktop(s));
    
    return 0;
}