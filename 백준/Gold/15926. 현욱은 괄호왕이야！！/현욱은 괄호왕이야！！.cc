#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
 
 
bool index[200001];
char str[200001];
stack<pair<int,int>> st;
int main(void){
    int n;
    cin >> n;
 
    for(int i = 1;i<=n;i++){
        cin >> str[i];
    }
 
    for(int i = 1;i<=n;i++){
        if(st.empty()){
            st.push({str[i],i});
        }
        else{
            if(st.top().first == '(' && str[i] == ')'){
 
               int element = st.top().second;
                index[element] = true;
                index[i] = true;
                st.pop();
            }
            else{
                st.push({str[i],i});
            }
        }
    }
 
	int max_value = 0;
    vector<int> v;
    
    for(int i = 1;i<=n;i++){
        if(index[i] == true){
            v.push_back(1);
        }
        else if(index[i] == false){
            
            if(max_value < v.size()){
                max_value = v.size();
            }
            v.clear();
        }
        
    }
    if(v.size() > max_value){
        max_value = v.size();
    }
    cout << max_value;
 
 
}