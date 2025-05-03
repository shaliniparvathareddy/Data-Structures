//program for listadt operations
#include <cstdio>
class listADT{
   private:
    int arr[5];
    int size;
    int current;
   public:
    listADT(){
        size=5;
        current = 0;
    }
   int insertbeg(int value);
   int insertend(int value);
   int insertpos(int value,int pos);
   int deletebeg();
   int deleteend();
   int deletepos(int pos);
   int search(int target);
   void display();
   int rotate1(int k);
   int rotate2(int k);
   int rotate3(int k);
   int reverse(int start,int end);
   int swap(int n1,int n2);

};
int main(){
    listADT lst1;
    int choice;
    int value;
    int pos;
    int k;
    int result;
    while(1){
        printf("Enter 1 for insertion at the beginning\nEnter 2 for insertion at the end\nEnter 3 for insertion at position\nEnter 4 for deletion at the beginning\nEnter 5 for deletion at the end\nEnter 6 for insertion at position");
        printf("\nEnter 7 for search\nEnter 8 for display\nEnter 9 to rotate\nEnter 10 for exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value you want to add:");
            scanf("%d",&value);
            lst1.insertbeg(value);
            lst1.display();
            break;
            case 2:
            printf("Enter the value you want to add:");
            scanf("%d",&value);
            lst1.insertend(value);
            lst1.display();
            break;
            case 3:
            printf("Enter the value you want to add:");
            scanf("%d",&value);
            printf("Enter the pos you want to add:");
            scanf("%d",&pos);
            lst1.insertpos(value,pos);
            lst1.display();
            break;
            case 4:
            result = lst1.deletebeg();
            printf("The deleted element is %d\n",result);
            lst1.display();
            break;
            case 5:
            result = lst1.deleteend();
            printf("The deleted element is %d\n",result);
            lst1.display();
            break;
            case 6:
            printf("Enter the position you want to delete:");
            scanf("%d",&pos);
            result = lst1.deletepos(pos);
            printf("The deleted element is %d\n",result);
            break;
            case 7:
            printf("Enter the value you want to search for:");
            scanf("%d",&value);
            result = lst1.search(value);
            if (result == 0){
                printf("The value is not found\n");
            }
            else{
                printf("The element is found at %d th index\n",result);
            }
            break;
            case 8:
            lst1.display();
            break;
            case 9:
            printf("Enter the number of times you want to rotate:");
            scanf("%d",&k);
            // lst1.rotate1(k);
            lst1.rotate2(k);
            // lst1.display();
            break;
            case 10:
            return 0;
            break;
            default:
            printf("Enter valid number\n");
        }
    }
    return 0;
}
//function to insert elements at the beginning
int listADT::insertbeg(int value){
    if (size==current){
        printf("The array is full\n Cannot insert value\n");
        return 0;
    }
    for(int i = current-1;i>=0;i--){
        arr[i+1] = arr[i];
    }
    arr[0] = value;
    current++;
    return 1;
}
//function to insert elements at the end
int listADT::insertend(int value){
    if(size == current){
        printf("The array is full\nCannot insert value\n");
        return 0;
    }
    arr[current] = value;
    current++;
    return 1;
}
//function to insert elements at a particular position
int listADT::insertpos(int value,int pos){
    if (size == current){
        printf("The array is full\nCannot insert value\n");
        return 0;
    }
    if (pos>size || pos<1){
        printf("Enter valid value of pos\n");
        return 0;
    }
    for(int i = current-1;i>=pos-1;i--){
        arr[i+1] = arr[i];
    }
    arr[pos-1] = value;
    current++;
    return 1;

}
//function to delete the first element
int listADT::deletebeg(){
    int value = arr[0];
    if (current == 0){
        printf("The list is empty\nNo elements can be deleted\n");
        return 0;
    }
    for(int i = 0;i<current -1;i++){
        arr[i] = arr[i+1];
    }
arr[current-1] = 0;
    current--;
    return value;
}
//function to delete the last element
int listADT::deleteend(){
    int value = arr[current-1];
    if (current == 0){
        printf("The list is empty\nNo elements can be deleted\n");
        return 0;
    }
    arr[current-1] = 0;
    current--;
    return value;
}
//function to delete element at a position
int listADT::deletepos(int pos){
    int value = arr[pos];
    if (current == 0){
        printf("The list is empty\nNo elements can be deleted\n");
        return 0;
    }
    if (pos>size || pos<1){
        printf("Enter valid value of pos\n");
        return 0;
    }
    for(int i = pos-1;i<current-1;i++){
        arr[i] = arr[i+1];
    }
arr[current-1] = 0;
    current--;
    return value;
}
//function to search for an element
int listADT::search(int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return 0;
}
//function to displaying the elements
void listADT::display(){
    for (int i = 0;i<size;i++){
        printf("%d   ",arr[i]);
    }
    printf("\n");
}
//function to rotate the elements of the array
int listADT::rotate1(int k){
    k=k%size;
    if (current == 0){
        printf("The list is empty\nIt cannot be rotated\n");
        return 0;
    }
    for(int i=0;i<k;i++){
        int temp = arr[current-1];
        for(int j=current-1;j>0;j--){
        arr[j] = arr[j-1];
    }
    arr[0] = temp;
    }
    return 1;
}
//function to swap elements
int listADT::swap(int n1,int n2){
    printf("%d\n",n1);
    printf("%d\n",n2);
    int temp = n1;
    n1 = n2;
    n2 = temp;
    printf("succesfull\n");
    printf("%d\n",n1);
    printf("%d\n",n2);
    return 1;
}
//function to reverse the elements of the array
int listADT::reverse(int start,int end){
    while(start<=end){
        // int temp = arr[start];
        // arr[start] = arr[end];
        // arr[end] = temp;
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    return 1;
}
//function to the elements of the array
int listADT::rotate2(int k){
    k=k%size;
    reverse(0,size-1);
    reverse(0,k-1);
    reverse(k,size-1);
return 1;
}
//function to rotate elements of the array
int listADT::rotate3(int k){
    k=k%size;
    int count =0;
    for (int i = 0; count < size; i++) {
        int current = i;
        int prev = arr[i];

        do {
            int next = (current + k) % size; 
            swap(arr[next], prev);  
            current = next;
            count++;
        } while (i != current);  
}
 
}
