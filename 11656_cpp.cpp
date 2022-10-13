#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

//백준 접미사배열
 
using namespace std;

 
int main(void){
    string prefix[1000];
    string str;
    cin >> str;
    int i = 0;
 
    for(i = 0;i<str.size();i++){
        string temp;
        for(int j = i;j<str.size();j++){
            temp = temp + str[j];
        }
        prefix[i] = temp;
 
    }
 
   sort(prefix,prefix+i);
 
    for(int i = 0;i<str.size();i++){
        cout << prefix[i] << endl;
    }
}