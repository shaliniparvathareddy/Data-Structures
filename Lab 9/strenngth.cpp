//Program to find the difference in strengths
#include <iostream>
int strengths(int arr[],int n);
int main(){
    int testcases;
    printf("Enter the number of testcases:");
    scanf("%d",&testcases);
    int n;
    for(int i=0;i<testcases;i++){
        printf("Enter the number of participants:");
        scanf("%d",&n);
        int arr[n];
        printf("Enter the strengths of participants:");
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        strengths(arr,n);
    }
}
//Function to find the difference in strengths
int strengths(int arr[],int n){
    int max1 = arr[0];
    int max2 = arr[0];
    for(int i = 0;i<n;i++){
        if(arr[i]>max1){
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i]>max2){
            max2 = arr[i];
        }
    }
    printf("The diff for each participant is: ");
    for(int i=0;i<n;i++){
        if(arr[i] != max1){
        printf("%d   ",arr[i] - max1);
        }
        else{
            printf("%d   ",arr[i] - max2);
        }
    }
    printf("\n");
    printf("\n");
    return 1;
}
