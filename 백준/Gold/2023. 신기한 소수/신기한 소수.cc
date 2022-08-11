#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define MAX 8
using namespace std;
int n;
int arr[MAX];
bool visited[MAX+2];

 
int check_prime(int n){
   for(int i = 2;i*i<=n;i++){
       if(n%i == 0){
           return -1;
       }
   }
    
    return 1;
}


void dfs(string str){
    if(str.size() >= n){
        if(str.size() > n){
            return;
        }
       
        bool valid = false;
        string new_str = "";
        for(int i = 0;i<n;i++){
            new_str += str[i];
            int N = stoi(new_str);
            if(check_prime(N) == -1){
                valid = true;
                break;
            }
        }
        
        if(valid == false){
             cout << str << '\n';
        }
        return;
    }
           
        for(int i = 1;i<=9;i++){
         
               string temp = str += to_string(i);
               dfs(temp);
               str.erase(str.size() - 1);
            }
        }
    
int main(void){
    cin >> n;

    dfs("2");
    dfs("3");
    dfs("5");
    dfs("7");
}