#include <iostream>
#include <string>
#include <algorithm>

//백준 8892 팰린드롬

//string reverse(string.begin(),string.end()) ->문자열을 뒤집어주는 함수(algorithm 헤더 추가)
 
using namespace std;
 
int main(void){
    int t;
    cin >> t;
    while(t--){

        string arr[100];
        int n;
        cin >> n;
 
 
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
 
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i != j){
                string sum = arr[i] + arr[j];
                string compare = sum;
                reverse(sum.begin(),sum.end());
                if(sum == compare){
                    count++;
                    cout << sum << '\n';
                    break;
                }
                }
                else if(i == j){
                    continue;
                }
            }
            if(count != 0){
                break;
            }
        }
        if(count == 0){
            cout << '0' << '\n';
        }
 
}
 
}