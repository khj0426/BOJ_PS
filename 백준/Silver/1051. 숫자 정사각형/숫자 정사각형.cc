#include <iostream>
using namespace std;
int n,m;
char map[51][51];
int ans = 0;
 
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
 
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
 
int check_(int x,int y,int size){
 
    if(x + size - 1 > n || y + size - 1 > m){
        return -1;
    }
 
     char dx[4] = {0, };
     dx[0] = map[x][y];
     dx[1] = map[x+size-1][y];
     dx[2] = map[x][y+size-1];
     dx[3] = map[x+size-1][y+size-1];
 
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(dx[i] != dx[j]){
                return -1;
            }
        }
    }
 
 
    return size;
}
 
int main(void){
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> map[i][j];
        }
    }
 
    int min_value = min(n,m);
    for(int i = 1;i<=min_value;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=m;k++){
                int N = check_(j,k,i);
                if(N != -1){
                    ans = max(ans,N*N);
                }
            }
        }
    }
    cout << ans;
}