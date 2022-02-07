#include <stdio.h>
#include <stdlib.h>

//백준 1920 (이진탐색)

int compare(const void *a,const void *b){
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    if(num1 > num2){
        return 1;
    }
    else if(num1 < num2){
        return -1;
    }
    else{
        return 0;
    }
   
}

int Binaryscarch(int arr[],int n,int key){
    int low = 0;
    int high = n-1;
    int mid;
   while(low<=high){
       mid = (low + high)/2;
       if(key == arr[mid]){
           return 1;
       }
       else if(key > arr[mid]){
           low = mid + 1;
       }
       else if(key < arr[mid]){
           high = mid - 1;
       }
   }
    
    return -1;
    
}

int main(void){
   int n;
    scanf("%d",&n);
    int array[100001];
    for(int i = 0;i<n;i++){
        scanf("%d",&array[i]);
    }
    
    qsort(array,n,sizeof(int),compare);
    
    
    int m;
    scanf("%d",&m);
    
    for(int i = 0;i<m;i++){
        int x;
        scanf("%d",&x);
        
        if(Binaryscarch(array,n,x) == 1){
            printf("1\n");
        }
        else if(Binaryscarch(array,n,x) == -1){
            printf("0\n");
        }
    }
   
    
    
}