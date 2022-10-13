#include <iostream>
#include <string>

//백준 1536 유진수

using namespace std;
int main(void){
    string str;
    cin >> str;
    if(str == "1"){
        cout << "NO";
        return 0;
    }
    long long sum = 1;
    for(int i = 0;i<str.size();i++){
         sum = (str[i]-48) * sum;
 
        long long temp = 1;
        for(int j = i+1;j<str.size();j++){
            temp = temp * (str[j]-48);
        }
        if(sum == temp){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}