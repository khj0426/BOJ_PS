#include <iostream>
#include <string>
using namespace std;
int main(void){
    string str;
    cin >> str;
    bool is_not_valid = false; 
 
    for(int i = 0;i<str.size();i++){
        if(str[i] == 'p'){
            if(str[i+1] == 'i'){
                i = i + 1;
                continue;
            }
            else if(str[i+1] != 'p'){
                cout << "NO";
                return 0;
            }
        }
        else if(str[i] == 'k'){
            if(str[i+1] == 'a'){
                i = i + 1;
                continue;
            }
            else if(str[i+1] != 'k'){
                cout << "NO";
                return 0;
            }
        }
        else if(str[i] == 'c'){
            if(str[i+1] == 'h' && str[i+2] == 'u'){
                i = i + 2;
                continue;
            }
            else{
                cout << "NO";
                return 0;
            }
        }
        else if(str[i] != 'k' || str[i] !='c' || str[i] != 'p'){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}