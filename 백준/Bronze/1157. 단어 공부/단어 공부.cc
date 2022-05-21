#include <iostream>
#include <string>

using namespace std;
int arr[60];
int main(void){
    string str;
    cin >> str;
    for(int i = 0;i<str.size();i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            arr[str[i]-'a']++;
        }
        else{
            arr[str[i]-'A']++;
        }
    }
    int max = 0;
    int num = 0;
    string ans = "";
    
  for(int i = 0;i<26;i++){
      if(max < arr[i]){
          max = arr[i];
          ans = i + 'A';
      }
      else if(max == arr[i]){
          ans = '?';
      }
  }
    
    
   cout << ans;
}