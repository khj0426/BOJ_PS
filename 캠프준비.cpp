#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 16
using namespace std;
struct problem{ //문제 인덱스와 문제 난이도 구조체 설정
    int index;
    int hard;
};
 
typedef struct problem pb;
 
int n,l,r,x;
vector<int> process; //process는 문제 난이도 넣어주는 벡터
vector<int> answer; //start == n 시 갱신 될 벡터
 
pb arr[MAX];
int cnt = 0;
 
void dfs(int start,int sum){ 
    if(start == n){
        if(process.size() >= 2){ //2이상일떄 answer 초기화 후
            answer.clear();
            for(int i = 0;i<process.size();i++){ //answer에 process 값 넣어주고
                answer.push_back(process[i]);
            }
            sort(answer.begin(),answer.end()); 
            /*answer 오름차순 정렬 -> 마지막에 가장 큰 값,앞에 가장 작은 값 */
            
            if(answer[answer.size()-1] - answer[0] >= x && sum >= l && sum <= r){
                cnt++;
            }
 
        }
        return;
    }
    dfs(start+1,sum); //건너뛰는 경우
    process.push_back(arr[start].hard);
 
    dfs(start+1,sum+arr[start].hard); //문제 가져가는 경우
    process.pop_back();
}
int main(void){
    cin >> n >> l >> r >> x;
    for(int i = 0;i<n;i++){
        arr[i].index = i+1;
        cin >> arr[i].hard;
    }
    dfs(0,0);
    cout << cnt;
}