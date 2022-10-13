#include <iostream>
#include <map>
using namespace std;
//백준 1269 대칭차집합
int main(void){
    int A[200000];
    int B[200000];
    map<int,int> m;
    map<int,int>::iterator iter;
    int n,l;
    cin >> n >> l;
    for(int i = 0;i<n;i++){
        cin >> A[i];
        m[A[i]]++;
    }
 
    for(int i = 0;i<l;i++){
        cin >> B[i];
    }
 
    int count = 0;
    for(int i = 0;i<l;i++){
        iter = m.find(B[i]);
        if(iter == m.end()){
            count++;
        }
    }
 
    m.clear();
 
    for(int i = 0;i<l;i++){
        m[B[i]]++;
    }
 
    for(int i = 0;i<n;i++){
        iter = m.find(A[i]);
        if(iter == m.end()){
            count++;
        }
    }
    cout << count;
 
}