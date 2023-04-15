#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
int down[1000001];
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int,int>> st;
    
    
    for(int i = 0;i<prices.size();i++){
        if(st.empty()){
            st.push({prices[i],i+1});
        }
        else{
            if(st.top().first <= prices[i]){
                st.push({prices[i],i+1});
            }
            else{
             
                int cnt = 0;
                while(1){
                    if(st.empty()){
                        break;
                    }
                    
                    if(st.top().first <= prices[i]){
                        break;
                    }
                    
                    cnt++;
                    down[st.top().second] = (i+1) - st.top().second;
                    st.pop();
                }
                st.push({prices[i],i+1});
            }
        }
    }
    
    while(!st.empty()){
        down[st.top().second] = prices.size()-st.top().second;
        st.pop();
    }
    
    for(int i = 1;i<=prices.size();i++){
        answer.push_back(down[i]);
    }
    
    return answer;
}