#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

//백준 2870 수학숙제
 
using namespace std;
 
bool cmp(string a, string b) {
	if (a.size() == b.size()) { //a,b의 길이가 같으면 사전순으로
		return a < b;
	}
	return a.size() < b.size(); //길이가 작은 순서대로
}
 
int main(void){
    string arr[1000];
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
 
     int index = 0;
    string str[1000];
 
    for(int i = 0;i<n;i++){
        string temp = "";
        bool is_char = false;
        for(int j = 0;j<arr[i].length();j++){
            if(isdigit(arr[i][j]) == 0){
                is_char = true;
                if(temp != ""){
                str[index] = temp;
                index++;
                temp = "";
                }
            }
           else if(isdigit(arr[i][j])!= 0){
               temp = temp + arr[i][j];
            }
        }
        if(temp !=  ""){
            str[index] = temp;
            index++;
        }
    }
 
 
    for(int i = 0;i<index;i++){
 
        string temp = "";
        int zero = 1000;
        int first = 1000;
        for(int j = 0;j<str[i].length();j++){
               if(str[i][j] == '0'){
                   if(first == 1000){
                       continue;
                   }
                   else{
                       temp = temp + str[i][j];
                   }
               }
            else{
                first = j;
                temp = temp + str[i][j];
            }
        }
 
        if(first == 1000){
            str[i] = "0";
        }
        else{
            str[i] = temp;
        }
 
    }
    sort(str,str+index,cmp);
    for(int i = 0;i<index;i++){
        cout << str[i] << '\n';
    }
 
 
 
}