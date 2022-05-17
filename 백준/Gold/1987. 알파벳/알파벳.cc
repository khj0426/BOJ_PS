#include <iostream>
#include <vector>
#include <string>
#define MAX 21
 
using namespace std;

int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
char Map[MAX][MAX];
bool visited[MAX][MAX]; 
int sum;
bool alpha[91];
 
int r,c;
int dx[4] = {1,0,-1,0}; //오른쪽 밑 왼쪽 위
int dy[4] = {0,-1,0,1};
 
void dfs(int x,int y,int depth){
 
    sum = max(depth,sum);
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx>= r || ny>= c){
            continue;
        }
     
 
        
        if(alpha[Map[nx][ny] - 'A'] == false){
            alpha[Map[nx][ny]-'A'] = true;
            dfs(nx,ny,depth+1);
            alpha[Map[nx][ny] - 'A'] = false;
 
        }
        }
 
 
 
}
 
 
int main(void){
     cin >> r >> c;
    for (int i = 0; i < r; i++) {
           string s;
           cin >> s;
        for (int j = 0; j < c; j++) {
            Map[i][j]=s[j];
        }
    }
    alpha[Map[0][0]-'A'] = true;
    dfs(0,0,1);
     cout << sum;
}