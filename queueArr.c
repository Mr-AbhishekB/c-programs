#include<stdio.h>
#define max 10

int enqueue(int arr[],int rear){
    if(rear==max-1)
        printf("\nQueue Overflow\n");
    else{
        int val;
        printf("\nEnter value to enter: ");
        scanf("%d",&val);
        rear++;
        arr[rear]=val;
    }
    return rear;
}

int dequeue(int arr[],int front){
    if(front==-1)
        printf("\nQueue Underflow\n");
    else{
        printf("\nElement dequeued-%d\n",arr[front]);
        front++;
    }
    return front;
}

void display(int arr[],int front,int rear){
    if(front==-1)
        printf("\nQueue is empty cannot display\n");
    else{
        printf("\nElements in queue from front to rear are-\n");
        for(int i=front;i<=rear;i++){
            printf("%d\n",arr[i]);
        }
        printf("\n");
    }
}

int main(){
    int front= -1;
    int rear=-1;
    int ch,arr[max];
    do{
        printf("Enter 1 to enqueue\nEnter 2 to dequeue\nEnter 3 to display\nEnter 4 to exit\n");
        scanf("%d",&ch);
        if(ch==1){
            rear=enqueue(arr,rear);
            if(rear==0)
                front=0;
        }
        if(ch==2)
            front=dequeue(arr,front);
        if(ch==3){
            display(arr,front,rear);
            
        }    
        if(front>rear){
            front=-1;
            rear=-1;
        }
    }while(ch!=4);
    return 0;
}