#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <stack>
using namespace std;
class tree{
    private:
    struct node{
        char data;
        struct node* left;
        struct node* right;
    }*root;
    public:
    tree(){
        root = nullptr;
    }
    struct node* getroot(){
        return root;
    }                                                                                                                                                                        
    int insert(char);
    void preorder(struct node*);
    void inorder(struct node*);
    void postorder(struct node*);
    int search(char);
    int constructexp(char str[],tree &t1);
};
//Function to insert elements in the tree
int tree::insert(char data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->right = nullptr;
    newnode->left = nullptr;
    if (root == nullptr){
        root = newnode;
        return 1;
    }
    struct node* queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    
    while(front < rear){
        struct node* temp = queue[front++];
        if(temp->left == nullptr){
            temp->left = newnode;
            return 1;
        }
        else{
            queue[rear++] = temp->left;
        }
        if(temp->right == nullptr){
            temp->right = newnode;
            return 1;
        }
        else{
            queue[rear++] = temp->right;
        }
    }
    return -1;
}
//Function to perform preorder traversal
void tree::preorder(struct node*curr){
    if(curr  == nullptr){
        return;
    }
    printf("%c   ",curr->data);
    preorder(curr->left);
    preorder(curr->right);
}
//Function to perform inorder traversal
void tree::inorder(struct node* curr){
    if(curr == nullptr){
        return;
}
    inorder(curr->left);
    printf("%c   ",curr->data);
    inorder(curr->right);
}
//Function to perform postorder traversal
void tree::postorder(struct node* curr){
    if(curr == nullptr){
        return;
    }
    postorder(curr->left);
    postorder(curr->right);
    printf("%c   ",curr->data);
}
//Function to perform search
int tree::search(char target){
    struct node* queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    if(root == nullptr){
        return -1;
    }
    while(front < rear){
        struct node* temp = queue[front++];
        if (temp->data == target){
            return 1;
        }
        if(temp->left != nullptr){
            queue[rear++] = temp->left;
        }
        if(temp->right != nullptr){
            queue[rear++] = temp->right;
        }
    }
    return -1;
}
//Function to check if an character is symbol
int isoperator(char s){
    if(s== '+' || s=='-' || s=='*' || s=='/'){
        return 1;
    }
    return 0;
}
//Function to construct expression tree
int tree::constructexp(char str[],tree &t1){
    char symbol;
    stack <struct node*> Stack;
    for(int i =0;str[i]!='\0';i++){
        symbol = str[i];
        if(isoperator(symbol) == 1){
            struct node* newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = str[i];
            if(Stack.size()>=2){
                newnode->right = Stack.top();
                Stack.pop();
                newnode->left = Stack.top();
                Stack.pop();
                Stack.push(newnode);
                
            }
        }
        else{
            struct node* newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = symbol;
            newnode->right = nullptr;
            newnode->left = nullptr;
            Stack.push(newnode);
        }
    }
    t1.root = Stack.top();
    return 1;
}
