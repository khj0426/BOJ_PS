#include <iostream>
#include <string>

//백준 잃어버린 괄호
 
using namespace std;
 
int main(void){
    string str;
    cin >> str;
 
    string temp;
    bool is_negative = false;
    int sum = 0;
 
   for(int i = 0;i<str.size();i++){
       if(str[i] != '-' && str[i] != '+'){
           temp = temp + str[i];
       }
       else if(str[i] == '-'){
 
           if(is_negative == true){
           sum = sum - stoi(temp);
           temp = "";
             }
           else if(is_negative == false){
               sum = sum + stoi(temp);
               temp = "";
           }
           is_negative = true;
 
       }
       else if(str[i] == '+'){
           if(is_negative == false){
               sum = sum + stoi(temp);
               temp = "";
           }
           else if(is_negative == true){
               sum = sum - stoi(temp);
               temp = "";
           }
       }
       
   }
    
    if(is_negative == true){
        sum = sum - stoi(temp);
        temp = "";
    }
    else if(is_negative == false){
        sum = sum + stoi(temp);
        temp = "";
    }
     cout << sum;
 
}