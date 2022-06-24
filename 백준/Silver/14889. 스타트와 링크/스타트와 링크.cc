#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main(void){
    int n;
    int map[21][21];
    cin >> n;
    vector<int> v;
    for(int i = 0;i<n;i++){
        v.push_back(i);
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
        }
    }
    
    vector<int> combinate;
    for(int i = 0;i<n/2;i++){
        combinate.push_back(1);
    }
    
    for(int i = 0;i<v.size()-n/2;i++){
        combinate.push_back(0);
    }
    
    sort(combinate.begin(),combinate.end());
    int ans = 987654321;
    int start,link = 0;
    do{
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i != j){
                    if(combinate[i] == 1 && combinate[j] == 1){
                       start = start + map[i][j];
                   }
                   else if(combinate[i] == 0 && combinate[j] == 0){
                       link = link + map[i][j];
                   }
                }
            }
        }
   
        
      
        if(abs(start-link) < ans){
            ans = abs(start-link);
        }
        
        start = 0;
        link = 0;
    }while(next_permutation(combinate.begin(),combinate.end()));
    
    cout << ans;
}