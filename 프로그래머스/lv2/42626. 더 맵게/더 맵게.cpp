#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 0;i<scoville.size();i++){
        q.push(scoville[i]);
    }
    
    
    while(q.size() > 1){
        int firstScovile = q.top();
        q.pop();
        int secondScovile = q.top();
        q.pop();
        if(firstScovile < K){
            int newScovile = firstScovile + (secondScovile * 2);
            q.push(newScovile);
            answer++;
        }
    }
    
    if(q.top() < K){
        return -1;
    }
    return answer;
}