#include <iostream>
 
using namespace std;
 
int main(void){
    int n,m;
    cin >> n >> m;
    int card[100];
    for(int i = 0;i<n;i++){
        cin >> card[i];
    }
 
    int min_sum = -1;
    bool is_equal = false;
 
    for(int i = 0;i<n;i++){
        int current_sum = 0;
        for(int j = i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                current_sum = card[i] + card[j] + card[k];  
                if(current_sum > m){
                    continue;
                }
                else{
                    if(current_sum == m){
                        is_equal = true;
                        min_sum = current_sum;
                        break;
                    }
                    else if(current_sum < m){
                        if(current_sum > min_sum){
                            min_sum = current_sum;
                        }
                    }
                }
            }
            if(is_equal == true){
                break;
            }
            
        }
        if(is_equal == true){
            break;
        }
       
    }
 
    cout << min_sum;
}