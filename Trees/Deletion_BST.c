#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    
}
int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;

    n->left = NULL;
    n->right = NULL;
    return n;
}
void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("cannot insert %d ,already in bst", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {

            root = root->right;
        }
    }
    struct node *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
struct node *searchIter(struct node *root, int key)
{
    while (root != NULL)
    {

        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}
struct node * inorderPredecesssor(struct node *root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}
struct node * DeleteNode(struct node * root,int value){
    struct node *iPre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root ->right ==NULL){
        free(root);
        return NULL;
    }
    
    //search for the node to be deleted
    if(value < root->data){
        root->left = DeleteNode(root->left,value);

    }else if(value >root->data){
        root->right = DeleteNode(root->right,value);
    }
    //deletion strategy when node is found
    else{
        iPre =inorderPredecesssor(root);
        root->data = iPre->data;
        root->left = DeleteNode(root->left,iPre->data);

    }
    return root;

}
int main()
{
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

   inorder(p);
   printf("\n");
   printf("%d",inorderPredecesssor(p)->data);
   DeleteNode(p,5);
   printf("\n");
   inorder(p);
    return 0;
}