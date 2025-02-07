#include<stdio.h>
#include<stdlib.h>
struct Node *f=NULL;
struct Node *r=NULL;
struct Node{
    int data;
    struct Node * next;
};

int isEmpty(){
    if(f==NULL)
    return 1;
    return 0;
}
int isFull(){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    if(n==NULL)
    return 1;
    return 0;
}
int enqueue(int val){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    if(isFull()){
        printf("queue is full\n");
        return -1;
    }else{
        n->data = val; 
        n->next=NULL;
        if(f==NULL){
            f=r=n;
        }else{
        r->next=n;
        r=n;
        }

    }
}

void linkedlisttraversal(){
    struct Node * ptr = f;
while (ptr!=NULL){
    printf("Element: %d \n",ptr->data);
    ptr=ptr->next;
}
}
int dequeue(){
    int val = -1;
    struct Node * ptr = f; 
    if(isEmpty()){
        printf("queue is empty\n");
        return -1;
    }else{
        f=f->next;
        val=ptr->data;
        free(ptr);
        return val;
    }
}
int main() {
    printf("remove element %d \n",dequeue());
    printf("adding enqueue\n");
    enqueue(34);
    enqueue(4);
    enqueue(7);
    linkedlisttraversal();
    printf("remove element %d \n",dequeue());
    printf("remove element %d \n",dequeue());
    printf("remove element %d \n",dequeue());
    printf("remove element %d \n",dequeue());
    printf("after enqueue\n");
    linkedlisttraversal();


    return 0;
}