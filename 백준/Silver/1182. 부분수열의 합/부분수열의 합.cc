#include <iostream>

//백준 부분수열의 합
using namespace std;
int n,s;
int arr[20];
int cnt = 0;
 
void dfs(int start,int sum){ //재귀의 종료 조건 start가 n일때
    if(start == n){
        return;
    }
    else if(sum + arr[start] == s){ //sum과 arr[start]의 합이 s라면 count증가
        cnt++;
    }
    dfs(start+1,sum+arr[start]); //현재 start를 더하는경우
    dfs(start+1,sum); //건너뛰는 경우
}
int main(void){
    cin >> n >> s;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    dfs(0,0);
    cout << cnt;
}