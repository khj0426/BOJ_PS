#include <stdio.h>
#include <stdlib.h>

//백준 용액합성하기(14921)
 
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
int main(void){
    int arr[100000];
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(int),compare);
 
    int is_not_plus = 0;
 
    int l = 0;
    int r = n-1;
    long long sum = 0;
    long long min = 200000001;
    while(l<r && r<n){
        sum = arr[l] + arr[r];
        if(sum < 0){
            l++;
            if(llabs(sum) < min){
                min = llabs(sum);
                is_not_plus = 1;
            }
        }
        else if(sum > 0){
            r--;
            if(llabs(sum) < min){
                min = llabs(sum);
                is_not_plus = 0;
            }
        }
        else if(sum == 0){
            min = 0;
            break;
        }
 
    }
    if(is_not_plus == 1){
        long long Min = -min;
        printf("%lld",Min);
    }
    else if(is_not_plus == 0){
        printf("%lld",min);
    }
 
}