#include<stdio.h>
void display(int arr[],int n){
    //traversal
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int sortedinsertion(int arr[],int size,int element,int capacity,int index)
{
    if(size>=capacity){
        return -1;
    }
    for(int i=size-1;i>=index;i--){
        arr[i+1]=arr[i];
        printf("\n %d,%d,%d \n",arr[i],i,index);
    }
    arr[index]=element;
    return 1;
}
void deletion(int arr[],int size,int delete,int capacity){
if(delete>capacity){
    printf("you enter invalid index to delete");

}
for (int i=delete;i<size-1;i++){
arr[i]=arr[i+1];
}
}
int main (){
    int arr[100]={1,2,3,4,5};
    int element =45,index=3;
    int size=5,delete=3;

    display(arr,size);
    sortedinsertion(arr,size,element,100,index);
    size+=1;
    display(arr,size);
    deletion(arr,size,delete,100);
    size-=1;
    display(arr,size);
    return 0;
}