#include <iostream>
#include <string>
#include <map>
#include <algorithm>

 //백준 베스트셀러
using namespace std;
 
int main(void){
    map<string,int> m;
    map<string,int> ::iterator iter;
    
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        string temp;
        cin >> temp;
        m[temp]++;
    }
 
    int count = 0;
    string Bestseller = "";
 
    for(iter = m.begin();iter != m.end();iter++){
        if(iter->second > count){ //iter->first : key값, iter->second : value값
            count = iter->second;
            Bestseller = iter->first;
        }
        else if(iter->second == count){
            if(Bestseller > iter->first){
                Bestseller = iter->first;
            }
        }
    }
    cout << Bestseller;
 
}