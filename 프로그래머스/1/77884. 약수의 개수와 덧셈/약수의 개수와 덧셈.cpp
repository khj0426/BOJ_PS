#include <iostream>
#include <string>
#include <vector>
//약수의 개수가 짝수 + 홀수 - 
using namespace std;
int getCount(int n){
    int count = 0;
    for(int i = 1;i<=n;i++){
        if(n % i == 0){
            count++;
        }
    }
    return count;
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left;i<=right;i++){
        if(getCount(i) % 2 == 0){
            answer += i;
        }
        else{
            answer -= i;
        }
    }
    
    return answer;
}