#include <iostream>
//1번 ~ N번
// 악보별로 1이상 10^9이하의 정수로 표현됨
//난이도가 클수록 어렵다
//xy두 게를 골라서 x번부터 y번까지 악보를 연주함

//지금연주하는게 다음번보다 어려우면 실수를 함

//i  > i+1 -? > 실수를 함

//실수하는 곡을 고르셈

//1 2 3 3 4 1 10 8 1
//13
//25
//47
//...
//dp[i] -> i번까지 실수를 몇번? 
// 1 2 3 3 4 1 10 8 1
// 0 0 0 0 1 0 1 1

#include <algorithm>
using namespace std;

int sum[100001];
int dp[100001];
int arr[100001];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
    }

    for(int i = 1;i<=n;i++){
        if(i != n && arr[i] > arr[i+1]){
            dp[i] = 1;
        }
    }

    for(int i = 1;i<=n;i++){
        if(i == 1){
            sum[i] = dp[i];
        }
        else{
            //0 1 2 2 3
            sum[i] = sum[i-1] + dp[i];
        }
        cout << sum[i] << ' ';
    }
    cout << '\n';

    int Q;
    cin >> Q;
    for(int i = 0;i<Q;i++){
        int x,y;
        cin >> x >> y;
        //y번까지 실수 몇번?
        //x번까지 실수 몇번?

        //0 1 1 0 1
        //0 1 2 2 3

        //0 1 2 2 3 3
        cout << sum[y-1] - sum[x-1] << '\n';
    }




}

