#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * prev;
    struct Node * next;

};
void linkedlisttraversal(struct Node * head){
    struct Node * ptr =head;

    while (ptr!=NULL)
    {
        printf("forward traversal");
        printf("Element:%d \n",ptr->data);
        if (ptr->next == NULL) { 
            break;
        }
        ptr=ptr->next;
    }
    while (ptr!=NULL)
    {
         printf("backward traversal");
        printf("Element:%d \n",ptr->data);
        ptr=ptr->prev;
    }

}
int main() {
    struct Node *N1;
    struct Node *N2;
    struct Node *N3;
    struct Node *N4;
    N1 = (struct  Node *)malloc(sizeof(struct Node));
    N2 = (struct  Node *)malloc(sizeof(struct Node));
    N3 = (struct  Node *)malloc(sizeof(struct Node));
    N4 = (struct  Node *)malloc(sizeof(struct Node));
    N1->prev = NULL;
    N1->data=7;
    N1->next = N2;
    N2->prev = N1;
    N2->data=11;
    N2->next = N3;
    N3->prev = N2;
    N3->data=41;
    N3->next = N4;
    N4->prev = N3;
    N4->data=66;
    N4->next = NULL;
    linkedlisttraversal(N1);
    return 0;
}