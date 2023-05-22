#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n;
int arr[1025];

int main(void){
    cin >> n;
    int N = pow(2,n);

    for(int i = 1;i<=N;i++){
        cin >> arr[i];
    }


    //1부터 시작 + 2
    //2부터시작 + 4
    //4부터 시작 + 8
    //8부터 시작 + 16


    //인덱스임
    vector<vector<int>> v;
    for(int i = 0;i<n;i++){
        vector<int> temp;
        for(int j = int(pow(2,i));j<=N;j+=int(pow(2,i+1))){
            temp.push_back(arr[j]);
        
        }
      
        v.push_back(temp);
    }



    for(int i = v.size()-1;i>=0;i--){
        for(int j = 0;j<v[i].size();j++){
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }

    
}