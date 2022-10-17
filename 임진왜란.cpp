#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

map<string,int> order; //문자열-번호 매핑
vector<string> ans; //제출한 답안
int n;

void input(){
    cin >> n;
    int first = 0;
    for(int i = 0;i<n;i++){
        string str;
        cin >> str;
        order[str] = first;
        first++;
    }
    for(int i = 0;i<n;i++){
        string str;
        cin >> str;
        ans.push_back(str);
    }


}

int solve(){
    int ans = 0;
    for(int i = 0;i<ans.size();i++){
        for(int j = i+1;j<ans.size();j++){
            if(order[ans[i]] < order[ans[j]]){
                ans++;
            }
        }
    }
    return ans;
}

int main(void){
    int total = n*(n-1)/2;

    input();
    cout << solve() << '/' << total;
}