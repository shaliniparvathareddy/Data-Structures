//Program for performing doubly linked lists functions
#include <cstdio>
#include <cstdlib>
class list{
    private:
    struct node{
        struct node *prev;
        int data;
        struct node *next;
    }*head,*tail;
    public:
    list(){
        head = nullptr;
        tail = nullptr;
    }
    int insertbeg(int);
    int insertend(int);
    int insertpos(int,int);
    int deletebeg();
    int deleteend();
    int deletepos(int);
    int search(int);
    void display();
};
int main(){
    list l1;
    int value;
    l1.insertbeg(4);
    // l1.insertbeg(8);
    // l1.insertbeg(12);
    // l1.insertend(1);
    // l1.insertend(2);
    // l1.insertend(3);
    // l1.insertpos(7,7);
    // l1.insertpos(5,33);
    // l1.insertpos(1,6);
    l1.display();
    // value = l1.deletebeg();
    // printf("%d\n",value);
    // value = l1.deleteend();
    // printf("%d\n",value);
    // // value = l1.deletepos();
    // // printf("%d\n",value);
    value = l1.deletepos(1);
    printf("%d\n",value);
    // l1.display();
    // value = l1.search(8);
    // if (value != 0){
    //     printf("The value is found at %d position\n",value);
    // }
    // else{
    //     printf("Not found\n");
    // }
    return 0;
}

//Insertion at the beginning of list
int list::insertbeg(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = nullptr;
    newnode->next = head;
    if(head == nullptr){
        tail = newnode;
        head = newnode;
    }
    head->prev =  newnode;  
    head = newnode;   
}
//Insertion at the end of list
int list::insertend(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = nullptr;
    if (tail == nullptr){
        head = newnode;
        tail = newnode;
        return 1;
    }
    tail->next = newnode;
    tail->prev = tail;
    tail = newnode;
    return 1;
}
//Insertion at position
int list::insertpos(int pos,int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = head;
    newnode->data = value;
    int i = 1;
    if (pos == 1){
        if(head == nullptr){
            tail = newnode;
            head = newnode;
            newnode-> next = nullptr;
            newnode->prev = nullptr;
            return 0;
        }
        if (head != nullptr){
            newnode->next = head;
            newnode->prev = nullptr;
            head->prev =  newnode;
            head = newnode;
            return 0;
        }
        
        
    }
    while(i<pos-1 && temp!=nullptr){
        temp = temp->next;
        i++;
    }
    if (temp == nullptr){
        printf("Invalid position\n");
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != nullptr){
        temp->next->prev = newnode;
    }
    if (temp->next == nullptr){
        tail = newnode;
    }
    temp->next = newnode;
}
//Function for deletion at beginning
int list::deletebeg(){
    int value = head->data;
    struct node *temp = head;
    if (head->next != nullptr){
        head->next->prev = nullptr;
    }
    if(head->next == nullptr){
       tail = nullptr; 
    }
    head = head->next;
    free(temp);
    return value;
}
//Function for deletion at end
int list::deleteend(){
    int value;
    struct node *temp = head;
    struct node *temp1;
   
    if(head->next == nullptr){
        temp1 = head;
        value = head->data;
        head = nullptr;
        tail = nullptr;
        free(temp1);
        return value;
    }
    value = tail->data;
    temp1 = tail;
    tail = tail->prev;
    tail->next = nullptr;
    free(temp1);
    return value;
    // while(temp->next->next != nullptr){
    //     temp = temp->next;
    // }
    // value = temp->next->data;
    // temp1 = temp->next;
    // temp->next = nullptr;
    // free(temp1);
    // return value;
}
//Function for deletion at position
int list::deletepos(int pos){
    int value;
    int i = 1;
    struct node *temp =head;
    struct node *temp1;
    if (pos == 1){
        temp1 = head;
        value = head->data;
        if(head->next == nullptr){
            tail = nullptr;
        }
        if(head->next != nullptr){
            head->prev = nullptr;
        }
        head = head->next;
        
        free(temp1);
        return value;
    }
    while(temp!=nullptr && i<pos-1){
        temp = temp->next;
        i++;
    }
    printf("i = %d\n",i);
    if(temp == nullptr || temp->next == nullptr){
        printf("Invalid position\n");
        return -1;
    }
    // if(temp->next->next == nullptr){
    //     value = temp->next->data;
    //     temp1 = temp->next;
    //     temp->next = nullptr;
    //     free(temp1);
    //     return value;
    // }
    value = temp->next->data;
    temp->next = temp->next->next;
    if (temp->next!=nullptr){
        temp->next->prev = temp; 
    }
    if (temp->next == nullptr){
        tail = nullptr;
    }
    return value;
}
//Function to display
void list::display(){
    if (head == nullptr){
        printf("List empty");
        return;
    }
    struct node *temp = head;
    while(temp!=nullptr){
        printf("%d   ",temp->data);
        temp = temp->next;
    }
    
    printf("\n");
    temp = tail;
    while(temp!=nullptr){
        printf("%d   ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
//Program to search for a element
int list::search(int target){
    struct node *temp = head;
    int position = 0;
    while(temp!=nullptr){
        if (temp->data == target){
            position++;
           return position;
        }
        position ++;
        temp = temp->next;
    }
    return 0;
}
