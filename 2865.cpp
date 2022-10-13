#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
 
  //백준 2865(나는 위대한 슈퍼스타 K)

using namespace std;

bool compare(pair<int,double> a, pair<int,double> b){ //vector의 second(참가자의능력)순으로 정렬
    if(a.first != b.first){
        return a.second > b.second;
    }
 
}
 
int main(void){
    int n,m,k;
    cin >> n >> m >> k;
    vector<pair<int,double>> v(n*m);
 
    for(int i = 0;i<m*n;i++){ //참가자의 번호와 능력 입력
         cin >> v[i].first >> v[i].second;   
    }
 
    sort(v.begin(),v.end(),compare); //참가자의 능력 순으로 정렬
 
    int value[10001] = {-1,}; //중복을 막을 배열
    int index = 0;
 
    double sum = 0; //참가자의능력 합
   for(int i = 0;i<n*m;i++){
 
       bool is_true = false; //중복시 true로 변경
       if(k == 0){//k만큼 더했다면 루프 탈출
           break;
       }
 
       if(i == 0){ //첫번째 경우 참가자의 능력 더해주고 k --, value 배열에 참가자의 번호 저장
           sum = sum + v[i].second;
           k--;
           value[index] = v[i].first;
           index++;
       }
       else{ //첫번째 경우가 아닌 경우
           for(int j = 0;j<index;j++){ //value배열만큼 돌면서
               if(v[i].first == value[j]){ //vector.first(참가자의 번호)와 중복된다면
                   is_true = true; //is_true ->true ->루프 탈출
                   break;
               }
           }
           if(is_true == false){ 
               //그 외의 경우 참가자의 능력 더해주고 k --, value 배열에 참가자의 번호 저장
               sum = sum + v[i].second;
               k--;
               value[index] = v[i].first;
               index++;
           }
       }
   }
    cout << fixed; //소수점자리 1자리로 고정
    cout.precision(1);
    cout << sum;
}