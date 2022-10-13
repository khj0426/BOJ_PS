#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
 
double min(double a,double b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
int arr[501];
//k이상 n-1이하
 
double caculate(int k,int start){
    double m = 0;
    for(int i = start;i<start+k;i++){
        m = m + arr[i];
    }
    m = m/k;
    double N = 0;
    for(int i = start;i<start+k;i++){
        N = N + (arr[i]-m) * (arr[i]-m);
    }
    N = N/k;
    return sqrt(N);
}
 
int main(void){
    int n;
    int k;
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
 
    float Min = 2000000000;
 
    while(k<=n){
 
 
        for(int i = 0;i<=n-k;i++){
            double m = 0;
            int n = 0;
            for(int j = i;j<i+k;j++){
                m = m + arr[j];
                n++;
            }
            double mid = m/n;
            double temp = 0;
            for(int j = i;j<i+k;j++){
                temp = ((arr[j]-mid)*(arr[j]-mid)) + temp;
 
            }
            double ans = sqrt(temp/n);
            Min = min(ans,Min);
            
 
        }
        k++;
 
    }    
 
    cout.precision(7);
     cout << Min << '\n';
 
}