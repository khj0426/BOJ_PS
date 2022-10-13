#include <iostream>
#include <algorithm>
#define MAX 14
//백준 6603 로또

using namespace std;
int n;
bool visited[MAX];
int arr[MAX];
int A[MAX];
void init(){
    for(int i = 0;i<=n;i++){
        arr[i] = 0;
        A[i] = 0;
        visited[i] = false;
    }
}

void dfs(int start){
    if(start == 6){
        bool valid = false;
        
            for(int i = 0;i<6;i++){
                if(arr[i-1] > arr[i]){
                    valid = true;
                    break;
                }
            }
        if(valid == false){
            for(int i = 0;i<6;i++){
                cout << arr[i] << ' ';
            }
            cout << '\n';
        }
        
     
        return;
    }
    for(int i = 0;i<n;i++){
        if(visited[i] == false){
            visited[i] = true;
            arr[start] = A[i];
            dfs(start+1);
            visited[i] = false;
        }
    }
}
int main(void){
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        init();
        for(int i = 0;i<n;i++){
            cin >> A[i];
        }
        sort(A,A+n);
        dfs(0);
        cout << '\n';
    }
}