#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool not_mix[201][201];
vector<int> v;
vector<int> combinate;
int n,m;

void init(){
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        not_mix[a-1][b-1] = 1;
        not_mix[b-1][a-1] = 1;
    }
    for(int i = 0;i<3;i++){
        combinate.push_back(1);
    }
    
    for(int i = 0;i<n-3;i++){
        combinate.push_back(0);
    }
    sort(combinate.begin(),combinate.end());
}

int combinate_value(){
    int cnt = 0;
    
    do{
        v.clear();
        for(int i = 0;i<n;i++){
            if(combinate[i] == 1){
                v.push_back(i);
            }
        }
        bool valid = false;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(i != j){
                    if(not_mix[v[i]][v[j]] == 1){
                        valid = true;
                        break;
                    }
                }
            }
            if(valid == true){
                break;
            }
        }

        
        if(valid == false){
            cnt++;
        }
        
        
    }while(next_permutation(combinate.begin(),combinate.end()));
    
    return cnt;
}
int main(void){
    init();
    cout << combinate_value();
}
