#include <iostream>
using namespace std;

//코드포스 round 799 C번
//https://codeforces.com/contest/1692/problem/C
 
bool visited[10][10];
bool first_input[10][10];
int dx[4] = {1,1,-1,-1};
int dy[4] = {-1,1,1,-1};
 
int t;
void init(){
    for(int i = 1;i<=8;i++){
        for(int j = 1;j<=8;j++){
            visited[i][j] = false;
        }
    }
}
 
void dfs(int x,int y){
 
	if(visited[x][y]){
		return;
	}
	visited[x][y] = true;
 
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || ny < 1 || nx > 8 || ny > 8){
                continue;
            }
			if(first_input[nx][ny] == true){
 
				dfs(nx,ny);
			}
 
 
        }
    }
}
 
int check_same(){
    for(int i = 1;i<=8;i++){
        for(int j = 1;j<=8;j++){
            if(visited[i][j] != first_input[i][j]){
 
                return -1;
            }
        }
    }
 
 
    return 1;
}
int main(void){
    int t;
    cin >> t;
    while(t--){
        for(int i = 1;i<=8;i++){
            for(int j = 1;j<=8;j++){
                char c;
                cin >> c;
                if(c == '#'){
                    first_input[i][j] = true;
                }
                else{
                    first_input[i][j] = false;
                }
            }
        }
        bool is_find = false;
        int r = 0;
        int c = 0;
        for(int i = 1;i<=8;i++){
            for(int j = 1;j<=8;j++){
                if(i != 1 && i != 8 && j != 1 && j != 8){
                    init();
                    dfs(i,j);
                    int N = check_same();
                    if(N == 1){
                    	bool valid = false;
                        for(int k = 0;k<4;k++){
                        	int nx = i + dx[k];
                        	int ny = j + dy[k];
                        	if(visited[nx][ny] == false){
                        		valid = true;
                        		break;
                        	}
                        }
                        if(valid == false){
                        	cout << i << ' ' << j << '\n';
                        	break;
                        }
 
                    }
                }
            }
 
        }
 
    }
}