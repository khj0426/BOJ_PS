#include <stdio.h>
#include <stdlib.h>
#define ERROR 0.00000001

//백준 6986
//https://www.acmicpc.net/board/view/191
 
double arr[100000];
 
int compare(const void *a,const void *b){
    double num1 = *(double *)a;
    double num2 = *(double *)b;
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
 
double Calculate_A(int n,int k){
    double sum = 0;
    int idx = 0;
    for(int i = k;i<n-k;i++){
        sum = sum + arr[i];
        idx++;
    }
 
    return sum/idx;
}
 
double Calculate_B(int n,int k){
    for(int i = 0;i<k;i++){
        arr[i] = arr[k];
    }
 
    for(int i = n-1;i>=n-k;i--){
        arr[i] = arr[n-k-1];
    }
    double sum = 0;
    for(int i = 0;i<n;i++){
        sum = sum + arr[i];
    }
    return sum/n;
 
}
 
int main(void){
    int n;
    int k;
    scanf("%d %d",&n,&k);
 
    for(int i = 0;i<n;i++){
        scanf("%lf",&arr[i]);
    }
 
    qsort(arr,n,sizeof(double),compare);
 
    printf("%.2f\n",Calculate_A(n,k)+ERROR);
    printf("%.2f\n",Calculate_B(n,k)+ERROR);
}