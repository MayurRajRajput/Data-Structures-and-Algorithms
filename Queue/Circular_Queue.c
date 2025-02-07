#include<stdio.h>
#include<stdlib.h>
struct cqueue{
    int size;
    int f;
    int r;
    int *arr;

};
int isFull(struct cqueue * q){
    if((q->r+1)%q->size==q->f)
        return 1;
    return 0;
}
int isEmpty(struct cqueue * q){
    if(q->r==q->f)
        return 1;
    return 0;
}
int enqueue(struct cqueue * q,int val){
    if(isFull(q)){
        printf("this cqueue is full");
        return 0;
    }else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
    }
}
int dequeue(struct cqueue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("no element to decqueue");
        return 0;
    }else{
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
    }
    return a;
    }
int cqueuetraversal(struct cqueue * q){
    if(isEmpty(q)){
        printf("it is empty\n");
        return 0;
    }
    printf("cqueue elements are:\n");
    int i = (q->f+1)%q->size;
    while(i!=(q->r+1)%q->size){
        printf("%d\n",q->arr[i]);
        i=(i+1)%q->size;
    }
   
}
int main() {
    struct cqueue q;
    q.size= 4;
    q.f= q.r = 0;
    q.arr = (int*)malloc(q.size*sizeof(int));
    enqueue(&q,3);
    enqueue(&q,2);
    enqueue(&q,1);
    cqueuetraversal(&q);
    dequeue(&q);
    dequeue(&q);
    cqueuetraversal(&q);
    enqueue(&q,2);
    enqueue(&q,1);
    cqueuetraversal(&q);
        return 0;
}