#include<stdio.h>

void delete(int arr[],int n,int size){
    for(int i=n;i<size-1;i++){
        arr[i]=arr[i+1];
    }
}

void display(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[100]={1,3,5,6,77,89};
    delete(arr,1,6);
    display(arr,5);
    return 0;
}