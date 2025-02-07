#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int * arr;
};
int isFull(struct stack * ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }else{
        return 0;
    }
}
int isEmpty(struct stack * ptr){
    if(ptr->top==-1){
        return 1;
    }else{
        return 0;
    }
}
int push(struct stack * ptr,int val){
if(isFull(ptr)){
printf("stack overflow! Cannot push %d to the stack\n",val);
return 0;
}else{
    ptr->top++;
    ptr->arr[ptr->top]=val;
}
}
int pop(struct stack * ptr){
if(isEmpty(ptr)){
    printf("stack underflow!");
    return -1;
}else
{
    int val = ptr->arr[ptr->top];
    ptr->top=ptr->top-1;
    return val;

}
}
int peek(struct stack * sp,int i){
    if(sp->top-i+1< 0){
        printf("not a valid position");
        return -1;
    }else{
        return sp->arr[sp->top-i+1];
    }

}
int main() {
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size*sizeof(int));
    printf("Stack has been successfully created \n");
    printf("Before pushing ,Full:%d\n",isFull(sp));
    printf("Before pushing ,Empty:%d\n",isEmpty(sp));
    push(sp,10);
    push(sp,9);
    push(sp,8);
    push(sp,7);
    push(sp,6);
    push(sp,5);
    push(sp,4);
    push(sp,3);
    push(sp,2);
    push(sp,1);
    
    printf("After pushing ,Full:%d\n",isFull(sp));
    printf("After pushing ,Empty:%d\n",isEmpty(sp));
    printf("popped %d from the stack \n",pop(sp));
    printf("peek %d from the stack \n",peek(sp,2));
   


    return 0;
}