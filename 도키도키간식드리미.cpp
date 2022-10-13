#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
 //백준 12789 도키도키 간식 드리미

int main(void){
    queue<int> q;
    vector<int> v;
    stack<int> st;
 
    int arr[1001];
    int n;
    cin >> n;
 
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        q.push(arr[i]);
    }
 
    int num = 1;
    while(!q.empty()){
        if(q.front() == num){
            v.push_back(num);
            q.pop();
            num++;
        }
        else if(q.front() != num){
            if(st.empty()){
                st.push(q.front());
                q.pop();
            }
            else if(!st.empty()){
                if(st.top() == num){
                    v.push_back(st.top());
                    st.pop();
                    num++;       
                }
                else if(st.top() != num){
                    st.push(q.front());
                    q.pop();
                }
            }
        }
    }
 
    while(!st.empty()){
        v.push_back(st.top());
        st.pop();
    }
    for(int i = 0;i<n;i++){
        if(v[i] != i+1){
            cout << "Sad";
            return 0;
        }
    }
    cout << "Nice";
    return 0;
 
}