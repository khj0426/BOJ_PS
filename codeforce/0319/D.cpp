#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
 
 
int main(void){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        long long arr[200005];
        long long dp[200005];
        cin >> n >> m;
        //0 1 0 2 03 04 05까지 합
        //
        for(int i = 1;i<=n;i++){
            dp[i] = 0;
            arr[i] = 0;
            long long num;
            cin >> num;
            arr[i] = num;
        }
      
        for(int i = 1;i<=n;i++){
            if(i == 1){
                dp[i] = arr[i];
            }
            else{
                dp[i] = dp[i-1] + arr[i];
            }
          
        }
       
 
        for(int i = 0;i<m;i++){
            int a,b,c;
            cin >> a >> b >> c;
            //2 2 1 3 2 3 2
            //2부터 3까지 합
            //1부터 5에서
            //2부터 3까지 뻄
            //1~2
            //4~5
 
            //1~7
            //4
            //8 - 1~2
            //3~4 --
            //1~4 - 1~2
 
            long long firstQuery = dp[b] - (dp[a-1]);
            long long res = dp[n] - firstQuery;
            
            long long multiply = (b-a+1) * c;
 
            res += multiply;
        
            if(res % 2 != 0){
                cout << "YES" << '\n';
            }
            else{
                cout << "NO" << '\n';
            }

        }
 
    }
}