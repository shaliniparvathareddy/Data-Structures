#include<iostream>
#include<algorithm>
using namespace std;
int findwinner(int a,int ni[],int q);
int main(){
    int k;
    int q;
    int testcases;
    printf("Enter the number of testcases:");
    scanf("%d",&testcases);
    for(int i=0;i<testcases;i++){
        printf("Enter the length of sequence a:");
        scanf("%d",&k);
        printf("Enter the number of values ni:");
        scanf("%d",&q);
        int a[k];
        int ni[q];
        printf("Enter the sequence a:");
        for(int j=0;j<k;j++){
            scanf("%d",&a[j]);
        }
        printf("Enter the values of ni:");
        for(int j=0;j<q;j++){
            scanf("%d",&ni[j]);
        }
        findwinner(a[0],ni,q);
    }
}

int findwinner(int a,int ni[],int q){
    
    printf("The number of winner are:");
    for(int i=0;i<q;i++){
        printf("%d   ",min(ni[i],a-1));
    }
    printf("\n");
    printf("\n");
}
