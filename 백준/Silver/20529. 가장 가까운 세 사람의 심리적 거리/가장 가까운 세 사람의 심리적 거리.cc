#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> v;
        vector<int> s;
        for(int i = 0;i<n;i++){
            string s;
            cin >> s;
            v.push_back(s);
        }
        for(int i = 0;i<3;i++){
            s.push_back(1);
        }
        for(int i = 0;i<n-3;i++){
            s.push_back(0);
        }
        sort(s.begin(),s.end());
        vector<string> temp;
        int ans = 987654321;
        do{
            temp.clear();
            for(int i = 0;i<n;i++){
                if(s[i] == 1){
                    temp.push_back(v[i]);
                }
            }
            int diff = 0;
            for(int i = 0;i<temp.size();i++){
                for(int j = i+1;j<temp.size();j++){
                    for(int k = 0;k<4;k++){
                        if(temp[i][k] != temp[j][k]){
                            diff++;
                        }
                    }    
                }
                
            }
            if(ans > diff){
                ans = diff;
                if(ans == 0){
                    break;
                }
            }
        }while(next_permutation(s.begin(),s.end()));
        cout << ans << '\n';
    }
}