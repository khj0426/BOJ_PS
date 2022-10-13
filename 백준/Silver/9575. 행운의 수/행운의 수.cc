#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t--){
 
        int a,b,c;
        map<int,int> m;
        int A[51];
        int B[51];
        int C[51];
 
        cin >> a;
        for(int i = 0;i<a;i++){
            cin >> A[i];
        }
        cin >> b;
        for(int i = 0;i<b;i++){
            cin >> B[i];
        }
        cin >> c;
        for(int i = 0;i<c;i++){
            cin >> C[i];
        }
        for(int i = 0;i<a;i++){
            for(int j = 0;j<b;j++){
                for(int k = 0;k<c;k++){
                    int sum = A[i] + B[j] + C[k];
 
                    string str = to_string(sum);
                    bool is_not_valid = false;
 
                    for(int q = 0;q<str.size();q++){
                        if(str[q] == '5' || str[q] == '8'){
                            continue;
                        }
                        else{
                            is_not_valid = true;
                            break;
                        }
                    }
                    if(is_not_valid == false){
 
                        m.insert({sum,sum});
                    }
 
                }
            }
        }
        cout << m.size() << '\n';
    }
 
}