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
int StackTop(struct stack * sp){
    return sp->arr[sp->top];
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
int prec(char ch){
    if(ch=='*'||ch=='/'){
        return 3;
    }else if(ch=='+'||ch=='-')
    {
        return 2;
    }else{
        return 0;
    }
}
int isOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        return 1;
    else
        return 0;
}
char * InfixToPostfix(char *infix){
struct stack * sp=(struct stack *)malloc(sizeof(struct stack));
sp->size=45;
sp->top=-1;
sp->arr=(char *)malloc(sp->size*sizeof(char));
char * postfix =(char *)malloc((strlen(infix)+1)*sizeof(char));
int i=0;//track infix traversal
int j=0;//track postfix addition
while(infix[i]!='\0')
{
    if(!isOperator(infix[i])){
        postfix[j]=infix[i];
        i++;
        j++;

    }else{
        if(prec(infix[i])>prec(StackTop(sp))){
            push(sp,infix[i]);
            i++;
        }else{
            postfix[j]=pop(sp);
            j++;
        }
    }
}
    while(!isEmpty(sp)){
        postfix[j]=pop(sp);
            j++;    
        }
        postfix[j]='\0';
        return postfix;


}
int main() {
    char * exp= "x-y/z-k*d";
   printf("postfix is %s ",InfixToPostfix(exp));
    return 0;
}