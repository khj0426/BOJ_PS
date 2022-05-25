#include <iostream>
using namespace std;
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
struct data{
    int t;
    int p;
};
 
typedef struct data d;
int max_length = 0;
d arr[15];
int n;
bool visited[15];
 
void dfs(int start,int sum){
    if(start == n){
        max_length = max(sum,max_length);
        return;
    }
 
    dfs(start+1,sum);
    if(start+arr[start].t <= n){
        dfs(start+arr[start].t,sum+arr[start].p);
    }
 
}
 
int main(void){
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i].t >> arr[i].p;
    }
    dfs(0,0);
    cout << max_length;
 
}