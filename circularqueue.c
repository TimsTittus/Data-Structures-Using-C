#include<stdio.h>
#include<stdlib.h>

int main() {
int size,front=-1,rear=-1,opt,value;
printf("Enter the size of the queue : ");
scanf("%d",&size);
int crqueue[size];
while(1) {
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    printf("Enter the option : ");
    scanf("%d",&opt);
    
    switch(opt){
        case 1:
            if(front==-1 && rear==-1) {
                front=rear=0;
                printf("Enter element : ");
                scanf("%d",&value);
                crqueue[rear]=value;
            }
            else if(front==(rear+1)%size) {
                printf("Overflow");
            }
            else {
                rear=(rear+1)%size;
                printf("Enter a element : ");
                scanf("%d",&value);
                crqueue[rear]=value;
            }
            break;
        case 2:
            if(front==-1 && rear==-1){
                printf("underflow");
            }
            else {
                int data = crqueue[front];
                if(front==rear) {
                    front=rear=-1;
                }
            else {
                front=(front+1)%size;
            }
            printf("%d dequeued",data);
            }
            break;
            
        case 3:
            int i=front;
            while(1) {
                printf("%d",crqueue[i]);
                if(i==rear)
                    break;
                i=(i+1)%size;
            }
        printf("\n");
        break;
        case 4:
            printf("Exiting...");
            exit(0);
        default:
            printf("Invalid input");
        }
    }
}