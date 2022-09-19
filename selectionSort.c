#include<stdio.h>

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n){
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }

}

int main(){
    int a[]={12,54,65,7,23,9};
    int n=6;
    printArray(a,n);
    selectionSort(a,n);
    printArray(a,n);
    return 0;
}