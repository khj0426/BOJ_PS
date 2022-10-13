#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int cnt = 0;
vector<char> v;
vector<char> combinate;
bool visited[11];
string str;
int n;

void input(){
    
    cin >> str;
    for(int i = 0;i<str.size();i++){
        v.push_back(str[i]);
    }
    n = str.size();
    sort(v.begin(),v.end());
}

void dfs(){
    do{
        bool flag = false;
        string new_ = "";
        for(int i = 0;i<n;i++){
            if(v[i] == v[i-1] || v[i] == v[i+1]){
                flag = true;
                break;
            }
            new_ += v[i];
        }
        if(flag == false){
            cnt++;
        }
        
    }while(next_permutation(v.begin(),v.end()));    
}


int main(void){
    input();
    dfs();
    cout << cnt;
   
}