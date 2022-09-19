#include<stdio.h>
#include<stdlib.h>

struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a,int tSize,int uSize){
//     (*a).total_size=tSize;
//     (*a).used_size=uSize;
//     (*a).ptr=(int *)malloc(tSize*sizeof(int));

    a->total_size=tSize;
    a->used_size=uSize;
    a->ptr=(int *)malloc(tSize*sizeof(int));
}

void showArray(struct myArray *a){
    for(int i=0;i<a->used_size;i++){
        printf("%d ",(a->ptr)[i]);
    }
}

void setArray(struct myArray *a){
    for(int i=0;i<a->used_size;i++){
        printf("Enter %d element: ",i);
        scanf("%d",(a->ptr+i));
    }
}

void insert(struct myArray *a,int num,int index){
    int i=0;
    int j=a->used_size++;
    while((j-i)>index){
        a->ptr[j-i]=a->ptr[j-i-1];
        i++;
    }
    a->ptr[index]=num;
}

void delete(struct myArray *a,int index){
    int i=0;
    int j=a->used_size--;
    while(a->ptr[j-i-1]>index){
        a->ptr[j-i-1]=a->ptr[j-i];
        i++;
    }
}

int main(){
    struct myArray marks;
    createArray(&marks,100,10);
    setArray(&marks);
    showArray(&marks);
    printf("\n");
    insert(&marks,15,3);
    showArray(&marks);
    // printf("\n");
    // delete(&marks,5);
    // showArray(&marks);
    return 0;
}