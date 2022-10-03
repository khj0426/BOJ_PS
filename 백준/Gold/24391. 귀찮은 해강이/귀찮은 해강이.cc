#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
 
int parent[100001];
int n,m;
 
int find(int x){
   if(parent[x] == x){
       return x;
   } 
   else{
       parent[x] = find(parent[x]);
       return parent[x];
 
   } 
}
 
void merge(int A,int B){
    int a = find(A);
    int b = find(B);
 
    if(a<b){
        parent[b] = a;
    }
    else if(a>b){
        parent[a] = b;
    }
}
 
void init(){
    scanf("%d %d",&n,&m);
 
    for(int i = 0;i<=n;i++){
        parent[i] = i;
    }
 
    for(int i = 0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        merge(a,b);
    }
}
 
int solve(){
    vector<int> v;
    int sum = 0;
    for(int i = 0;i<n;i++){
        int lecture;
        scanf("%d",&lecture);
        v.push_back(lecture);
       if(i != 0){
            if(find(v[i-1]) != find(lecture)){
                sum++;
            }
       }
    }
    return sum;
}
 
int main(void){
    init();
    printf("%d",solve());
}