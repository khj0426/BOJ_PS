#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int MIN_VALUE = 987654321;
int MAX_VALUE = -987654321;
int n;
int arr[11];
vector<int> number;
 
void input(){
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    for(int i = 1;i<=4;i++){
        int nextnum;
        cin >> nextnum;
        number.push_back(nextnum);
    }
 
}
 
void dfs(int start,int sum){
 
 
    if(start == n-1){
    	MAX_VALUE = max(sum,MAX_VALUE);
    	MIN_VALUE = min(sum,MIN_VALUE);
 
    	return;
    }
 
    for(int i = 0;i<number.size();i++){
        if(number[i] >= 1){
            number[i]--;
            if(i == 0){
                dfs(start+1,sum+arr[start+1]);
            }
            else if(i == 1){
                dfs(start+1,sum-arr[start+1]);
            }
            else if(i == 2){
                dfs(start+1,sum*arr[start+1]);
            }
            else if(i == 3){
                dfs(start+1,sum/arr[start+1]);
            }
            number[i]++;
 
        }
    }
}
 
int main(void){
    input();
    dfs(0,arr[0]);
    cout << MAX_VALUE << '\n';
    cout << MIN_VALUE;
}