#include <iostream>
#include <string>
using namespace std;
int L,R,S,K = 0;

int main(void){
    
    int n;
    cin >> n;
    string str;
    cin >> str;
    
    bool flag = false;
    int cnt = 0;
    for(int i = 0;i<str.size();i++){
        
        if(str[i] >= '1' && str[i] <= '9'){
            cnt++;
        }
        else{
            if(str[i] == 'L'){
            L++;
            
        }
        else if(str[i] == 'S'){
            S++;
           
        }
        else if(str[i] == 'R'){
            if(L > 0){
                L--;
                cnt++;
            }
            else if(L == 0){
                break;
            }
           
        }
        else if(str[i] == 'K'){
            if(S > 0){
                S--;
                cnt++;    
            }
            else if(S == 0){
                break;
            }
            
        }
    }
        }
        
    cout << cnt;
}