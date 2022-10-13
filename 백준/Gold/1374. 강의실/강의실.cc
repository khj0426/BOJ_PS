#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct room{
    int start;
    int end;
};

typedef struct room rm;
bool cmp(rm a,rm b){
    if(a.start != b.start){
        return a.start < b.start;
    }
    else{
        return a.end < b.end;
    }
}
priority_queue<int,vector<int>,greater<int>> pq;
rm arr[100001];

int main(void){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        arr[a-1].start = b;
        arr[a-1].end = c;
    }
    sort(arr,arr+n,cmp);
    
    for(int i = 0;i<n;i++){
        if(i == 0){
            pq.push(arr[i].end);
            ans++;
        }
        else{
            if(pq.top() > arr[i].start){
                pq.push(arr[i].end);
                ans++;
            }
            else{
                pq.pop();
                pq.push(arr[i].end);
            }
        }
    }
    
    cout << ans;
    
}


