#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
 
int n,m;
int arr[300000];
int main(void){
    scanf("%d %d",&n,&m);
 
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    map<int,int> Mymap;
    map<int,int>::iterator iter;
 
    for(int i = 0;i<n;i++){
        iter = Mymap.find(arr[i]);
        if(iter == Mymap.end()){
            Mymap.insert({arr[i],i});
        }
        else{
            continue;
        }
    }
 
    for(int i = 0;i<m;i++){
        int query;
        scanf("%d",&query);
        iter = Mymap.find(query);
        if(iter != Mymap.end()){
            int N = iter->second;
            printf("%d\n",N);
        }
        else{
            printf("-1\n");
        }
    }
}