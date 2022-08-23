#include <iostream>
#include <string>
using namespace std;
int sums[27][200001];
int dp_sum[27][200001];
 
int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
    string str;
    cin >> str;
 
    for(int i = 0;i<str.size();i++){
        char c = str[i];
        sums[c-'a'][i] = 1;
    }
 
    for(int i = 0;i<27;i++){
        for(int j = 0;j<str.size();j++){
            if(j == 0){
                dp_sum[i][j] = sums[i][j];
            }
            else{
                dp_sum[i][j] += sums[i][j];
                dp_sum[i][j] += dp_sum[i][j-1];
            }
 
        }
 
    }
    int query;
    cin >> query;
    for(int i = 0;i<query;i++){
        char ap;
        cin >> ap;
        int start,end;
        cin >> start >> end;
        int diff = dp_sum[ap-'a'][end] - dp_sum[ap-'a'][start-1];
        cout << diff << '\n';
 
    }
 
 
}