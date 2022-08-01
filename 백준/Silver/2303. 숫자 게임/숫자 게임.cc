#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main(void){
    int arr[1001][5];
    int sums[1001] = {-1, };
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<5;j++){
            cin >> arr[i][j];
        }
    }
    //5개중 3개
    //r->1 n-r -> 0
    vector<int> v;
    vector<int> combinate;
    
    for(int i = 0;i<5;i++){
        v.push_back(i);
    }
    
    for(int i = 0;i<3;i++){
        combinate.push_back(1);
    }
    
    for(int i = 0;i<5-3;i++){
        combinate.push_back(0);
    }
    
    sort(combinate.begin(),combinate.end());
    
    do{
        for(int i = 0;i<n;i++){
            int sum = 0;
            for(int j = 0;j<5;j++){
                if(combinate[j] == 1){
                    sum += arr[i][j];
                }
            }
            string str = to_string(sum);
            
            int N = str[str.size()-1]-48;
            if(N > sums[i]){
                sums[i] = N;
            }
           
        }
    }while(next_permutation(combinate.begin(),combinate.end()));
    
    
    int max_num = 0;
    int max_value = 0;
    for(int i = 0;i<n;i++){
        if(sums[i] >= max_value){
            max_num = i;
            max_value = sums[i];
        }
    }
    cout << max_num + 1;
    
}