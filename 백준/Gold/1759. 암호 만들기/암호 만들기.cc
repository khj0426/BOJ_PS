#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
 
char charater[15];
bool visited[15];
char arr[15];
int l,c;
void dfs(int start,char ch){
    string temp = "";
    if(start == l){
        int a = 0; //자음
        int b = 0; //모음
        bool nots = false;
        for(int i = 0;i<l;i++){   
             if(arr[i-1] > arr[i]){
                  nots = true;
                  break;
              }
            if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'o' || arr[i] == 'u' ||arr[i] == 'i'){
                a++;
            }
            else{
                b++;
            }  
              temp = temp + arr[i];
        }
        if(a>=1 && b>=2 && nots == false){
            cout << temp << '\n';
        }
        return;
        }
        for(int i = 0;i<c;i++){
            if(visited[i] == false && charater[i] > ch){
                visited[i] = true;
                arr[start] = charater[i];
                dfs(start+1,arr[start]);
                visited[i] = false;
            }
        }
 
 
}
int main(void){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
 
    cin >> l >> c;
    for(int i = 0;i<c;i++){
        cin >> charater[i];
    }
    sort(charater,charater+c);
    dfs(0,' ');
 
}