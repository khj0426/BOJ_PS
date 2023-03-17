#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> arr;
    vector<int> answerArr;

    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }

    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        answerArr.push_back(num);
    }
    
     if(arr == answerArr){
         cout << 1;
         return 0;
     }

    for(int i = n-1;i>=1;i--){
        bool flag = false;
        for(int j = 0;j<n-1;j++){
            if(arr[j] > arr[j+1]){
                flag = true;
                swap(arr[j],arr[j+1]);
                if(arr[j] == answerArr[j]){
                    if(arr == answerArr){
                         cout << 1;
                        return 0;
                    }
                }
            }
        }
        if(flag == false){
            break;
        }
    }

    cout << 0;
    return 0;
}