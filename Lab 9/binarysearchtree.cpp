//Program to implement binary search tree
#include <cstdio>
#include <cstdlib>
class tree{
    public:
    struct node{
        char data;
        struct node* left;
        struct node* right;
    }*root;
    
    tree(){
        root = nullptr;
    }
    struct node* getroot(){
        return root;
    }
    tree::node* insert(char, tree::node*);
    void preorder(struct node*);
    void inorder(struct node*);
    void postorder(struct node*);
    int search(struct node*,char target);
};
int main(){
    tree t1;
    int choice;
    char value;
    int result;
    while(1){
        printf("Enter 1 for insert\nEnter 2 for preorder traversal\nEnter 3 for inorder traversal\n");
        printf("Enter 4 for postorder traversal\nEnter 5 for search\n");
        printf("Enter 6 for exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter value to insert:");
            scanf(" %c",&value);
            t1.root = t1.insert(value, t1.getroot());
            break;
            case 2:
            t1.preorder(t1.getroot());
            printf("\n");
            break;
            case 3:
            printf("hello 3\n");
            t1.inorder(t1.getroot());
            printf("\n");
            break;
            case 4:
            t1.postorder(t1.getroot());
            printf("\n");
            break;
            case 5:
            printf("Enter the value to search for:");
            scanf(" %c",&value);
            result = t1.search(t1.getroot(),value);
            if (result == -1){
                printf("The element is not found in the tree\n");
            }
            else{
                printf("The element is found in the tree\n");
            }
            break;
            case 6:
            return 0;
            default:
            printf("Enter valid choice\n");
        }
        printf("\n");
    }
}
//Function to insert elements
tree::node* tree::insert(char value, tree::node* curr) {
    if (curr == nullptr) {
        node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->left = nullptr;
        newnode->right = nullptr;
        return newnode;
    }
    if (value < curr->data) {
        curr->left = insert(value, curr->left);
    } 
    else if(value > curr->data) {
        curr->right = insert(value, curr->right);
    }
    return curr;
}
//Function to perform preorder traversal
void tree::preorder(struct node* curr){
    if(curr == nullptr){
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
int tree::search(struct node* curr, char target) {
    if (curr == nullptr) {
        return -1;  
    }
    if (curr->data == target) {
        return 1;  
    }
    if (target < curr->data) {
        return search(curr->left, target);
    }
    return search(curr->right, target);
}
