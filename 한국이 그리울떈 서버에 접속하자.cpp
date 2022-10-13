#include <iostream>
#include <string>

//백준 9996 한국이 그리울떈 서버에 접속하자

using namespace std;
int main(void){
    int n;
    cin >> n;
    string pattern;
    cin >> pattern;
    string arr[101];
    bool index[101];
 
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
 
    string start_str = "";
    string end_str = "";
    for(int i = 0;i<pattern.size();i++){
        if(pattern[i] == '*'){
            break;
        }
        start_str = start_str + pattern[i]; //앞에서부터 *까지의 패턴 문자열
    }
 
    for(int i = pattern.size();i>=0;i--){ //뒤에서부터 *까지의 패턴 문자열
        if(pattern[i] == '*'){
            break;
        }
        end_str = end_str + pattern[i];
    }
 
    for(int i = 0;i<n;i++){
        bool is_not_pattern = false;
        for(int j = 0;j<start_str.size();j++){ //방문한 인덱스 bool값 true로 바꾸고
            index[j] = true;
            if(arr[i][j] != start_str[j]){ //패턴이 다른경우
                is_not_pattern = true;
                break;
            }
 
        }
 
      for(int j = end_str.size()-1;j>=0;j--){ //뒤에서부터 패턴 문자열
          if(end_str[j] != arr[i][arr[i].size()-j] && index[arr[i].size()-j] != true){
              is_not_pattern = true;
              break;
          }
          if(end_str[j] == arr[i][arr[i].size()-j] && index[arr[i].size()-j] == true){
              is_not_pattern = true;
              break;
          }
     /*패턴이 다른경우 + 패턴이 같은데 이미방문한 인덱스를 방문 시 탈출*/
          
      }
 
        if(is_not_pattern == true){
            cout << "NE" << '\n';
        }
        else{
            cout << "DA" << '\n';
        }
    }
 
}
 