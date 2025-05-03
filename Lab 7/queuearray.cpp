//Program to implement queue using array
#include <iostream>
class queue{
    private:
    int arr[5];
    int rear;
    int front;
    public:
    queue(){
        rear = -1;
        front = -1; 
    }
    int enqueue(int value);
    int dequeue();
    void peek();
};
int main(){
    queue q1;
    int  choice;
    int value;
    while(1){
        printf("Enter 1 for push\nEnter 2 for pop\nEnter 3 for peek\n");
        printf("Enter 4 to exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to push:");
            scanf("%d",&value);
            q1.enqueue(value);
            break;
            case 2:
            value = q1.dequeue();
            if(value == 0){
                printf("The queue is empty\nCannot pop elements\n");
            }
            else{
                printf("The popped element is %d\n",value);
            }
            break;
            case 3:
            q1.peek();
            break;
            case 4:
            return 0;
            default:
            printf("Enter valid choice\n");
        }
        printf("\n");
        printf("\n");
    }
}
//Function to insert elements into the queue
int queue::enqueue(int value){
    if(rear == 4){
        printf("The queue is full\nCannot insert elements\n");
        return 0;
    }
    rear++;
    arr[rear] = value;
    if (front==-1){
        front++;
    }
    return 1;
}
//Function to delete elements in the queue
int queue::dequeue(){
    if(front == -1 || front>rear){
        printf("The queue is empty\nCannot pop elements\n");
        return 0;
    }
    int value = arr[front++];
    if(front=rear){
        front = -1;
        rear =-1;
    }
    return (value);
}
//Function to display the front element
void queue ::peek(){
    if(front==-1){
        printf("The stack is empty\nCannot display the element\n");
        return;
    }
    printf("The element at the beginning is:%d\n",arr[front]);
}
