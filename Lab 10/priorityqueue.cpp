//Program to implement priority queue using max heap
#include <cstdio>
#include<iostream>
#include <algorithm>
using namespace std;
#define maxsize 100
class priorqueue{
    private:
    int arr[maxsize];
    int front;
    int rear;
    public:
    priorqueue(){
        front = 0;
        rear = -1;
    }
    int insert(int);
    int delete1();
    void display();
    int search(int);
    void sort();
};
int main(){
    int choice;
    priorqueue p1;
    int value;
    int result;
    while(1){
        printf("Enter 1 for insertion\nEnter 2 for deletion\nEnter 3 for display\n");
        printf("Enter 4 for search\nEnter 5 for sort\n");
        printf("Enter 6 for exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to insert:");
            scanf("%d",&value);
            p1.insert(value);
            break;
            case 2:
            value = p1.delete1();
            if (value == -1){
                printf("Cannot delete elements\nQueue is empty\n");
            }
            else{
                printf("The deleted element is %d\n",value);
            }
            break;
            case 3:
            p1.display();
            break;
            case 4:
            printf("Enter the value to search:");
            scanf("%d",&value);
            result = p1.search(value);
            if (result == -1){
                printf("The element is not found in the Queue\n");
            }

            else{
                printf("The element is found in the Queue\n");
            }
            break;
            case 5:
            p1.sort();
            break;
            case 6:
            return 0;
            default:
            printf("Enter valid choice\n");
        }
        printf("\n");
        printf("\n");
    }
}
//Function to insert element
int priorqueue::insert(int value){
    if(rear == maxsize-1){
        printf("Cannot insert elements\nQueue is full\n");
        return -1;
    }
    rear++;
    arr[rear] = value;
    int curr = rear;
    int parent = (curr - 1)/2;
    while(curr>0 && arr[curr]>arr[parent]){
        int temp = arr[curr];
        arr[curr] = arr[parent];
        arr[parent] = temp;
        curr = parent;
        parent = (curr -1)/2;
    }
    return 0;
}
//Function to delete elements
int priorqueue::delete1(){
    if(rear == -1){
        return -1;
    }
    int value = arr[front];
    arr[front] = arr[rear--];
    int curr = front;
    while(true){
        int left = 2*curr+1;
        int right = 2*curr +2;
        int max1 = curr;
        if(left<=rear && arr[left]>arr[max1]){
            max1 = left;
        }
        if(right <= rear && arr[right]>arr[max1]){
            max1 = right;
        }
        if(curr == max1){
            break;
        }
        
        int temp = arr[max1];
        arr[max1] = arr[curr];
        arr[curr] = temp;
        curr = max1;
    }
    return value;
}
//Function to display
void priorqueue::display(){
    if(rear==-1){
        printf("Cannot display elements\nQueue is empty\n");
        return;
    }
    for(int i =0;i<=rear;i++){
        printf("%d   ",arr[i]);
    }
    printf("\n");
}
//Function to search
int priorqueue::search(int value){
    if(rear == -1){
        printf("Queue is empty\n");
        return 0;
    }
    for(int i=0;i<=rear;i++){
        if(arr[i] == value){
            return 1;
        }
    }
    return -1;
}
//Function to sort
void priorqueue::sort(){
    int arr2[rear+1];
    int i = 0;
    while(rear!=-1){
        arr2[i] = delete1();
        i++;
    }
    for(int j=0;j<i;j++){
        rear++;
        arr[rear]=arr2[j];
    }
}
