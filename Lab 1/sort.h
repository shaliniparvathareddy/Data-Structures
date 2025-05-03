// header file code
void bubblesort(int arr[],int size){

  for(int i=0;i<size-1;i++){
  
    int swapped =0;
    
    for(int j=0;j<size-i-1;j++){
    
      if (arr[j+1] < arr[j]){
      
        int temp=arr[j+1];
        
        arr[j+1]=arr[j];
        
        arr[j]=temp;
        
        swapped=1;
        
      }
  
  }

}

for(int k=0;k<size;k++){

  printf("%d",arr[k]);
  
  printf("\n");

}

}

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
          
        }
      
    for(int k=0;k<size;k++){
    
    printf("%d",arr[k]);
    
    printf("\n");
    
    }

}


void insertionsort(int arr[],int size){

  for(int i=1;i<size;i++){
  
    int key = arr[i];
    
    int j=i-1;
    
    while (arr[j]>key && j>=0){
    
      arr[j+1]=arr[j];
      
      j--;
      
    }
    
    arr[j+1]=key;
  
  }
  
  for(int k=0;k<size;k++){
  
  printf("%d",arr[k]);
  
  printf("\n");
  
  }

}
