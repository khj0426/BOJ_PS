#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
bool is_break[101];

void solve(int a,int b){
    for(int i = a;i<b;i++){
        is_break[i] = true;
    }
}

void init(){
    cin >> n;
    for(int i = 1;i<=n;i++){
        is_break[i] = false;
    }
    cin >> m;
    for(int i = 0;i<m;i++){
        int A,B;
        cin >> A >> B;
        solve(A,B);
    }
}



int main(void){
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        if(is_break[i] == false){
            cnt++;
        }
    }
    cout << cnt;
}