#include "stack.h"
int checkbalance(string);
int main(){
    string s;
    int choice;
    int result;
    while(1){
        cout<<"Enter 1 for check balance\nEnter 2 for exit\nEnter your choice:";
        cin>>choice;
        switch(choice){
            case 1: 
            cout<<"Enter the string:";
            cin>>s;
            result = checkbalance(s);
            cout<<result<<endl;
            if(result==1){
                cout<<"Balanced!!!"<<endl;
            }
            else{
                cout<<"Not balanced!!!"<<endl;
                
            }
            break;
            case 2:
            return 0;
            default:
            cout<<"Invalid option"<<endl;
        }
    }
    return 0 ;
}
int checkbalance(string s){
    list s1;
    int result = 0;
    int count=0;
    for(int i=0;i!='\0';i++){
        if(s[i]=='('){
            s1.push(i);
        }
        else if (s[i]==')'){
                s1.pop();
            
        }
    }
    result = int(s1.isempty());
    if (result){
        return 1;
    }
    
    return 0;
}
