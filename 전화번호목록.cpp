#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main(void){
 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
   int t;
   cin >> t;
 
   for(int i = 0;i<t;i++){
       bool is_not_correct = false;
         string arr[10000];
         int n;
         cin >> n;
        for(int j = 0;j<n;j++){
             cin >> arr[j];
        }
       sort(arr,arr+n); //사전순으로 정렬하기
 
       for(int j = 0;j<n;j++){
           string temp = arr[j]; //J번쨰 배열의 문자열
           string temp_2 = arr[j+1].substr(0,temp.size());
           //J+1배열의 문자열을 J번쨰 문자열 길이만큼 짤라놓고 비교
           
           if(temp == temp_2){ //J와 J+1배열의 문자열이 같다면
               is_not_correct = true; //일관성이 없는 경우 ->is_not_correct변수를 true로 바꿔주기
               break;
           }
           else{
                continue;
           }
       }
 
 
 
       if(is_not_correct == true){ //is_not_correct == true->일관성이 없는 경우
           cout << "NO" << '\n';
       }
       else{ //그 외의 경우 일관성이 있는 경우
           cout << "YES" << '\n';
       }
 
}
 
}