#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int r,c;
char map[21][21];
vector<string> v;

void input(){
    cin >> r >> c;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> map[i][j];
        }
    }
}

int solve(){
    
    
    for(int i = 0;i<r;i++){
        string str = "";
        bool find = false;
        
        for(int j = 0;j<c;j++){
            if(map[i][j] != '#'){
                str += map[i][j];
            }
            else if(map[i][j] == '#'){
                if(str.size() == 1 || str == ""){
                    str = "";
                    continue;
                }
                else if(str.size() >= 2){
                    v.push_back(str);
                    find = true;
                    break;
                }
            }
            
        }
        if(find == false && str != "" && str.size() >= 2){
            v.push_back(str);
        }
        
    }
    
    for(int i = 0;i<c;i++){
        string str = "";
        bool FIND = false;
        
        for(int j = 0;j<r;j++){
            if(map[j][i] != '#'){
                str += map[j][i];
            }
            else if(map[j][i] == '#'){
                if(str.size() == 1 || str == ""){
                    str = "";
                    continue;
                }
                else if(str.size() >= 2){
                    v.push_back(str);
                    FIND = true;
                    break;
                }
            }
        }
        if(FIND == false && str != "" && str.size() >= 2){
            v.push_back(str);
        }
    }
    
    sort(v.begin(),v.end());
    cout << v[0];

    return 0;
    
  
}
int main(void){
    input();
    solve();
}
