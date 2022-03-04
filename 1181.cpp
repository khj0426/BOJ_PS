#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;

//백준 1181 단어정렬
 
bool compare(string s1,string s2){
    int num1 = s1.size();
    int num2 = s2.size();
    if(num1 == num2){
        return s1<s2;
    }
    else{
    return num1 < num2;
}
}
 
int main(void){
 
    string str[20000];
 
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> str[i];
    }
 
    sort(str,str+n,compare);
 
    for(int i = 0;i<n;i++){
        if(str[i] != str[i+1]){
            cout << str[i] << '\n';
        }
 
    }
}