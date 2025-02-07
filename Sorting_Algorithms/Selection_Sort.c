#include<stdio.h>
void printArray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
void selectionsort(int *A,int n){
    int IndexOfMin,temp;
    printf("running selection array...\n");
    for(int i=0;i<n-1;i++){
        IndexOfMin=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[IndexOfMin]){
                IndexOfMin=j;
            }
        }
        temp = A[i];
        A[i]=A[IndexOfMin];
        A[IndexOfMin]=temp;

        }
    }

int main() {
    int A[]={3,5,2,13,12};
    int n=5;
    printArray(A,n);
    selectionsort(A,n);
    printArray(A,n);
    return 0;
}