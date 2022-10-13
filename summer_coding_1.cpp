#include <string>
#include <vector>
#include <iostream>
using namespace std;
 
char arr;
int bad[2100];
 
int solution(vector<vector<int>> atmos) {
    int answer = 0;
    return answer;
}
int main(void){
    string wter;
    int count = 1;
    while(!cin.eof()){
        cin >> arr;
        if(arr >= '0' && arr <= '9'){
            wter = wter + arr;
        }
        else if(arr == ','){       
           bad[count] = stoi(wter);      
            count++;
            wter = "";
        }
 
    }
    bad[count] = stoi(wter);
 
 
 
    bool change = false;
    int day = 0;
    int CN = 0;
 
   for(int i = 1;i<=count;i=i+2){
 
       if(bad[i] <= 80 && bad[i+1] <= 35){
               continue;
 
       }
       else if((bad[i] >= 81 && bad[i] <= 150) ||(bad[i+1] >= 36 && bad[i+1] <= 75)){
           if(change == false){
               change = true;
               CN++;
               day++;
           }
           else if(change == true){
               day++;
               if(day == 3){
 
                   day = 0;
                   CN++;
               }
           }
 
       }
       else if(bad[i] >= 151 && bad[i+1] >= 76){
           CN++;
       }
 
   }
   cout << CN;
 
    }