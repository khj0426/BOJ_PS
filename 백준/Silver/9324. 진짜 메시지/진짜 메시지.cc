#include <iostream>
#include <string>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int array[27] = {0, };
        bool is_correct = false;

        for(int i = 0;i<str.size();i++){
            char c = str[i];
            array[c-'A']++;
            if(array[c-'A'] == 3){
                if(str[i+1] != c || i+1 > str.size()){
                    is_correct = true;
                    cout << "FAKE" << '\n';
                    break;
                } 
                else{
                    array[c-'A'] = 0;
                    i = i + 1;
                }
            }
        }
        if(is_correct == false){
            cout << "OK" << '\n';
        }
        
    }
}