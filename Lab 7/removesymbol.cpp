//Program to remove + and preceeding symbol
#include <cstdlib>
#include <iostream>
using namespace std;
class stack{
    private:
    struct  node{
        char data;
        struct node *next;
    }*head;
    public:
    stack(){
        head = nullptr;
    }
    int push(char);
    char pop();
    int revrer(string);
    void display(struct node*);
};
int main(){
    stack s1;
    string s;
    cout<<"Enter the string";
    cin>>s;
    s1.revrer(s);
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
    char value;
    if(head == nullptr){
        return 0;
    }
    value = head->data;
    struct node *delnode = head;
    head = head->next;
    free(delnode);
    return value;
}
//Function to perform the task
int stack::revrer(string s){
    stack s1;
    for (int i=0;s[i]!='\0';i++){
        char symbol = s[i];
        if(symbol=='+'){
            pop();
        }
        else{
            push(symbol);
        }
    }
    display(head);
    return 0;
}
void stack::display(struct node* temp){
    if(temp == nullptr){
        return;
    }
    display(temp->next);
    printf("%c",temp->data);
}
