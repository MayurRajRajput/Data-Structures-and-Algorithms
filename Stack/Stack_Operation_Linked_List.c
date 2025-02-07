#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
struct Node * top = NULL;
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
int pop(struct Node* tp){
    if(isEmpty(tp)){
        printf("stack underflow!");
        return 0;
    }else{
        struct Node * n = tp;
        top=(tp)->next;
        int x = n->data;
        free(n);
        return x; 
    }
}
int peek(int pos){
    struct Node * ptr = top;
    for(int i=0;(i<pos-1 && ptr!=NULL);i++){
        ptr =ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;

    }else{
        return -1;
    }
}
int main() {
    
    top=push(top,28);
    top=push(top,18);
    top=push(top,15);
    top=push(top,7);
    // int element = pop(top);
    // printf("popped element is %d \n",element);

    linkedlisttraversal(top);
    int i=1;
    while(peek(i)!=-1){
    printf("value at position %d is %d\n",i,peek(i));
    i++;
    }
    return 0;
    }
