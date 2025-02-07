#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;

};
int isFull(struct queue * q){
    if(q->r==q->size)
        return 1;
    return 0;
}
int isEmpty(struct queue * q){
    if(q->r==q->f)
        return 1;
    return 0;
}
int enqueue(struct queue * q,int val){
    if(isFull(q)){
        printf("this queue is full");
        return 0;
    }else{
        q->r=q->r+1;
        q->arr[q->r]=val;
    }
}
int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("no element to dequeue");
        return 0;
    }else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
    }
int queuetraversal(struct queue * q){
    if(isEmpty(q)){
        printf("it is empty\n");
        return 0;
    }
    printf("queue elements are:\n");
    for(int i=q->f+1;i<=q->r;i++){
        printf("%d \n",q->arr[i]);
    }
}
int main() {
    struct queue q;
    q.size= 100;
    q.f= q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));
    enqueue(&q,3);
    enqueue(&q,2);
    enqueue(&q,1);
    queuetraversal(&q);
    dequeue(&q);
    dequeue(&q);
    queuetraversal(&q);
        return 0;
}