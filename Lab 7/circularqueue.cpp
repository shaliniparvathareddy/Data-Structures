//Program to implement circular queue using array
#include <cstdio>
class queue{
    private:
    int arr[5];
    int front;
    int rear;
    int currsize;
    public:
    queue(){
        front = 0;
        rear = -1;
        currsize = 0;
    }
    int enqueue(int);
    int dequeue();
    int peek();
};
int main(){
    queue q1;
    int choice;
    int value;
    while (1){
        printf("Enter 1 for push\nEnter 2 for pop\nEnter 3 for peek\n");
        printf("Enter 4 for exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to push:");
            scanf("%d",&value);
            value = q1.enqueue(value);
            if (value == 0){
                printf("The queue is empty\nCannot insert elements\n");
            }
            break;
            case 2:
            value = q1.dequeue();
            if (value == 0){
                printf("The queue is empty\nCannot dequeue\n");
            }
            else{
                printf("The element deleted is %d\n",value);
            }
            break;
            case 3:
            value = q1.peek();
            if (value==0){
                printf("The list is empty\n");
            }
            else{
                printf("The element at the top is %d\n",value);
            }
            break;
            case 4:
            return 0;
            default:
            printf("Enter valid option\n");
        }
        printf("\n");
        printf("\n");
    }

}
//Function to insert elements in the circular queue
int queue::enqueue(int value){
    if (currsize == 5){
        return 0;
    }
    rear=(rear+1)%5;
    arr[rear] = value;
    currsize++;
    return 1;
}
//Function to delete elements in the circular queue
int queue::dequeue(){
    if(currsize==0){
        return 0;
    }
    int value = arr[front];
    front = (front+1)%5;
    currsize--;
    return value;
}
//Function to display front element     
int  queue::peek(){
    if (currsize == 0){
        return 0;
    }
    return arr[front];
}
