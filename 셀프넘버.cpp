#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
 //백준 셀프넘버 4673

int d(int n){ //n과 n자리수 모두 더한 값 리턴
    string str = to_string(n); //n을 문자열로 바꾸고 sum의 초기값을 n으로
    int sum = n;
    for(int i = 0;i<str.size();i++){ //n의 자리수 더하고 리턴
        sum = sum + str[i]-48;
    }
    return sum; 
}
 
int main(void){
    bool arr[100000];
    for(int i = 1;i<=10000;i++){ //생성자 방문처리
        arr[d(i)] = true;
    }
    for(int i = 1;i<=10000;i++){
      if(arr[i] == false){
          cout << i << '\n';
      }
    }
 
}