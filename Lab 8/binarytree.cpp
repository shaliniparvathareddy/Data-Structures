/*
LESSONS LEARNT
     1.ROOT IS PRIVATE(SO CANNOT DIRECTLY PASS)
     2.QUEUE SHOULD BE STRUCT NODE* TYPE
*/
//Program to implement tree ADT using a character binary tree
#include <cstdio>
#include <cstdlib>
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
            t1.insert(value);
            break;
            case 2:
            t1.preorder(t1.getroot());
            break;
            case 3:
            t1.inorder(t1.getroot());
            break;
            case 4:
            t1.postorder(t1.getroot());
            break;
            case 5:
            printf("Enter the value to search for:");
            scanf(" %c",&value);
            result = t1.search(value);
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
        printf("\n");
    }
}
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
