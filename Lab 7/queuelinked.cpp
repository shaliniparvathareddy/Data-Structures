//Program to implement queue using singly linked list
#include <cstdio>
#include <cstdlib>
class queue{
    private:
    struct node{
        int data;
        struct node *next;
    }*head;//*tail;
    public:
    queue(){
        head = nullptr;
        //tail = nullptr;s
    }
    int enqueue(int);
    int dequeue();
    void peek();
    void display();
};
int main(){
    queue q1;
    int choice;
    int value;
    while(1){
        printf("Enter 1 for push\nEnter 2 for pop\nEnter 3 for peek\n");
        printf("Enter 4 for exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to be enqueued:");
            scanf("%d",&value);
            q1.enqueue(value);
            break;
            case 2:
            value = q1.dequeue();
            if (value == 0){
                printf("The elements cannot be dequeued\n");
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
    }
}
//Function to insert elements in the queue
int queue::enqueue(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next = nullptr;
    if(head == nullptr){
        head = newnode;
        // tail = newnode;
        return 1;
    }
    struct node *temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = newnode;
    /*for doing using tail pointer*/
    // tail->next = newnode;
    // tail = newnode;
    return 1;
}
//Function to delete elements in the queue
int queue::dequeue(){
    if (head == nullptr){
        printf("The queue is empty\nCannot delete elements\n");
        return 0;
    }
    struct node*delnode = head;
    int value = head->data;
    head = head->next;
    /*for doing it using tail pointer*/
    // if(head == nullptr){
    //     tail = nullptr;
    // }
    free(delnode);
    return value;
}
//Function to display the front element
void queue::peek(){
    if(head == nullptr){
        printf("The queue is empty\nCannot display elements\n");
        return;
    }
    printf("The element at the begging is :%d\n",head->data);
}
void queue::display(){
    struct node *temp = head;
    while(temp!=nullptr){
        printf("%d   ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}-
