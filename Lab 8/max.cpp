//Program to find the largest amount of block in tower 1
#include <cstdio>
//Function to find the largest amount of blocks in tower 1
void largest(){
    printf("\nEnter number of towers:");
    int no_towers;
        scanf("%d",&no_towers);
        int arr[no_towers];
        printf("Enter the number of blocks:");
        for(int j = 0;j<no_towers;j++){
            scanf("%d",&arr[j]);
        }
        for(int i=0;i<no_towers-1;i++){
        for(int j=1;j<no_towers-i-1;j++){
            if (arr[j+1] < arr[j]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
              
            }
        }
        }
        for(int k =1;k<no_towers;k++){
            if(arr[k]>arr[0]){
                if((arr[0]+arr[k])%2 == 0){
                    arr[0] = (arr[0]+arr[k])/2;
                }
                else{
                    arr[0] = ((arr[0]+arr[k])/2)+1;
                }
            }
        }
        printf("The largest amount of blocks in tower1:%d\n\n",arr[0]);
}
int main(){
    int testcases;
    printf("Enter number of testcases:");
    scanf("%d",&testcases);
    for(int i = 0;i<testcases;i++){
        largest();
    }
    return 0;
}
