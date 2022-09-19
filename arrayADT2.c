#include<stdio.h>

//Code for traversal
void display(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
//Code for insertion
int indInsertion(int arr[],int size, int element, int capacity,int index){
    if(size>=capacity)
        return -1;
    for(int i=size;i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
}

int main(){
    int arr[100]={1,2,6,78,99};
    int size=5,element=45,index=3;
    display(arr,size);
    printf("\n");
    indInsertion(arr,size,element,100,index);
    size++;
    display(arr,size);
    return 0;
}