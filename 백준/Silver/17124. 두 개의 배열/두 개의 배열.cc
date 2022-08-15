#include <iostream>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int min(int a,int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}
 
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);


    vector<int> A;
    vector<int> B;
    
 
    int t;
    cin >> t;
    while(t--){
        A.clear();
        B.clear();
        ll sum = 0;
        int n,m;
        cin >> n >> m;
        for(int i = 0;i<n;i++){
            int x;
            cin >> x;
            A.push_back(x);
          
        }
        for(int i = 0;i<m;i++){
            int x;
            cin >> x;
            B.push_back(x);
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        vector<int>::iterator iter;
       
        
        for(int i = 0;i<n;i++){
            iter = lower_bound(B.begin(),B.end(),A[i]);
            
            if(iter-B.begin() > m-1){
                sum += B[B.size()-1];
            }
            else{
                if(iter-B.begin() == 0){
                    sum += B[iter-B.begin()];
                }
                else{
                    int first_value = abs(A[i] - B[iter-B.begin()]);
                    int second_value = abs(A[i] - B[iter-B.begin() - 1]);
                    if(first_value < second_value){
                        sum += B[iter-B.begin()];
                    }
                    else{
                        sum += B[iter-B.begin()-1];
                    }
                }
               
            }
        }
        cout << sum << '\n';
 
    }
 
}
