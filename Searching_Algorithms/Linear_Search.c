#include <stdio.h>
int main()
{
 int a[20],i,n,elem,pos;
 pos=-1;
 printf("enter the size of array: ");
 scanf("%d",&n);
 printf("enter the element of array: ");
 for(i=0;i<n;i++){
 scanf("%d",&a[i]);
 }
 printf("enter the element to be search: ");
 scanf("%d",&elem);
 for(i=0;i<n;i++){
    if(a[i]==elem){
        printf("element %d is found at %d",elem,i);
        pos=i;
        break;
    }
 }
 if(pos==-1){
    printf("element is not found");
 }
 return 0;
}