#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void linkedlisttraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element:%d\n",ptr->data);
        ptr=ptr->next;
    }
    
}

//Case 1: deleting First Node  
struct Node * DeletionFirst(struct Node *head){
struct Node *ptr=head;
head = head->next;
free(ptr);
return head;
}

//Case 2 : deleting a node inbetween
struct Node * DeletionAtIndex(struct Node *head,int index){
    // method 1:
    // struct Node *p= head;
    // // int i =0;
    // // while(i!=index-1){
    // //     p=p->next;
    // //     i++;
    // // }
    // // struct Node * q = p->next;
    // // p->next=q->next;
    // // free(q);
    // // return head;

    // method 2:
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    
    }
    p->next=q->next;
    free(q);
    return head;
} 

struct Node * DeletionAtEnd(struct Node *head){
    struct Node *p=head;
    struct Node *q =head->next;
    while(q->next !=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
struct Node * DeletionWithValue(struct Node *head,int Value){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->data!=Value && q->next != NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data == Value){
    p->next=q->next;
    free(q);
    }
    return head;
}


int main() {
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data=4;
    head->next = second;
    second->data = 3;
    second ->next = third;
    third->data = 8;
    third->next = fourth;
    fourth -> data = 1;
    fourth->next = NULL;
    printf("Linked List Before Deletion\n");
    linkedlisttraversal(head);
    //head = DeletionFirst(head);
    // head = DeletionAtIndex(head,2);
    // head = DeletionAtEnd(head);
    head = DeletionWithValue(head,3);
    printf("\nLinked List After Deletion\n");
    linkedlisttraversal(head);

    return 0;
}