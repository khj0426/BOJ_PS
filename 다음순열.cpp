#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> arr;
vector<int> copy_arr;
int main(void){
    cin >> n;
    for(int i = 0;i<n;i++){
        int element;
        cin >> element;
        arr.push_back(element);
    }
    copy_arr = arr;
    int first = 0;
    do{
        if(first == 1){
            break;
        }
        first++;
 
    }while(next_permutation(copy_arr.begin(),copy_arr.end()));
 
    bool valid = false;
    for(int i = 0;i<arr.size();i++){
        if(arr[i] - arr[i+1] != 1){
            valid = true;
            break;
        }
    }
    if(valid == false){
        cout << -1;
    }
    else{
        for(int i = 0;i<copy_arr.size();i++){
            cout << copy_arr[i] << ' ';
        }
    }
 
 
 
 
}