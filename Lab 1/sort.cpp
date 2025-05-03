//Program to sort numbers
#include <cstdio>
void bubblesort(int arr[],int size);
void selectionsort(int arr[],int size);
void insertionsort(int arr[],int size);
void display(int arr[],int size);
int main(){
  int size;
  printf("Enter the no of elements");
  scanf("%d",&size);
  int arr[size];
  for(int i=0;i<size;i++){
      printf("Enter the %d element",i);
      scanf("%d",&arr[i]);
  }
  while(1){
    printf("Enter 1 forbubblesort 2 for selectionsort 3 for insertion 4 to exit");
    printf("\n");
    printf("Enter your choice");
    int choice;
    scanf("%d",&choice);
    switch(choice){
    case 1:
    bubblesort(arr,size);
    break;
    case 2:
    selectionsort(arr,size);
    break;
    case 3:
    insertionsort(arr,size);
    break;
    case 4:
    return 0;
    break;
    default:
    printf("enter valid choice");
    printf("\n");
    }
  }
return 0;
}
// Function for bubble sorting
void bubblesort(int arr[],int size){
  for(int i=0;i<size-1;i++){
    int swapped =0;
    for(int j=0;j<size-i-1;j++){
      if (arr[j+1] < arr[j]){
        int temp=arr[j+1];
        arr[j+1]=arr[j];
        arr[j]=temp;
      }
      }
      printf("The array after %d pass is ",i);
      printf("\n");
      display(arr,size);
  }
  display(arr,size);
}
// Function for selection sort
void selectionsort(int arr[],int size){
  for(int i=0;i<size;i++){
    int minindex=i;
    for(int j=i+1;j<size;j++){
      if(arr[j]<arr[minindex]){
        minindex=j;
      }
      }
      int temp1=arr[minindex];
      arr[minindex]=arr[i];
      arr[i]=temp1;
      printf("The array after %d pass is ",i);
      printf("\n");
      display(arr,size);
  }
  display(arr,size);
}
// Function for insertion sort
void insertionsort(int arr[],int size){
  for(int i=1;i<size;i++){
    int key = arr[i];
    int j=i-1;
    while (arr[j]>key && j>=0){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
    printf("The array after %d pass is ",i);
    printf("\n");
    display(arr,size);
    }
    display(arr,size);
    }
    void display(int arr[],int size){
    for(int k=0;k<size;k++){
    printf("%d",arr[k]);
    printf("\n");
  }
}
