#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int visited[26];
 
int main(void){
 
    int n;
    cin >> n;
    string str;
    cin >> str;
    int check_valid= 0;
 
    int l = 0;
    int r = 0;
    int max_length = 1;
    int cur_length = 1;
    visited[str[l]-'a'] = true;
    check_valid = 1;
    while(l<=r && r<str.size()){
        if(check_valid <= n){
           r++;
 
           if(visited[str[r]-'a'] == 0){
               visited[str[r]-'a'] += 1;
               cur_length++;
               max_length = max(max_length,cur_length);
               check_valid++;
           }
           else if(visited[str[r] -'a'] != 0){
               visited[str[r]-'a'] += 1;
               cur_length++;
               max_length = max(max_length,cur_length);
           }
 
        }
 
        else if(check_valid > n){
           visited[str[l]-'a']--;
 
           if(visited[str[l]-'a'] == 0){
           	check_valid--;
             
           }
            l++;
            cur_length--;  
        }
   
 
 
    }
      cout << max_length-1;

 
}