//Program to perform round robin scheduling algorithm
#include "roundrobinalgo.h"
 int main(){
    list l1;
    int limit;
    printf("Enter the time limit:");
    scanf("%d",&limit);
    l1.setter(limit);
    int choice;
    int value;
    while(1){
        printf("Enter 1 for insertion\nEnter 2 to execute\nEnter 3 for exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the time for the process:");
            scanf("%d",&value);
            l1.insert(value);
            l1.display();
            break;
            case 2:
            l1.execute();
            break;
            case 3:
            return 0;
            default:
            printf("Enter valid choice\n");
        }
    }
 }
 //Function to set limit value
void list::setter(int timelimit){
    limit = timelimit;
    return;
}
 //Function to insert process
int list :: insert(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = nullptr;
    if (head == nullptr){
        head = newnode;
        return 1;
    }
    struct node *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newnode;
    return 1;
}
//Function to execute
int list:: execute(){
    struct node *temp = head;
    while(head!= nullptr){
        if((head->data) > limit){
            (head-> data) = (head->data) - limit;
            insert(head->data);
            printf("The remaining time for the process is %d\n",head->data);
            temp = head;
            if(head != nullptr){
                head = head->next;
            }
            free(temp);
        }
        
        else{
            temp = head;
            if(head != nullptr){   
            head = head->next;
            }
            printf("The process is completed\n");
            free(temp);
        }
    }
    if(head == nullptr){
        printf("Succesful!!!\n");
    }
    return 0;
}
//Function to display 
void list::display(){
    struct node *temp = head;
    while(temp!=nullptr){
        printf("%d   ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
