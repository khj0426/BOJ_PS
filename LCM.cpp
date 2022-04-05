#include <iostream>
//백준 5347 LCM
using namespace std;
long long GCD(long long a,long long b){
        if(a%b == 0){
            return b;
        }
           int A= a;
           int B= b;
           int C= a%b;
        while(1){ 
            if(C== 0){
                return B;
            }
            else{
                A = B;
                B = C;
                C = A%B;
            }
        }
}
long long LCM(long long a,long long b){
    return a*b/GCD(a,b);
}
int main(void){
    int t;
    cin >> t;
    while(t--){        
        long long a;
        long long b;
       
        cin >> a >> b;
        cout << LCM(a,b) << '\n';
    }
}