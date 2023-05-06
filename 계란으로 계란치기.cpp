#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
    조건을 만족하지 않더라도 계속 탐색을 이어가야함 -> 이 경우를 위해 flag변수를 두자!
    두 계란이 깨진 상태라면 , 아예 계란을 치지 못하므로, 두 계란이 깨지지 않은 상태에서,
    비교해야함
*/
 
int n;
int maxCnt = 0;
bool visited[10];
vector<pair<int,int>> eggs; // 내구도와 무게
 
void dfs(int index, int sum) {
    if (index > n) {
        return;
    }
    
    //오른쪽 끝까지 도착한 경우
    if (index == n) {
        int cnt = 0;
        //꺠진 계란이 존재하면 카운트
        for(int i = 0;i<n;i++){
            if(eggs[i].first <= 0){
                cnt++;
            }
        }
        //카운터 값 갱신
        maxCnt = max(cnt,maxCnt);
        return;
    }
 
    bool flag = false;
    for (int i = 0; i < n; i++) {
        //같은 계란이 아닌 경우
        if (i != index) {
            // 내구도가 상대 계란의 무게만큼 깎임
            int currentS = eggs[index].first - eggs[i].second;
            
            //두 계란이 깨지지 않은 상태에서 비교함
            if ( eggs[i].first > 0 && eggs[index].first > 0) {
                eggs[index].first = currentS;
                eggs[i].first -= eggs[index].second;
                flag = true;
                //계란을 칠 수 있는 경우 flag설정
                dfs(index+1, sum+1);
                eggs[index].first += eggs[i].second;
                eggs[i].first += eggs[index].second;
 
            }
        }
    }
    
    //계란을 칠 수 없는 경우 설정
    if(flag == false){
        dfs(index+1,sum);
    }
}
 
int main(void) {
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        int S, W;
        cin >> S >> W;
        eggs.push_back({S, W});
    }
 
    dfs(0, 0);
    cout << maxCnt;
}