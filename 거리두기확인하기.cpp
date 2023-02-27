#include <string>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool validRange(int x,int y){
    if(x >= 5 || y >= 5 || x < 0 || y < 0){
        return false;
    }
    return true;
}
//상하좌우 오른쪽위오른쪽아래 왼쪽위왼쪽아래 //2칸 위 2칸 아래 2칸 왼 2칸 오

int dx[12] = {0,0,-1,1,1,1,-1,-1,0,0,-2,2};
int dy[12] = {1,-1,0,0,1,-1,1,-1,2,-2,0,0};

char map[5][5];
int Endx = 0;
int Endy = 0;
bool pos = false;

void dfs(int x,int y,int depth){
    if(depth > 2){
        return;
    }

    if(x == Endx && y == Endy){
        cout << x << ' ' << y << ' ' << depth << '\n';
        pos = true;
        return;
    }
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        //X라면 파티션에 막히고 O라면 갈수 있음
        if(validRange(nx,ny) && map[nx][ny] != 'X'){
            dfs(nx,ny,depth+1);
        }
    }
}

vector<int> solution(vector<vector<string>> places) {

    vector<int> answer;

    //맨해튼 거리가 2 

    for(int tc = 0;tc<places.size();tc++){
        bool flag = false;
        for(int i = 0;i<5;i++){
            for(int j = 0;j<5;j++){
                map[i][j] = places[tc][i][j];
            }
        }
        for(int p = 0;p<5;p++){
            for(int q = 0;q<5;q++){
                if(map[p][q] == 'P'){
                    //바로 옆이나 위에 붙어있는 경우 바로 위반하는 경우임
                    //거리가 1
                    for(int j = 0;j<4;j++){
                        int nx = p + dx[j];
                        int ny = q + dy[j];
                        if(validRange(nx,ny) && map[nx][ny] == 'P'){
                            flag = true;
                        }
                    }
                    //맨해튼 거리가 2인 경우 
                    //도착 좌표를 넣어두고 dfs로 갈 수 있는지 확인
                    for(int j = 4;j<12;j++){
                        int nx = p + dx[j];
                        int ny = q + dy[j];
                        if(validRange(nx,ny) && map[nx][ny] == 'P'){
                            //도착 좌표 초기화
                            Endx = nx;
                            Endy = ny;
                            pos = false;
                            dfs(p,q,0);
                            //시작으로부터 도착까지 거리가 2이하로 도착한 경우
                            if(pos){
                                flag = true;
                            }
                        }
                    }
                }
            }
        }
        if(flag){
            answer.push_back(0);
        }
        else{
            answer.push_back(1);
      }
    }
    return answer;

}