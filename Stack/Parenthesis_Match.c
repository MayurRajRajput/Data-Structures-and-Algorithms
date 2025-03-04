#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
int size;
int top;
char *arr;
};
int isEmpty(struct stack * ptr){
    if(ptr->top==-1){
        return 1;
    }else{
        return 0;
    }
}
int isFull(struct stack* ptr){
    if(ptr->top==ptr->size){
        return 1;
    }else{
        return 0;
    }
}
char push(struct stack * ptr,char val){
    if(isFull(ptr)){
        printf("stack overflow!");
        return 0;
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
char pop(struct stack *  ptr){
    if(isEmpty(ptr)){
        printf("stack underflow!");
        return 0;
    }else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int parenthesisMatch(char *exp,int explen){
    struct stack * sp;
    sp->size=explen;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));
    for(int i =0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(sp,exp[i]);
        }else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
      }  
    if(isEmpty(sp)){
        return 1;
    }else{
        return 0;
    }
    
}
int main() {
    char * exp= "*8*(9)";
    int explen=strlen(exp);
    if(parenthesisMatch(exp,explen)){
        printf("the parenthesis is matching");
    }else{
        printf("the parenthesis is not matching");
    }
    return 0;
}