#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
int main(void){
    string A;
    string B;
    cin >> A;
    cin >> B;
 
    int Min = 987654321;
 
    for(int i = 0;i<=B.size()-A.size();i++){  
        int count = 0;
        for(int j = 0;j<A.size();j++){
            if(A[j] != B[j+i]){
                count++;
            }
        }
      Min = min(count,Min);
    }
    cout << Min;
 
}