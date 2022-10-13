#include <iostream>
#include <queue>

using namespace std;

struct st{
    int operator()(int a,int b){
        return a>b;
    }
};

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    priority_queue<int, vector <int>, st> q;
    int n;
    cin >> n;
    
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        if(x != 0){
            q.push(x);
        }
        else if(x == 0){
            if(q.empty()){
                cout << '0' << '\n';
            }
            else{
                cout << q.top() << '\n';
                q.pop();
            }
        }
    }
    
}