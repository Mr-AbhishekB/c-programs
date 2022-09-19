#include<stdio.h>
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int k=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                k=1;
            }
        }
        if(k==0)
            return;
    }
}

int main(){
    int a[]={12,54,65,7,23,9};
    int n=6;
    printArray(a,n);  
    bubbleSort(a,n); 
    printArray(a,n);  
    return 0;
}