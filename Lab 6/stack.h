#include <iostream>
#include <cstdlib>
class stack {
    public:
    struct node{
        char data;
        struct node*next;
    }*head;
    stack(){
        head = nullptr;
    }
    int push(char);
    char pop();
    char peek();
    bool isEmpty() {
        return head == nullptr; 
    }
    
};
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
        return '\0';
    }
    struct node *delnode;
    delnode = head;
    char value = head->data;
    head = head->next;
    free(delnode);
    return value;
}
char stack::peek(){
    if(head == nullptr){
        printf("The stack is empty\n");
        return -1;
    }
    return head->data;
}
