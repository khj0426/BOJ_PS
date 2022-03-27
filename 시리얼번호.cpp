#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

//백준 1431 시리얼 번호
 
using namespace std;
 
int min(int a,int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}
 
bool compare(string s1,string s2){
    int first_sum = 0;
    int second_sum = 0;
    if(s1.size() != s2.size()){
        if(s1.size() > s2.size()){
            return false;
        }
        else if(s1.size() < s2.size()){
            return true;
        }
    }
    else if(s1.size() == s2.size()){
        for(int i = 0;i<s1.size();i++){
            if(isdigit(s1[i]) != 0){
                first_sum = first_sum + s1[i]-48;
            }
        }
        for(int i = 0;i<s2.size();i++){
            if(isdigit(s2[i]) != 0){
                second_sum = second_sum + s2[i]-48;
            }
        }
        if(first_sum > second_sum){
            return false;
        }
        else if(first_sum < second_sum){
            return true;
        }
        else if(first_sum == second_sum){
            return s1<s2;
        }
    }
 
}
 
int main(void){
    string arr[55];
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n,compare);
    for(int i = 0;i<n;i++){
        cout << arr[i] << '\n';
    }
}