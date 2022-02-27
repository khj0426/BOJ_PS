#include <iostream>
#include <cstring>
#include <string>
#include <deque>
 
using namespace std;
 
int main(void){
    int n;
    cin >> n;
 
    deque<int> dq;
 
    for(int i = 0;i<n;i++){
        char Str[30];
        cin >> Str;
        if(strcmp(Str,"push_front") == 0){
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if(strcmp(Str,"push_back") == 0){
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if(strcmp(Str,"pop_front") == 0){
            if(dq.empty()){
               cout << "-1" << '\n';
            }
            else{
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if(strcmp(Str,"pop_back") == 0){
            if(dq.empty()){
                cout << "-1" << '\n';
            }
            else{
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if(strcmp(Str,"size") == 0){
           cout << dq.size() << '\n';
        }
        else if(strcmp(Str,"empty") == 0){
            if(dq.empty()){
                cout << "1" << '\n';
            }
            else{
                cout << "0" << '\n';
            }
        }
        else if(strcmp(Str,"front") == 0){
              if(dq.empty()){
                cout << "-1" << '\n';
            }
            else{
                cout << dq.front() << '\n';
            }
        }
        else if(strcmp(Str,"back") == 0){
           if(dq.empty()){
                cout << "-1" << '\n';
            }
            else{
                cout << dq.back() << '\n';
            }
        }
    }
 
}