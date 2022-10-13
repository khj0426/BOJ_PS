#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int main(void){
    map<string,string> m;
    map<string,string>::iterator iter;
    int n;
    string arr[101];
    cin >> n;
    
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        sort(arr[i].begin(),arr[i].end());
    }
    
    
    for(int i = 0;i<n;i++){
        iter = m.find(arr[i]);
        if(iter == m.end()){
            m.insert(pair<string,string>(arr[i],arr[i]));
        }
    }
    cout << m.size();
}