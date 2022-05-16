#include <iostream>
#include <map>
#include <string>
using namespace std;
int n,k;
string arr[11];
bool visited[11];
map<int,int> m;
string A[11];
 
void dfs(int start){
    if(start == k){
        int number = 0;
        string temp = "";
        for(int i = 0;i<n;i++){
            temp = temp + arr[i];
        }
        number = stoi(temp);
        m.insert(pair<int,int>(number,number));
        return;
    }
    for(int i = 0;i<n;i++){
        if(visited[i] == false){
            visited[i] = true;
            arr[start] = A[i];
            dfs(start+1);
            visited[i] = false;
        }
    }
 
}
int main(void){
    cin >> n;
    cin >> k;
    for(int i = 0;i<n;i++){
        cin >> A[i];
    }
    dfs(0);
    cout << m.size();
}