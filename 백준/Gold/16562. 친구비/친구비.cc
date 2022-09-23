#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
 
int p[10001];
int S[10001];
bool visited[10001];
int item[10001];
map<int,bool> mymap;
map<int,bool>::iterator iter;
 
int find(int x){
    if(p[x] == x){
        return x;
    }
    else{
        p[x] = find(p[x]);
        return p[x];
    }
}
 
int merge(int a,int b){
    int A = find(a);
    int B = find(b);
    if(A == B){
        return -1;
    }
    if(S[A] < S[B]){
        S[B] = S[A];
        p[B] = A;
    }
    else{
        S[A] = S[B];
        p[A] = B;
    }
    visited[A] = 1;
    visited[B] = 1;
    return 1;
}
 
int main(void){
    int n,m,k;
    cin >> n >> m >> k;
 
    for(int i = 1;i<=n;i++){
        S[i] = 1;
        p[i] = i;
    }
    for(int i = 1;i<=n;i++){
        cin >> item[i];
        S[i] = item[i];
    }
 
 
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(find(a) != find(b)){
        	merge(a,b);
        }
    }
 
   for(int i = 1;i<=n;i++){
       iter = mymap.find(find(i));
       if(iter == mymap.end()){
           mymap[find(i)] = 1;
       }
   }
 
    int ans = 0;
 
    for(iter = mymap.begin();iter != mymap.end();iter++){
        ans += S[iter->first];
    }
 
    bool flag = false;
    for(int i = 1;i<=n;i++){
        if(find(i) != i && visited[find(i)] == false){
            flag = true;
            break;
        }
    }
    if(ans > k){
        flag = true;
    }
 
    if(flag == true){
        cout << "Oh no";
    }
    else{
        cout << ans;
    }
 
 
 
}