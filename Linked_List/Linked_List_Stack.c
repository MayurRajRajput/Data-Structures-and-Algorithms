#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

int isEmpty(struct Node * top){
if(top==NULL){
return 1;
}
else{
    return 0;
}
}
void linkedlisttraversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("element : %d\n",ptr->data);
        ptr=ptr->next;
    }
}
int isFull(struct Node * top){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    if(n== NULL){
        return 1;
    }else{
        return 0;
    }
}
struct Node *push(struct Node * top,int x){
    if(isFull(top)){
        printf("stack overflow!");
        return 0;
    }else{
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
}
int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("stack underflow!");
        return 0;
    }else{
        struct Node * n = *top;
        *top=(*top)->next;
        int x = n->data;
        free(n);
        return x; 
    }
}
int main() {
    struct Node * top = NULL;
    top=push(top,78);
    top=push(top,7);
    top=push(top,8);
    int element = pop(&top);
    printf("popped element is %d \n",element);
    linkedlisttraversal(top);
    return 0;
}