#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
 
using namespace std;
 
struct data{
    int D;
    int H;
    int num;
    int order;
};
 
struct compare{
    bool operator()(struct data a, struct data b){
        if(a.D != b.D){
            return a.D < b.D;
        }
        else if(a.D == b.D){
            if(a.H != b.H){
                return a.H < b.H;
            }
        }
 
            return a.num > b.num;
 
    }
};
 
int main(void){
    int N,M,K;
    cin >> N >> M >> K;
 
    bool endflag = false;
 
    int sumofOut = 0;
    int Deka = 0;
    //
	queue<struct data> q [M+1];
 
    for(int i = 0;i<N;i++){
        int d,h;
        cin >> d >> h;
        if(i == K){
            Deka = i;
        }
        q[i%M].push({d,h,i%M,i});
    }
 
    priority_queue<struct data,vector<struct data>,compare> answer;
     for(int i = 0;i<M;i++){
            if(q[i].size() == 0){
                continue;
            }
            answer.push(q[i].front());
            q[i].pop();
    }
 
 
    while(1){
 
        if(endflag){
            break;
        }
 
        if(answer.size() == 0){
            break;
        }
        else{
            int next = answer.top().order;
            int newqNum = answer.top().num;
  
            if(next == Deka){
                endflag = true;
                break;
            }
            answer.pop();
            if(q[newqNum].size() != 0){
                answer.push(q[newqNum].front());
                q[newqNum].pop();
            }
 
            sumofOut++;
        }
    }
 
    cout << sumofOut;
 
 
}