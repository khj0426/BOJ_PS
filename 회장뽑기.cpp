#include <iostream>
#include <vector>
#define MAX 987654321

//백준 2660 회장뽑기

using namespace std;
int arr[51][51];
int n;
int min(int a,int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}

void init(){
    cin >> n;
    
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i == j){
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = MAX;
            }
        }
    }
}

void input(){
    while(1){
        int first;
        int second;
        cin >> first >> second;
        if(first == -1 && second == -1){
            break;
        }
        arr[first][second] = 1;
        arr[second][first] = 1;
    }
}

void floyd(){
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){            
                    arr[i][j] = min(arr[i][j],arr[i][k] + arr[k][j]);
            }
        }
    }
}

int find_min(){ //최소 점수 구하는 함수
    int max_ = MAX;
    for(int i = 1;i<=n;i++){
        int sum = 0;
        for(int j = 1;j<=n;j++){
            sum += arr[i][j];
        }
        max_ = min(sum,max_);
    }
    return max_;
}

int main(void){
    init();
    input();
    floyd();
    int min_value = find_min();
   
    vector<int> v;
    int value = 0;
    
    for(int i = 1;i<=n;i++){
        int sum = 0;
        int temp = 0;
        
        for(int j = 1;j<=n;j++){
            sum += arr[i][j];
            if(arr[i][j] > temp){
                temp = arr[i][j];
            }
        }
        if(sum == min_value){
            v.push_back(i);
            value = temp;
        }
    }
    
    cout << value << ' ' << v.size() << '\n';
    for(int i = 0;i<v.size();i++){
        cout << v[i] << ' ';
    }
   
}