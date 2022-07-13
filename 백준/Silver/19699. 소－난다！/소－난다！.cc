#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int primes[20001];
int n,m;
map<int,int> Map;
map<int,int>::iterator iter;
int a[10];
int arr[10];
bool visited[10];

void init(){
    for(int i = 1;i<=20000;i++){
        primes[i] = i;
    }
    
    for(int i = 2;i<=20000;i++){
        for(int j = i+i;j<=20000;j=j+i){
            if(primes[j] == 0){
                continue;
            }
            primes[j] = 0;
        }
    }
}

void dfs(int start){
    if(start == m){
        int sum = 0;
        for(int i = 0;i<m;i++){
            sum += arr[i];
        }
        
        if(primes[sum] != 0){
            Map.insert({sum,sum});
        }
        return;
    }
    for(int i = 0;i<n;i++){
        if(visited[i] == false){
            visited[i] = true;
            arr[start] = a[i];
            dfs(start+1);
            visited[i] = false;
        }
    }
}
int main(void){
    init();
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    
    dfs(0);
    if(Map.size() == 0){
        cout << -1;
        return 0;
    }
   
    for(iter = Map.begin();iter != Map.end();iter++){
        cout << iter->first << ' ';
    }
  
}