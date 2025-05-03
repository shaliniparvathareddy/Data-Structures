//Stack implementation using arrays
#include <cstdio>
class stack{
    private:
    char arr[5];
    int current;
    int size;
    public:
    stack(){
        current = 0;
        size = 5;
    }
    int push(char);
    char pop();
    void peek();
};
int main(){
    int choice;
    char value;
    stack s1;
    while(1){
        printf("Enter 1 for push\nEnter 2 for pop\nEnter 3 for peek\n");
        printf("Enter 4 for exit\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice){
            case 1:
            printf("Enter the value to be inserted:");
            scanf(" %c",&value);
            s1.push(value);
            break;
            case 2:
            value = s1.pop();
            if(value == -1){
                printf("The stack is empty\nCannot delete element\n");
                }
                else{
                    printf("The deleted element is :%c\n",value);

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
    if(current == size){
        printf("The stack is full\nCannot insert elements\n");
        return 0;
    }
    arr[current]=value;
    current ++;
    return 1;
}
//Function to pop elements
char stack::pop(){
    if(current==0){
        return -1;
    }
    char value = arr[current-1];
    current --;
    return value;
}
//Function to print last element
void stack::peek(){
    if(current == 0){
        printf("The stack is empty\n");
        return;
    }
    printf("The element last inserted is :%c\n",arr[current-1]);
}
