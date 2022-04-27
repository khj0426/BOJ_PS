#include <iostream>
#include <string>
using namespace std;

//codeforce Division? 
int main(void){
 
 string str[100000];
 int n;
 cin >> n;
 for(int i = 0;i<n;i++){
     cin >> str[i];
 }
 
 for(int i = 0;i<n;i++){
 	int N = stoi(str[i]);
     if(N >= 1900){
         cout << "Division 1" << '\n';
     }
     else if(N >= 1600 && N <= 1899){
         cout << "Division 2" << '\n';
     }
     else if(N >= 1400 && N <= 1599){
         cout << "Division 3" << '\n';
     }
     else{
         cout << "Division 4" <<'\n';
     }
 }
 return 0;
}