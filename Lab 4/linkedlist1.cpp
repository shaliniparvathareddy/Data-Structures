//Program to perform linked list operation
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
        printf("Enter 7 for search\nEnter 8 for display\nEnter 9 for display reverse\n");
        printf("Enter 10 for reverse link\nEnter 11 for exit\nEnter your choice:");
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
            // l1.display();
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
            l1.displayreverse();
            break;
            case 10:
            l1.reverselist();
            break;
            case 11:
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
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    return 1;
}
//Member function  to insert at end
int list::insertend(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    if(head == nullptr){
        newnode->next = nullptr;
        head = newnode;
        return 0;
    }
    struct node *temp = head;
    while( temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newnode;
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
    if(pos==1){
        newnode->next = head;
        head = newnode;
        return 0;
    }
    int i = 1;
    struct node *temp = head;
    while(i!=pos-1 && temp!=nullptr){
        temp = temp->next;

        i++;
    }
    if(i<pos-1){
        printf("Enter valid position");
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
    head = head->next;
    free(deletenode);
    return num;
}
//Member function to delete element at the end
int list::deleteend(){
    int num ;
    struct node *deletenode;
    if(head == nullptr){
        return -1;
    }
    if(head->next == nullptr){
        deletenode = head;
        head = head->next;
        num = head->data;
        free(deletenode);
        return num;
    }
    struct node *temp = head;
    // if(head->next == head){
    //     head = nullptr;
    // }
    while(temp->next->next!=nullptr){
        temp = temp->next;
    }
    deletenode = temp->next;
    num = temp->next->data;
    temp->next = head;
    printf("%d\n",temp->next->data);
    free(deletenode);
    return num;
    
}
//Member function to delete element at position
int list::deletepos(int pos){
    if (head == NULL || pos<=0){
        printf("invalid");
        return 0;
    }
    if (pos == 1){
        struct node *delete1 = head;
        head = head->next;
        free(delete1);
        return  1;
    }










    
    int n = 1;
    struct node *temp = head;                                                                                           
    while(n!=pos-1 && temp != NULL){
        temp = temp->next;
    }
    if (temp->next == NULL || temp == nullptr){
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
    int position=0;
    while(temp != nullptr){
        if(temp->data == target){
            position++;
            return position;
        }
    }
    return -1;
}
//Member function for displaying result
void list::display(){
    struct node *temp = head;
    while(temp!=nullptr){
        printf("%d   ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
//function to display list in reverse order
void list::displayreverse(){
    struct node *temp = head;
    int count =0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    for(int i = count;i>0;i--){
        temp = head;
        int j=i-1;
        while( j>0){
            temp = temp->next;
            j--;
        }
        printf("%d\n",temp->data);
    }
}
//Member function to reverse linked list
int list::reverselist(){
    if (head == nullptr || head->next == nullptr){
        return 0;
    }
    struct node *next1 = NULL;
    struct node *current = head;
    struct node *prev = NULL;
    while(current != NULL){
        next1 = current->next;
        current->next = prev;
        prev = current;
        current = next1;
    }
    head = prev;
    return 1;
}
