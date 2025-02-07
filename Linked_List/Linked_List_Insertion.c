#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * next;

};
void linkedlisttraversal(struct Node * ptr){
    while(ptr != NULL){
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;
    }
}

//Case:1

struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    
    ptr->next = head;
    ptr->data=data;
    return ptr;

}

//Case:2

struct Node * insertAtIndex(struct Node *head, int data,int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p=head;
    int i = 0;
    while(i!=index-1){
       p=p->next;
       i++; 
    }
    ptr->next=p->next;
    p->next =ptr;
    ptr->data = data;
    return head;

}

//Case:3

struct Node * insertAtEnd(struct Node *head,int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node * p = head;
        
        while(p->next!=NULL){
          p = p->next;
        }
        p->next=ptr;
        ptr->next=NULL;
        ptr->data = data;
        return head;
    
};

//Case:4

struct Node * insertAfterNode(struct Node *head ,struct Node *PrevNode,int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node * p = head;
        ptr->next=PrevNode->next;
        PrevNode->next= ptr;

        ptr->data = data;
        return head;
    
};


int main() {
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    head -> data = 7;
    head->next = second;
    second-> data = 11;
    second->next = third;
    third -> data = 41;
    third->next = fourth;
    fourth -> data = 66;
    fourth->next = NULL;
    printf("Linked List Before Insertion\n");
    linkedlisttraversal(head);
    printf("\nLinked List after Insertion\n");
    //head = insertAtFirst(head,50);
    //head = insertAtIndex(head,56,1);
    //head = insertAtEnd(head,50);
    head = insertAfterNode(head,third,45);
    
    linkedlisttraversal(head);
    
    return 0;


}