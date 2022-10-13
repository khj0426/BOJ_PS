 #include <iostream>
using namespace std;
 
 
 int arr[1025][1025];
int dp[1025][1025];
 
int main(void){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin >> n >> m;
 
    int temp = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> arr[i][j];
        }
    }
 
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){    
               dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j]; 

        }
    }
 
    for(int i = 0;i<m;i++){
        int x,y,x2,y2;
        cin >> x >> y >> x2 >> y2;  
        int diff = dp[x2][y2] - dp[x-1][y2] - dp[x2][y-1] + dp[x-1][y-1];
        cout << diff << '\n';
    }
}