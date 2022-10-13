#include <iostream>
#include <string>
#include <vector>
using namespace std;

int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

int check_prime(int N){
    for(int i = 2;i*i<=N;i++){
        if(N%i == 0){
            return -1; //소수가 아닌 경우
        }
    }
    return 1;
}


int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[10001];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        int ans = 987654321;
        vector<int> ans_v;
        
        for(int i = 0;i<n;i++){
            vector<int> v;
            int temp_sum = arr[i];
            v.push_back(arr[i]);
            
            for(int j = i+1;j<n;j++){
                v.push_back(arr[j]);
                temp_sum += arr[j];
                if(check_prime(temp_sum) == 1){
                    if(ans > j-i + 1){
                        ans = j-i + 1;
                        ans_v = v;
                        break;
                    }
                }
            }
        }
        
        
       if(ans != 987654321){
           cout << "Shortest primed subsequence is length" << ' ' << ans << ':';
           for(int i = 0;i<ans_v.size();i++){
               cout << ' ' << ans_v[i];
           }
           cout << '\n';
       }
        else{
            
        cout << "This sequence is anti-primed." << '\n';
    
        }
    }
     
}