#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int n;
int max_value = -1;
int k;
vector<char> v;
vector<char> combinate;

void dfs(int start){
    
     string new_str = "";
     for(int i = 0;i<start;i++){
            new_str += combinate[i];
        }
    
    if(new_str.size() >= 1){
        int temp = stoi(new_str);
        if(temp >= max_value && temp <= N){
            max_value = temp;
        }
    }

    if(start == n){
        int temp = stoi(new_str);
        for(int i = 0;i<start;i++){
            new_str += combinate[i];
        }
        if(temp >= max_value && temp <= N){
            max_value = temp;
        }
        return;
    }
    
    for(int i = 0;i<k;i++){
        combinate.push_back(v[i]);
        dfs(start+1);
        combinate.pop_back();
    }
}
int main(void){
    string input;
    cin >> input;
  
    n = input.size();
    N = stoi(input);
    
    
    
    cin >> k;

    for(int i = 0;i<k;i++){
        char c;
        cin >> c;
        v.push_back(c);
    }

    dfs(0);
    
    cout << max_value;
}
