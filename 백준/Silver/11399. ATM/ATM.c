#include <stdio.h>
void Bubblesort(int arr[],int n){ 
    int i,j;
    int temp;
    for(i = 0;i<n-1;i++){ 
        for(j = 0;j<(n-i)-1;j++){ 
            if(arr[j]>arr[j+1]){ 
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(void){
    int sum = 0;
    int summ = 0;
    int n;
    scanf("%d",&n);
    int arr[1000];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    Bubblesort(arr,n);
    for(int i = 0;i<n;i++){
        sum = sum + arr[i];
        summ = summ + sum;
    }
    printf("%d",summ);
}