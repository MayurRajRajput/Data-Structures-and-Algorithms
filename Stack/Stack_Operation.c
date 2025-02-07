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
int main() {
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size*sizeof(int));
    printf("Stack has been successfully created \n");
    printf("Before pushing ,Full:%d\n",isFull(sp));
    printf("Before pushing ,Empty:%d\n",isEmpty(sp));
    push(sp,1);
    push(sp,56);
    push(sp,56);
    push(sp,56);
    push(sp,56);
    push(sp,56);
    push(sp,56);
    push(sp,56);
    push(sp,56);
    push(sp,56);
    
    printf("After pushing ,Full:%d\n",isFull(sp));
    printf("After pushing ,Empty:%d\n",isEmpty(sp));
    printf("popped %d from the stack \n",pop(sp));
   


    return 0;
}