#include <iostream>
#include <algorithm>
using namespace std;
 
//사탕의 색이 다른 인접한 두 칸을 고른다
//고른칸에 있는 사탕을 바꾼다
//모두 같은 색으로 이루어져 있는 가장 긴 연속 부분을 고르고 사탕을 먹는다
 
 
int n;
char c[51][51];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
 

int FindCharNum(char ch){
    int ans = 0;
    for(int i = 0;i<n;i++){
        int cnt = 0;
        for(int j = 0;j<n;j++){
            if(c[i][j] == ch){
                cnt++;
            }
            else{
                ans = max(cnt,ans);
                cnt = 0;
            }
        }
        ans = max(cnt,ans);
    }

    for(int i = 0;i<n;i++){
        int cnt = 0;
        for(int j = 0;j<n;j++){
            if(c[j][i] == ch){
                cnt++;
            }
            else{
                ans = max(cnt,ans);
                cnt = 0;
            }
        }
        ans = max(cnt,ans);
    }
    return ans;
}

int Calculate(){
    int ans = 0;
    ans = max(FindCharNum('C'),ans);
    ans = max(FindCharNum('P'),ans);
    ans = max(FindCharNum('Z'),ans);
    ans = max(FindCharNum('Y'),ans);
    return ans;
}
 
int main(void){
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> c[i][j];
        }
    }
    int maxSize = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            //왼쪽 색깔 다른 경우
            if(c[i][j] != c[i-1][j] && i-1 >= 0){
                swap(c[i][j],c[i-1][j]);
                maxSize = max(maxSize,Calculate());
                swap(c[i][j],c[i-1][j]);
            }
             if(c[i][j] != c[i+1][j] && i+1 < n){
                swap(c[i][j],c[i+1][j]);
                maxSize = max(maxSize,Calculate());
                swap(c[i][j],c[i+1][j]);
            }
 
              if(c[i][j] != c[i][j-1] && j-1 >= 0){
                swap(c[i][j],c[i][j-1]);
                maxSize = max(maxSize,Calculate());
                swap(c[i][j],c[i][j-1]);
            }
 
             if(c[i][j] != c[i][j+1] && j+1 < n){
                swap(c[i][j],c[i][j+1]);
                maxSize = max(maxSize,Calculate());
                swap(c[i][j],c[i][j+1]);
            }
        }
    }
    cout << maxSize;
}