#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void linkedlisttraversal(struct Node *head){
    struct Node * ptr = head;
    // printf("Element:%d \n",ptr->data);
    // ptr =ptr->next;
    // while(ptr!=head){
    //     printf("Element:%d \n",ptr->data);
    //     ptr =ptr->next;
    // }
    do{
      printf("Element:%d \n",ptr->data);
    ptr =ptr->next;  
    }while(ptr!=head);
}

struct Node * InsertAtFirst(struct Node * head,int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data =data;
    struct Node * p = head->next;
    while(p->next !=head){
        p=p->next;
    }
    //at this point p points to the last node of this circular linked list 
    p->next = ptr;
    ptr->next=head;
    head=ptr;
    return head;
}
int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head = (struct  Node *)malloc(sizeof(struct Node));
    second = (struct  Node *)malloc(sizeof(struct Node));
    third = (struct  Node *)malloc(sizeof(struct Node));
    fourth = (struct  Node *)malloc(sizeof(struct Node));
    head->data=4;
    head->next = second;
    second->data=3;
    second->next = third;
    third->data=6;
    third->next = fourth;
    fourth->data=1;
    fourth->next = head; 
    printf("linked list before insertion\n");
    linkedlisttraversal(head);
    head = InsertAtFirst(head,80);
    printf("\nlinked list after insertion \n");
    linkedlisttraversal(head);
    return 0;
}