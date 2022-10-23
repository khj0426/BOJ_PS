#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int,int> m;
map<int,int>::iterator iter;
int n;
void init(){
    cin >> n;
    for(int i = 0;i<n;i++){
        int name,effect;
        cin >> effect >> name;
        m[effect] = name;
    }
}
int main(void){
    init();
    int k;
    cin >> k;
    for(int i = 0;i<k;i++){
        int r;
        cin >> r;
        vector<int> v;
        for(int j = 0;j<r;j++){
            int x;
            cin >> x;
            iter = m.find(x);
            if(iter != m.end()){
                v.push_back(m[x]);
            }
        }
        if(v.size() != r){
            cout << "YOU DIED" << '\n';
        }
        else{
            for(int j = 0;j<v.size();j++){
                cout << v[j] << ' ';
            }
            cout << '\n';
        }
    }
}