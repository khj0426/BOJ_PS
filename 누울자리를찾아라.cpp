#include <iostream>
#include <algorithm>

using namespace std;

char map[101][101];
int main(void){
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
        }
    }

    int row = 0;
    int column = 0;
    //가로 확인
    for(int i = 0;i<n;i++){
        int cnt = 0;
        bool flag = false;
        for(int j = 0;j<n;j++){
            if(map[i][j] == '.'){
                cnt++;
            }
            else{
                if(cnt >= 2){
                    row++;
                    flag = true;
                }
                cnt = 0;
            }
        }
        if(cnt >= 2 ){
            row++;
        }
    }

    //세로 확인
    for(int i = 0;i<n;i++){
        int cnt = 0;
        bool flag = false;

        for(int j = 0;j<n;j++){
            if(map[j][i] == '.'){
                cnt++;
            }
            else{
                if(cnt >= 2){
                    flag = true;
                    column++;
                }
                cnt = 0;
            }
        }
        if( cnt  >= 2){
            column++;
        }
    }

    cout << row << ' ' << column << '\n';



}