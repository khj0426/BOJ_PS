
//틀린 코드

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
    pair<string,int> s;
    pair<string,int> r;
 

 
int main(void){
    int max_size = 0;
    pair<string,int> arr[20001];
 
    int n;
    cin >> n;
 
    for(int i = 0;i<n;i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
 
    sort(arr,arr+n);
    for(int i = 0;i<n;i++){
       string temp = arr[i+1].first.substr(0,arr[i].first.size());
        
        if(temp.size() >= max_size && temp == arr[i]){
            max_size = temp.size();
            s = arr[i];
            r = arr[i+1];
        }
    }
 
 
    if(s.second < r.second){
        cout << s.first << '\n';
        cout << r.first;
        return 0;
    }
    else{
        cout << r.first << '\n';
        cout << s.first;
        return 0;
    }
 
 
}
