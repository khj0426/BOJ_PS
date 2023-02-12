#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//행 n / 2
//열 n % 숫자

// 0 1 2 3 4 5 

// 나누기,나머지
// 00,01,02,10,11,12
// 행 열 정보 받아서 해당하는 숫자 
long long getvalidNum(vector<long long> v){
    long long maxValue = 0;
    for(int i = 0;i<v.size();i++){
        maxValue = max(maxValue,v[i]);
    }
    
    return maxValue + 1;
}

//행 열에 대한 정보 반환
vector<long long> getrowColumn(long long num,int divideNum){
    vector<long long> ans;
    ans.push_back(num/divideNum);
    ans.push_back(num%divideNum);
    return ans;
}

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    
    //00
    //01 10 11
    //02 20 12 21 22
    //33 5
    //O(n)에 풀어야 함
   
    for(long long i = left;i<=right;i++){
        vector<long long> rowColumns = getrowColumn(i,n);
        answer.push_back(getvalidNum(rowColumns));
    }
    
    return answer;
}