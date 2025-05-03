//Stack implementation using linked list
#include<cstdio>
#include<cstdlib>
class stack{
    private:
    struct node{
        char data;
        struct node* next;
    }*head;
    public:
    stack(){
        head = nullptr;
    }
    int push(char);
    char pop();
    void peek();
};
int main(){
    stack s1;
    int choice;
    char value;
    while(1){
        printf("Enter 1 for push\nEnter 2 for pop\nEnter 3 for peek\n");
        printf("Enter 4 for exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to insert:");
            scanf(" %c",&value);
            s1.push(value);
            break;
            case 2:
            value = s1.pop();
            if(value == -1){
                printf("The stack is empty\nCannot delete elements\n");
            }
            else{
                printf("The deleted element is:%c\n",value);
            }
            break;
            case 3:
            s1.peek();
            break;
            case 4:
            return 0;
            default:
            printf("Enter valid choice\n");
        }
        printf("\n");
    }
    return 0;
}
//Function to push elements
int stack::push(char value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    return 1;
}
//Function to pop elements
char stack::pop(){
    if(head == nullptr){
        return -1;
    }
    struct node *delnode;
    delnode = head;
    char value = head->data;
    head = head->next;
    free(delnode);
    return value;
}
//Function to print last inserted element
void stack::peek(){
    if(head == nullptr){
        printf("The stack is empty\n");
        return;
    }
    printf("The last inserted element is:%c\n",head->data);
}
