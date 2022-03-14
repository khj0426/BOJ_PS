#include <iostream>
#include <queue>

using namespace std;

int main(void){
    
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    priority_queue<int> q;  
    
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