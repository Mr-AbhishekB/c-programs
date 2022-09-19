//Stack
#include<stdio.h>
#define max 50

int push(int arr[],int top){
    int val;
    printf("Enter value to add to stack: ");
    scanf("%d",&val);
    if(top==max-1)
        printf("Stack overflow\n");
    else{
        top++;
        arr[top]=val;
    }
    return top;
}

int pop(int arr[],int top){
    if(top==-1)
        printf("Stack underflow\n");
    else{
        printf("Popped value is %d\n",arr[top]);
        top--;
    }
    return top;
}

void display(int arr[],int top){
    for(int i=top;i>-1;i--){
        printf("%d\n",arr[i]);
    }
    printf("\n");
}
int main(){
    int top=-1,ch;
    int arr[max];

    do{
        printf("Enter 1 to push\nEnter 2 to pop\nEnter 3 to display\nEnter 4 to exit\n");
        scanf("%d",&ch);
        
        switch(ch){
            case 1: top=push(arr,top);
            break;

            case 2: top=pop(arr,top);
            break;

            case 3: display(arr,top);
            break;
            
            case 4: return 0;
        }

    }while(ch>0);
    return 0;
}