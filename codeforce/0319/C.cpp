#include <vector>
#include <iostream>
#include <string>
 
using namespace std;
int main(void){
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        bool flag = false;
        int n;
        cin >> n;
 
        int alpha[70] = {0, };
        for(int i = 0;i<=27;i++){
            alpha[i] = 0;
        }
 
        vector<char> str;
 
 
        for(int i = 0;i<n;i++){
            char newC;
            cin >> newC;
            str.push_back(newC);
        }
 
 
        for(int i = 0;i<str.size();i++){
        	alpha[str[i] -'a']++;
        }
 
        for(int i = 0;i<str.size();i++){
            if(alpha[str[i]-'a'] >= 1){
                if((i+1) % 2 != 0){
                    for(int j = 0;j<str.size();j++){
                        if(str[i] == str[j] && (j+1) % 2 == 0){
                            flag = true;
                            break;
                        }
                    }
                    if(flag){
                        break;
                    }
                }
                else if((i+1) % 2 == 0){
                    for(int j = 0;j<str.size();j++){
                        if(str[i] == str[j] && (j+1) % 2 != 0){
                            flag = true;
                            break;
                        }
                    }
                }
            }
 
            if(flag){
                break;
            }
        }
 
 
        if(flag == false){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
 
 
}