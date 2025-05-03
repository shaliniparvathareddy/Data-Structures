//Program to convert infix to postfix and evaluate postfix expression
#include "fix.h"
void getinfix(char str[]);
char* convertinfix(char s[]);
int evaluatepostfix(char* s);
int precedece(char op);
int main(){
    char str[100];
    int choice;
    char* result1; 
    while(1){
        printf("Enter 1 for storing infix\nEnter 2 for converting the expression\nEnter 3 for evaluating the expression\n");
        printf("Enter 4 for exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            getinfix(str);
            break;
            case 2:
            result1=convertinfix(str);
            break;
            case 3:
            evaluatepostfix(result1);
            break;
            case 4:
            return 0;
            default:
            printf("Enter valid number\n");
        }
        printf("\n");
    }
}
//Function to store infix
void getinfix(char str[]){
    printf("Enter the expression:");
    scanf(" %s",str);
    return;
}
//Function to return the precedence of operators
int precedece(char op){
    if(op=='*' || op=='/'){
        return 2;
    }
    else if(op=='+' || op=='-'){
        return 1;
    }
    return 0;
}
//Function to convert infix to postfix
char* convertinfix(char s[]){
    char symbol;
    char* postfix = (char*)malloc(100 * sizeof(char));
    stack stk;
    int j=0;
    char next;
    for (int i=0;s[i]!='\0';i++){
        symbol = s[i];
        if(symbol == '('){
            stk.push(symbol);
        }
        else if(symbol == ')'){
            while((next=stk.pop())!='('){
                postfix[j++] = next;
            }
        }
        else if(symbol == '*'||symbol == '/'||symbol=='+'||symbol=='-'){
            while(!stk.isEmpty() && precedece(stk.peek())>=precedece(symbol)){
                postfix[j++] = stk.pop();
            }
            stk.push(symbol);
        }
        else{
            postfix[j++] = symbol;
        }
    }
    while(!stk.isEmpty()){
        postfix[j++]=stk.pop();
    }
    postfix[j]='\0';
    printf("The postfix expression is :%s",postfix);
    return postfix;
}
//Function to evaluate postfix expression
int evaluatepostfix(char* s){
    char postfix;
    stack1 stk1;
    for (int i=0;s[i]!='\0';i++){
        char symbol = s[i];
        if(!(symbol == '*'||symbol == '/'||symbol=='+'||symbol=='-')){
            stk1.push(symbol-'0');
        }
        else if(symbol == '*'||symbol == '/'||symbol=='+'||symbol=='-'){
            int num2 = stk1.pop();
            int num1 = stk1.pop();
            if(symbol=='*'){
                stk1.push(num1*num2);
            } 
            else if(symbol =='/'){
                stk1.push(num1/num2);
            }
            else if(symbol=='+'){
                stk1.push(num1+num2);
            } 
            else if(symbol =='-'){
                stk1.push(num1-num2);
            }
        }
    }
    int result = stk1.pop();
    printf("The value of the expression is:%d",result);
}
