#include <iostream>
#include <string>
using namespace std;

 
int ydl,ydo,ydv,yde;
 
int main(void){
    int max = -1;
    string yd;
    cin >> yd;
    for(int i = 0;i<yd.size();i++){
        if(yd[i] == 'L'){
            ydl++;
        }
        else if(yd[i] == 'O'){
            ydo++;
        }
        else if(yd[i] == 'V'){
            ydv++;
        }
        else if(yd[i] == 'E'){
            yde++;
        }
    }
 
    int n;
    cin >> n;
 
    string ans = "";
    for(int i = 0;i<n;i++){
        string str;
        cin >> str;
        int arr[4] = {0,0,0,0};
 
        for(int j = 0;j<str.size();j++){
            if(str[j] == 'L'){
                arr[0]++;
            }
            else if(str[j] == 'O'){
                arr[1]++;
            }
            else if(str[j] == 'V'){
                arr[2]++;
            }
            else if(str[j] == 'E'){
                arr[3]++;
            }
        }
        arr[0] = arr[0] + ydl;
        arr[1] = arr[1] + ydo;
        arr[2] = arr[2] + ydv;
        arr[3] = arr[3] + yde;
 
 int sum = ((arr[0]+arr[1])*(arr[0]+arr[2])*(arr[0]+arr[3])*(arr[1]+arr[2])*(arr[1]+arr[3])*(arr[2]+arr[3]))%100;
        if(sum > max){
            ans = str;
            max = sum;
        }
        else if(sum == max){
            if(str < ans){
                ans = str;
            }
        }
 
    }
   cout << ans;
}