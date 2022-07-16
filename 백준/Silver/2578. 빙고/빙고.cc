#include <iostream>
using namespace std;

int map[5][5];
int check_bingo(){
    int num_of_bingo = 0;
    for(int i = 0;i<5;i++){
        bool valid = false;
        for(int j = 0;j<5;j++){
            if(map[i][j] != 0){
                valid = true;
                break;
            }
        }
        if(valid == false){
            num_of_bingo++;
        }
    }
    
    for(int i = 0;i<5;i++){
        bool valid = false;
        for(int j = 0;j<5;j++){
            if(map[j][i] != 0){
                valid = true;
                break;
            }
        }
        if(valid == false){
            num_of_bingo++;
        }
    }
    
   bool valid = false;
    for(int i = 0;i<5;i++){
        if(map[i][i] != 0){
            valid = true;
        }
        if(valid == true){
            break;
        }
    }
    
    if(valid == false){
        num_of_bingo++;
    }
    
    valid = false;
    
    for(int i = 4;i>=0;i--){
        if(map[i][4-i] != 0){
            valid = true;
            break;
        }
    }
    if(valid == false){
        num_of_bingo++;
    }
    
    if(num_of_bingo >= 3){
        return 1;
    }
   return -1;
}
int main(void){
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            cin >> map[i][j];
        }
    }
    
    int first = 1;
    int x;
    
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            
            cin >> x;
            first++;
            bool is_find = false;
            
            for(int k = 0;k<5;k++){
                for(int q = 0;q<5;q++){
                    if(map[k][q] == x){
                        is_find = true;
                        map[k][q] = 0;

                    }
                }

            }
            
            if(check_bingo() == 1){
                cout << first - 1;
                return 0;
            }
        }
    }
}