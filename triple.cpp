#include <map>
#include <iostream>
using namespace std;
int main(void){
  //codeforce triple
    int t;
    cin >> t;
    while(t--){
    map<int,int> m;
    map<int,int>::iterator iter;
        bool is_find = false;
        int n;
        cin >> n;
        for(int i = 0;i<n;i++){
            int x;
            cin >> x;
            m[x]++;
        }
        for(iter = m.begin();iter != m.end();iter++){
            if(iter->second >= 3){
                cout << iter->first << '\n';
                is_find = true;
                break;
            }
        }
        if(is_find == false){
            cout << "-1" << '\n';
        }
 
 
    }
 
}