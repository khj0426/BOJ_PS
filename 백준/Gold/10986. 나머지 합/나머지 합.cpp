#include <iostream>
using namespace std;

typedef long long ll;
int main(void){
	ll arr[1000001] = {0, }; //입력받을 배열
	ll dp[1000001] = {0, }; //누적합 배열
	ll mod_dp[1000011] = {0, }; //누적합 MOD연산 한 배열

	ll n,m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++){ /*누적합 계산 */
		cin >> arr[i];
		if(i == 1){
			dp[i] = arr[i];
		}
		else{
			dp[i] = dp[i] + arr[i] + dp[i-1];
		}
		
	}
	ll cnt = 0;
	for(int i = 1;i<=n;i++){
		dp[i] = dp[i] % m;
		if(dp[i] == 0){ //0이 되는 경우 따로 처리 필요
			cnt++;
		}
		
		mod_dp[dp[i]]++; //누적합 MOD배열에 값 저장
	}
	
	for(int i = 0;i<=n-1;i++){ //경우의 수 계산
		cnt += (mod_dp[i] * (mod_dp[i] - 1)) / 2;
	
	}
	cout << cnt;
}