//Program to implement Hash ADT with Linear Probing
#include <cstdio>
#include <iostream>
using namespace std;
#define TABLE_SIZE 10
class linearprobing{
    private:
    int arr[TABLE_SIZE];
    public:
    linearprobing(){
    for(int i=0;i<TABLE_SIZE;i++){
        arr[i] = -1;
    }
    }
    int insert(int);
    int delete1(int);
    int search(int);
    void display();
};
int main(){
    linearprobing l1;
    int value;
    int choice;
    int result;
    while(1){
        printf("Enter 1 for insert\nEnter 2 for delete\nEnter 3 for search\n");
        printf("Enter 4 for display\nEnter 5 for exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to insert:");
            scanf("%d",&value);
            result = l1.insert(value);
            if(result == 1){
                printf("Insertion successfull\n");
            }
            else{
                printf("Cannot insert\nTable is full\n");
            }
            break;
            case 2:
            printf("Enter the value to delete:");
            scanf("%d",&value);
            result = l1.delete1(value);
            if(result == -1){
                printf("Cannot delete elements\n");
            }
            else{
                printf("The element is found at the index %d\n",result);
            }
            break;
            case 3:
            printf("Enter the value to search:");
            scanf("%d",&value);
            result = l1.search(value);
            if(result == -1){
                printf("The element is not found\n");
            }
            else{
                printf("The element is found at the index %d",result);
            }
            break;
            case 4:
            l1.display();
            break;
            case 5:
            return 0;
            default:
            printf("Enter valid choice\n");
        }
        printf("\n");
        printf("\n");
    }
    return 0;
}
//function to insert elements
int linearprobing::insert(int key){
    int index = key%TABLE_SIZE;
    int c;
    printf("Enter the value of the constant c:");
    scanf("%d",&c);
    for(int i=0;i<TABLE_SIZE;i++){
        int ins = (index+i*i+c)%TABLE_SIZE;
        if(arr[ins] == -1){
            arr[ins] = key;
            return 1;
        }
    }
    return -1;
}
//Function to delete elements
int linearprobing::delete1(int key){
    int index = key%TABLE_SIZE;
    for(int i=0;i<TABLE_SIZE;i++){
        int ins = (index+i*i+c)%TABLE_SIZE;
        if(arr[ins]==-1){
            return -1;
        }
        if(arr[ins] == key){
            arr[ins] = -1;
            return ins;
        }
    }
    return -1;
}
//Function to search for elements
int linearprobing::search(int key){
    int index = (key)%TABLE_SIZE;
    for(int i=0;i<TABLE_SIZE;i++){
        int ins=(index+i*i+c)%TABLE_SIZE;
        if(arr[ins] == -1){
            return -1;
        }
        if(arr[ins] == key){
            return ins;
        }
    }
    return -1;
}
//Function to display
void linearprobing::display(){
    for(int i=0;i<TABLE_SIZE;i++){
        printf("%d   ",arr[i]);
    }
    printf("\n");
}
