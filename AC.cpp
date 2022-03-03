#include<iostream>
#include<string>
#include<deque>
#include<cstring>
#include<cctype>

//백준 AC
//R이 나오면 0,1을 통해 뒤에서 뺼건지 앞에서 뺄건지 정하기
 
using namespace std;
 
int main(void){
    int t;
    cin >> t;
 
 
    for(int i = 0;i<t;i++){
        bool R = false;
        bool is_error = false;
     deque <int> dq;
        string str;
        cin >> str;
        int n;
        cin >> n;
        string arr;
        cin >> arr;
        string temp;
        for(int i = 0;i<arr.size();i++){
            if(isdigit(arr[i]) != 0 && arr[i+1] == ','){
                temp = temp + arr[i];
                int n = stoi(temp);
                dq.push_back(n);
                temp = "";
            }
            else if(isdigit(arr[i]) != 0 && isdigit(arr[i+1]) != 0){
                temp = temp + arr[i];
            }
            else if(isdigit(arr[i])!= 0 && arr[i+1] == ']'){
                temp = temp + arr[i];
                int n = stoi(temp);
                dq.push_back(n);
                temp = "";
            }

 
        }
 
        for(int i = 0;i<str.size();i++){
             if(str[i] == 'R'){
                if(R == false){
                    R = true;
                }
                else if(R == true){
                    R = false;
                }
 
            }
           else if(str[i] == 'D'){
                if(dq.empty()){
                    cout << "error";
                    is_error = true;
                    break;
                }
                else if(!dq.empty()){
                    if(R == false){
                        dq.pop_front();
                    }
                    else if(R == true){
                        dq.pop_back();
                    }
                }
            }
 
        }
 
        if(is_error != true){
        cout << '[';
        }
 
 
        while(1){
            if(R == false){
                if(dq.empty()){
                    break;
                }
                cout << dq.front();
                if(!dq.empty()){
 
 
                    dq.pop_front();
                    if(dq.size() != 0){
                        cout << ',';
                    }
 
                }
 
 
            }
            else if(R == true){
                 if(dq.empty()){
                    break;
                }
                cout << dq.back();
                if(!dq.empty()){
 
                    dq.pop_back();
                    if(dq.size() != 0){
                        cout << ',';
                    }
                }
 
            }
        }
 
 
        if(is_error != true){
 
        cout << ']';
        }
 
        cout << '\n';
 

    }
 
}