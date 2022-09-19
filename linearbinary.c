#include<stdio.h>

int linearSearch(int arr[],int size, int element){
    for(int i=0;i<size;i++){
        if(arr[i]==element)
            return i;
    }
}

int binarySearch(int arr[],int size,int element){
    int low=0,high=size-1,mid;
    mid=(low+high)/2;
    while(low<=high){
        if(arr[mid]==element){
            return mid;
        }
        else if(element>arr[mid]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        mid=(low+high)/2;
    }
}

int main(){
    int arr[]={1,4,6,8,99,105,220,560,780,999};
    int size=sizeof(arr)/sizeof(int);
    int res=binarySearch(arr,size,4);
    printf("4 found at %d position",res);
    
    return 0;
}