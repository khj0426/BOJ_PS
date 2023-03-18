#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


bool isSame(char a,char b,char c){
    if(a == b && a == c && b == c){
        return true;
    }
    return false;
}

int calculateNum(vector<string> board,char c){
    int numofX = 0;
    for(int i = 0;i<board.size();i++){
        for(int j = 0;j<board[i].size();j++){
            if(board[i][j] == c){
                numofX++;
            }
        }
    }
    return numofX;
}


int solution(vector<string> board) {
    int answer = -1;
    
    //승부가 난 경우 + O가 이긴 경우
    // X의 개수가 O-1
    // X가 이긴 경우 존재 X
    // O가 이긴 경우가 2개 나오는 경우
    
    int caseoWin[4] = {0,0,0,0};
    int casexWin[4] = {0,0,0,0};
    int sumofFlag = 0;
    
    for(int i = 0;i<board.size();i++){
        if(isSame(board[i][0],board[i][1],board[i][2]) && board[i][0] == 'O'){
            caseoWin[0]++;
            
        }
    }

    for(int i = 0;i<board.size();i++){
        if(isSame(board[0][i],board[1][i],board[2][i]) && board[0][i] == 'O'){
            caseoWin[0]++;
          
        }
    }
    
    if(isSame(board[0][0],board[1][1],board[2][2]) && board[0][0] == 'O'){
        caseoWin[2] = 1;
        
    }
    
     if(isSame(board[0][2],board[1][1],board[2][0]) && board[0][2] == 'O'){
        caseoWin[3]++;
       
    }
   
   
    for(int i = 0;i<board.size();i++){
        if(isSame(board[i][0],board[i][1],board[i][2]) && board[i][0] == 'X'){
            casexWin[0]++;
           
        }
    }
    
    for(int i = 0;i<board.size();i++){
        if(isSame(board[0][i],board[1][i],board[2][i]) && board[0][i] == 'X'){
            casexWin[1]++;
           
        }
    }
    
    if(isSame(board[0][0],board[1][1],board[2][2]) && board[0][0] == 'X'){
        casexWin[2]++;
        
    }
    
     if(isSame(board[0][2],board[1][1],board[2][0]) && board[0][2] == 'X'){
        casexWin[3]++;
        
    }
    
    int o = 0;
    int x = 0;
    for(int i = 0;i<4;i++){
        if(caseoWin[i] > 0){
            o += caseoWin[i];
        }
        if(casexWin[i]){
            x += casexWin[i];
        }
    }
 
    if(o > 0 && x > 0){
        return 0;
    }
    if(o > x){
        if(calculateNum(board,'O') - 1 != calculateNum(board,'X')){
            return 0;
        }
    }
    
    if(x > o){
        if(calculateNum(board,'O')  != calculateNum(board,'X')){
            return 0;
        }
    }
     if(calculateNum(board,'X') > calculateNum(board,'O') || calculateNum(board,'O') - calculateNum(board,'X') > 1)
            return 0;
  
    
    return 1;
}