#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int map[101][101];
int n,m;
 
void input(){
	cin >> n >> m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin >> a >> b;
		map[a][b] = 1; //a번 구슬이 b번보다 무거움
		map[b][a] = -1; //b번 구슬이 a번 구슬보다 가벼움
	}		
}
 
void solve(){
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(map[i][k] == 1 && map[k][j] == 1){ //무거운 구슬
					map[i][j] = 1;
 
				}
				if(map[i][k] == -1 && map[k][j] == -1){ //가벼운 구슬
					map[i][j] = -1;
				}
			}
		}
	}
}
 
int main(void){
	input();
	solve();
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		int left = 0; //i번 구슬보다 무거운 구슬의 수
        int right = 0; //i번 구슬보다 가벼운 구슬의 수
 
		for(int j = 1;j<=n;j++){
            if(i == j){ //같은 구슬 제외하고
                continue;
            }
			if(map[i][j] == 1){ //j가 더 무거운 경우
				left++;
			}
            else if(map[i][j] == -1){ //j가 더 가벼운 경우
                right++;
            }
       
		}
        /*무거운 구슬의 수가 과반수 또는 가벼운 구슬의 수가 과반수 넘어가면 중간 불가 */
        
		if((n / 2 < left) || (n / 2 < right)){
			cnt++;
		}
       
         
	}
	cout << cnt;
}