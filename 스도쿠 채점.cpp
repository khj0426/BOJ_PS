#include <iostream>
#include <algorithm>
 
using namespace std;
 
int arr[10][10];
int t;
bool findNum[10];
 
void inputCase(){
    cin >> t;
}
 
void inputArr(){
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
             cin >> arr[i][j];
             findNum[j] = false;
        }     
    }
}
 
int Check_row(){
   for(int i = 0;i<9;i++){
         fill(findNum,findNum + 10,false);
        for(int j = 0;j<9;j++){
            findNum[arr[i][j]-1] = true;
        }
    for(int k = 0;k<9;k++){
        if(findNum[k] == false){
            return 1;
        }
    }    
   }
   return 0;
}
 
int Check_column(){
    for(int i = 0;i<9;i++){
        fill(findNum,findNum + 10,false);
        for(int j = 0;j<9;j++){
            findNum[arr[j][i]-1] = true;
        }
         for(int k = 0;k<9;k++){
            if(findNum[k] == false){
                return 1;
            }
        }    
   }
   return 0;
}
 
int Check_board(){
    for(int i = 0;i<9;i+=3){
 
        for(int j = 0;j<9;j+=3){
            fill(findNum,findNum + 10,false);
            for(int p = i;p<i+3;p++){
                for(int q = j;q<j+3;q++){
                    findNum[arr[p][q]-1] = true;
                }
            }
             for(int k = 0;k<9;k++){
                if(findNum[k] == false){
                return 1;
                }
            }
       
         }    
    }
    return 0;
}
 
int main(void){
    inputCase();
    for(int i = 0;i<t;i++){
        inputArr();
        if(Check_column() == 1){
            cout << "Case " << i+1 << ": INCORRECT" << '\n';
        }
        else if(Check_row() == 1){
            cout << "Case " << i+1 << ": INCORRECT" << '\n';
        }
        else if(Check_board() == 1){
            cout << "Case " << i+1 << ": INCORRECT" << '\n';
        }
        else{
        	 cout << "Case " << i+1 << ": CORRECT" << '\n';
        }
    }
}