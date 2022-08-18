#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
 
#define MAX 987654321
using namespace std;
 
int map[27][27];
int n,m;
 
void init(){
    cin >> n;
    for(int i = 0;i<26;i++){
        for(int j = 0;j<26;j++){
            if(i != j){
                map[i][j] = MAX;
            }
        }
    }
 
 
}
 
void parse(){
 
    char a = '\0';
    char b = '\0';
 
    for(int i = 0;i<n*3;i++){
        string str;
        cin >> str;
        if(str.size() == 1){
            if(a == '\0'){
                a = str[0];
            }
            else if(a != '\0' && b == '\0'){
                b = str[0];
            }
        }
        if(a != '\0' && b != '\0'){
            map[a-'a'][b-'a'] = 1;
            a = '\0';
            b = '\0';
 
        }
    }    
}
 
int main(void){
    init();
    parse();
 
    for(int k = 0;k<26;k++){
        for(int i = 0;i<26;i++){
            for(int j = 0;j<26;j++){
                if(map[i][j] == 1 || (map[i][k] == 1 && map[k][j] == 1)){
                    map[i][j] = 1;
                }
            }
        }
    }
    
 
    
    cin >> m;
    
    char a = '\0';
    char b = '\0';
 
    for(int i = 0;i<m*3;i++){
        string str;
        cin >> str;
        if(str.size() == 1){
            if(a == '\0'){
                a = str[0];
            }
            else if(a != '\0' && b == '\0'){
                b = str[0];
            }
        }
        if(a != '\0' && b != '\0'){
            if(map[a-'a'][b-'a'] == 1){
                cout << "T" << '\n';
            }
            else{
                cout << "F" << '\n';
            }
            a = '\0';
            b = '\0';
 
        }
    }    
    
    
}