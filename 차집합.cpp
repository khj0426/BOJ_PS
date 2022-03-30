#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
 
//백준 1822 차집합
using namespace std;
 
int main(void){
 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<long long,long long> m;
    map<long long,long long>::iterator iter;
 
    vector<long long> v;
    vector<long long>::iterator viter;
    int count = 0;
    int n,l;
    cin >> n >> l;
    int a[500000];
    int b[500000];
 
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
 
    for(int i = 0;i<l;i++){
        cin >> b[i];
    }
 
    for(int i = 0;i<l;i++){
        m[b[i]]++;
    }
 
    for(int i = 0;i<n;i++){
        iter = m.find(a[i]);
        if(iter == m.end()){
            count++;
            v.push_back(a[i]);
        }
    }
 
    if(count == 0){
        cout << '0' << '\n';
    }
    else{
        
        sort(v.begin(),v.end());
    cout << count << '\n';
    for(viter = v.begin();viter != v.end();viter++){
        cout << *viter << ' ';
    }
    }
 
 
}