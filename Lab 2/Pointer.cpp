//menu driven program to identify palindrome armstrong and perfect number
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
void palindrome(int *no);
void armstrong(int *no);
void perfect(int *no);
int main(){
    int *no = (int*)malloc(sizeof(int));
    
    while(1){
printf("Enter 1 palindrome 2 for armstrong 3 for perfect 4 to exit");
printf("\n");
printf("Enter your choice:");
int choice;
scanf("%d",&choice);
switch(choice){
case 1:
printf("enter the number:");
    scanf("%d",no);
palindrome(no);
break;
case 2:
printf("enter the number:");
    scanf("%d",no);
armstrong(no);

break;
case 3:
printf("enter the number:");
    scanf("%d",no);
perfect(no);
break;
case 4:
return 0;
break;
default:
printf("enter valid choice");
printf("\n");
}
}
     free(no);
     return 0;
}
//function to identify palindrome
void palindrome(int *no){
    int *revno = (int*)malloc(sizeof(int));
    int *no1 = (int*)malloc(sizeof(int));
    *no1=*no;
    int *rem = (int*)malloc(sizeof(int));
    *revno=0;
    while(*no!=0){
        *rem=(*no)%10;
        *revno=(*revno)*10+(*rem);
        *no=(*no)/10;
    }
    printf("%d\n",*revno);
    if(*no1==*revno){
        printf("it is an palindrome\n");
    }
    else{
        printf("it is not a palindrome\n");
    }
    free(revno);
    free(no);
    free(rem);
}
//function to identify armstrong number
void armstrong(int *no){
    int *no1 = (int*)malloc(sizeof (int));
    *no1 = *no;
     int *rem = (int*)malloc(sizeof(int));
    int *count = (int*)malloc(sizeof(int));
    *count=0;
     int *no2 = (int*)malloc(sizeof(int));
     *no2=0;
    while(*no1!=0){
        *no1=*no1/10;
        (*count)++;
    }
    *no1=*no;
    while(*no1!=0){
        *rem = *no1%10;
        *no2=(*no2)+pow(*rem,*count);
        *no1=*no1/10;
    }
    // if(*no2==*no){
    //     printf("it is an armstrong number\n");
    // }
    // else{
    //     printf("it is not an armstrong number\n");
    // }
    free(no1);
    free(count);
    free(rem);
    free(no2);
}
//function to identify perfect number
void perfect(int *no){
    int *sum= (int*)malloc(sizeof(int));
    *sum=0;
    int *i= (int*)malloc(sizeof(int));
    for( (*i)=1;(*i)<=(*no)-1;(*i)++){
        if((*no)%(*i)==0){
            (*sum)=(*sum)+(*i);
        }

    }
    if (*no == *sum){
        printf("it is a perfect number\n");
    }
    else{
        printf("it is not an perfect number\n");
    }
    free(sum);
    free(i);

}
