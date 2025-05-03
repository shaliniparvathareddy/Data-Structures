//Program to implement expression tree
#include "tree.h"
int validpostfix(char str[]);
int main(){
    tree t1;
    int choice;
    int result;
    char str[100];
    while(1){
        printf("Enter 1 for Postfix Expression\nEnter 2 to Construct Expression Tree\nEnter 3 for preorder\n");
        printf("Enter 4 for inorder\nEnter 5 for postorder\n");
        printf("Enter 6 for exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the Postfix Expression:");
            scanf("%s",str);
            result = validpostfix(str);
            if(result == 0){
                printf("It is valid postfix expression\n");
            }
            else{
                printf("This is an invalid expression\n");
            }
            break;
            case 2:
            printf("Enter the Postfix Expression:");
            scanf("%s",str);
            if(validpostfix(str)==0){
                t1.constructexp(str,t1);
            }
            else{
                printf("Invalid expression\n");
            }
            break;
            case 3:
            t1.preorder(t1.getroot());
            printf("\n");
            break;
            case 4:
            t1.inorder(t1.getroot());
            printf("\n");
            break;
            case 5:
            t1.postorder(t1.getroot());
            printf("\n");
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
//Function to check if a postfix expression is valid
int validpostfix(char str[]){
    stack <char> operand;
    for(int i = 0;str[i]!='\0';i++){
        char symbol = str[i];
        if(isoperator(symbol)){
            if(operand.size()<2){
                return -1;
            }
            operand.pop();
            operand.pop();
            operand.push(1);
        }
        else if(isalnum(symbol)){
            operand.push(1);
        }
        else{
            return -1;
        }
    }
    return 0;
}
