#include <iostream>
#include <deque>
#include <cmath>
using namespace std;
int main(void){
    deque<pair<int,int>> dq;
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        int x;
        cin >> x;
        dq.push_back({i,x});
    }
 
    bool is_plus = false;
    bool is_minus = false;
 
    int first = dq.front().second;
    if(first > 0){
        is_plus = true;
        is_minus = false;
    }
    else if(first < 0){
        is_minus = true;
        is_plus = false;
    }
 
    cout << dq.front().first << ' ';
    dq.pop_front();
 
    while(!dq.empty()){
        if(is_plus == true && is_minus == false){
            for(int i = 0;i<first;i++){
                dq.push_back({dq.front().first,dq.front().second});
                dq.pop_front();
            }
            first = dq.back().second;
            cout << dq.back().first << ' ';
 
            dq.pop_back();
            if(first < 0){
                is_minus = true;
                is_plus = false;
            }
            else if(first > 0){
                is_plus = true;
                is_minus = false;
            }
        }
 
        else if(is_plus == false && is_minus == true){
            for(int i = 0;i<abs(first);i++){
                dq.push_front({dq.back().first,dq.back().second});
                dq.pop_back();
            }
            first = dq.front().second;
            cout << dq.front().first << ' ';
            dq.pop_front();
            if(first < 0){
                is_minus = true;
                is_plus = false;
            }
            else if(first > 0){
                is_plus = true;
                is_minus = false;
            }
 
        }
    }
}