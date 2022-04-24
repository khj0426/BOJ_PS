#include <iostream>
#include <string>
#include <map>
//백준 1235 학생 번호
/*뒤에서부터 문자열 더하면서 공통된 번호가 아닐때, 번호의 크기 리턴*/

using namespace std;
int main(void){
    string arr[1000];
    string str[1000];
    map<string,string> m;
    map<string,string>::iterator iter;
 
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
 
 
 
       for(int j = arr[0].size()-1;j>=0;j--){
           bool distinct_ = false;
           for(int i = 0;i<n;i++){
               str[i] = str[i] + arr[i][j];
           }
 
           for(int k = 0;k<n;k++){
               iter = m.find(str[k]);
               if(iter == m.end()){
                   m.insert(pair<string,string>(str[k],str[k]));
               }
               else if(iter != m.end()){
                   distinct_ = true;
                   break;
               }
           }
           if(distinct_ == false){
               cout << str[0].size();
               return 0;
           }
 
       }
 
 
}