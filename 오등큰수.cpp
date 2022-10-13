#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

//백준 17299 오등큰수

using namespace std;
int main(void){
    stack <pair<int,int>> st;
    int arr[1100000];
    int count[1100000];
    vector<int> v;
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        count[arr[i]]++; 
    }
 
    for(int i = n-1;i>=0;i--){
        if(st.empty()){
            st.push({arr[i],count[arr[i]]});
            v.push_back(-1);
        }
        else{
            if(count[arr[i]] < st.top().second){
                v.push_back(st.top().first);
                st.push({arr[i],count[arr[i]]});
            }
            else if(count[arr[i]] >= st.top().second){
                while(1){
                    if(st.empty() || st.top().second > count[arr[i]]){
                        break;
                    }
                    st.pop();
                }
                if(st.empty()){
                    v.push_back(-1);
                    st.push({arr[i],count[arr[i]]});
                }
                else if(st.top().second > count[arr[i]]){
                    v.push_back(st.top().first);
                    st.push({arr[i],count[arr[i]]});
                }
            }
 
        }
    }
    vector<int>::iterator iter;
    reverse(v.begin(),v.end());
    for(iter = v.begin();iter != v.end();iter++){
        cout << *iter << ' ';
    }
 
 
}