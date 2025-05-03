//Program to perform  circular linked list operations
#include <cstdio>
#include <cstdlib>
class list{
    private:
    struct node {
        int data;
        struct node *next;
    }*head;
    public:
    list(){
        head = NULL;
}
    int insertbeg(int);
    int insertend(int);
    int insertpos(int,int);
    int deletebeg();
    int deleteend();
    int deletepos(int);
    int search(int);
    void display();
    void displayreverse();
    int reverselist();
};

int main(){
    list l1;
    int choice;
    int value;
    int pos;
    int delvalue;
    int target;                                                                                                                                                                                                  
    int result;
    while(1){
        printf("Enter 1 for insertion at beginning\nEnter 2 for insertion at end\nEnter 3 for insertion at position\n");
        printf("Enter 4 for deletion at beginning\nEnter 5 for deletion at end\nEnter 6 for deletion at position\n");
        printf("Enter 7 for search\nEnter 8 for display\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to insert:");
            scanf("%d",&value);
            l1.insertbeg(value);
            l1.display();
            break;
            case 2:
            printf("Enter the value to insert:");
            scanf("%d",&value);
            l1.insertend(value);
            l1.display();
            break;
            case 3:
            printf("Enter the value to insert:");
            scanf("%d",&value);
            printf("Enter the position to insert:");
            scanf("%d",&pos);
            l1.insertpos(value,pos);
            l1.display();
            break;
            case 4:
            delvalue = l1.deletebeg();
            if (delvalue == -1){
                printf("The list is empty\nCannot delete elements\n");
            }
            else{
                printf("The deleted value is :%d\n",delvalue);
            }
            break;
            case 5:
            delvalue = l1.deleteend();
            if (delvalue ==  -1){
                printf("The list is empty\nCannot delete element\n");
            }
            else{
                printf("The deleted value is:%d\n",delvalue);
            }
            break;
            case 6:
            printf("Enter the position to delete:");
            scanf("%d",&pos);
            delvalue = l1.deletepos(pos);
            if (delvalue ==  -1){
                printf("The list is empty\nCannot delete element\n");
            }
            else{
                printf("The deleted value is:%d\n",delvalue);
            }
            break;
            case 7:
            printf("Enter the element to search:");
            scanf("%d",&target);
            result = l1.search(target);
            if (result == -1){
                printf("The element is not found\n");
            }
            else{
                printf("The element was found at position %d\n",result);
            }
            break;
            case 8:
            l1.display();
            break;
            case 9:
           return 0;
           default:
           printf("Enter valid choice\n");
        }
        printf("\n");
        printf("\n");
    }
}
// Member function  to insert at beginning
int list::insertbeg(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node)); 
    struct node *temp = head;
    newnode->data = value;
    if (head == nullptr){
        newnode->next = newnode;
        head = newnode;
        return 1;
    }
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    head = newnode;
    return 1;
}
//Member function  to insert at end
int list::insertend(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    if(head == nullptr){
        newnode->next = head;
        head = newnode;
        head->next = head;
        return 0;
    }
    struct node *temp = head;   
    
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    return 0;
}
//Member function to insert at position
int list::insertpos(int value,int pos){
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    if(pos<=0){
        printf("Enter valid position");
        return -1;
    }
    if(pos==1 ){
       insertbeg(value);
       return 0;
    }
    int i = 1;
    struct node *temp = head;
    while(i!=pos-1 && temp->next!=head){
        temp = temp->next;
        i++;
    }
    if(i<pos-1){
        printf("Enter valid position\n");
        return -1;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return 0;
}
//Member function to delete element at the beginning
int list::deletebeg(){
    int num = head->data;
    if(head == nullptr){
        return -1;
    }
    struct node *deletenode = head;
    if(head->next == head){
        deletenode = head;
        head = nullptr;
        free(nullptr);
    }
    struct node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
    free(deletenode);
    return num;
}
//Member function to delete element at the end
int list::deleteend(){
    int num;
    struct node *deletenode;
    if(head == nullptr){
        return -1;
    }
    if(head->next == head){
        deletenode = head;
        head = head->next;
        num = head->data;
        free(deletenode);
        return num;
    }
    struct node *temp = head;
    while(temp->next->next!=head){
        temp = temp->next;
    }
    
    deletenode = temp->next;
    temp->next = head;
    free(deletenode);
    return 0;
    
}
//Member function to delete element at position
int list::deletepos(int pos){
    if (head == NULL || pos<=0){
        printf("invalid");
        return 0;
    }
    if (pos == 1){
        deletebeg();
        return  1;
    }
    int n = 1;
    struct node *temp = head;
    while(n!=pos-1 && temp->next != head){
        temp = temp->next;
    }
    if (n!=pos-1|| temp->next == head){
        printf("invalid");
        return 0;
    }
    struct node *deletenode = temp->next;
    temp->next = temp->next->next;
    free(deletenode);
    return 1;
}
//Member function for searching
int list::search(int target){
    struct node *temp = head;
    int position=1;
    if(temp->data==target){
        return position;
    }
    temp = temp->next;
    while(temp != head){
        if(temp->data == target){
            return position;
        }
    }
    return -1;
}
//Member function for displaying result
void list::display(){
    struct node *temp = head;
    printf("%d   ",temp->data);
    temp = temp->next;
    while(temp!=head){
        printf("%d   ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
