#include <iostream>
#include <vector>

using namespace std;

int n;
char map[130][130];

int blue = 0;
int white = 0;

void solve(int x,int y,int size){
    if(size == 1){
        if(map[x][y] == '0'){
            white++;

        }
        else{
            blue++;
        }
        return;
    }
    bool flag = false;

    for(int i = x;i<x+size;i++){
        for(int j = y;j<y+size;j++){
            if(map[i][j] != map[x][y]){
                flag = true;
                break;
            }
        }
        if(flag == true){
            break;
        }
    }

    if(flag == false){
        if(map[x][y] == '0'){
            white++;
        }
        else{
            blue++;
        }
    }
    else{
        int newSize = size/2;
        solve(x+newSize,y,newSize);
        solve(x,y+newSize,newSize);
        solve(x+newSize,y+newSize,newSize);
        solve(x,y,newSize);
    }
}


int main(void){
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
        }
    }
    solve(0,0,n);
    cout << white << '\n';
    cout << blue << '\n';

}