#include <iostream>
#include <algorithm>

//백준 8979 올림픽
using namespace std;
struct cty{
    int gold;
    int silver;
    int bronze;
    int cty_num;
    int final_num;
};
typedef struct cty ct;
bool cmp(ct a,ct b){
    if(a.gold != b.gold){
        return a.gold>b.gold;
    }
    else if(a.gold == b.gold && a.silver != b.silver){
        return a.silver > b.silver;
    }
    else if(a.silver == b.silver && a.bronze != b.bronze){
        return a.bronze > b.bronze;
    }
}
int main(void){
    ct arr[1000];
    int n,m;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        int x,y,z,q;
        cin >> x >> y >> z >> q;
        arr[i].cty_num = x;
        arr[i].gold = y;
        arr[i].silver = z;
        arr[i].bronze = q;
    }
    sort(arr,arr+n,cmp);
    int first = 1;
    
    for(int i = 0;i<n;i++){
       arr[i].final_num = first;
       first++;
    }
    
    for(int i = 0;i<n;i++){
        if(arr[i].gold == arr[i-1].gold && arr[i].silver == arr[i-1].silver && arr[i].bronze == arr[i-1].bronze){
            arr[i].final_num = arr[i-1].final_num;
        }
    }
    for(int i = 0;i<n;i++){
        if(arr[i].cty_num == m){
            cout << arr[i].final_num;
            break;
        }
    }
    
}