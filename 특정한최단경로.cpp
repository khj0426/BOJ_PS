//1번 정점에서 N번 정점으로 이동
//두 정점은 반드시 통과

//정점 A ,B
//A부터 돌리고
//B부터 돌림

//1-A-B-N
//1-B-A-N

#define MAXVAL 987654321

#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int Dt[801][801];
int visited[801];
vector<pair<int,int>> graph[801];
//비용과 간선

void Solve(int start){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    visited[start] = 0;

    q.push({visited[start],start});

    while(!q.empty()){
        int CurWeight = q.top().first;
        int CurNode = q.top().second;

        q.pop();
        for(int i = 0;i<graph[CurNode].size();i++){
            int NextWeight = graph[CurNode][i].first;
            int NextNode = graph[CurNode][i].second;

            if(visited[NextNode] > NextWeight + CurWeight){
                visited[NextNode] = NextWeight + CurWeight;
                q.push({visited[NextNode],NextNode});
            }
        }
    }
}

int main(void){
    int N,E;
    int MinA = MAXVAL;
    int MinB = MAXVAL;
    int A,B;
    cin >> N >> E;
    for(int i = 1;i<=N;i++){
        visited[i] = MAXVAL;
    }


    for(int i = 0;i<E;i++){
        int From,To,Weight;
        cin >> From >> To >> Weight;

        //그래프 생성
        graph[From].push_back({Weight,To});
        graph[To].push_back({Weight,From});

    }

    //1ABN
    //1BAN

    cin >> A >> B;

    Solve(1);
    Dt[1][A] = visited[A];
    Dt[1][B] = visited[B];

    for(int i = 1;i<=N;i++){
        visited[i] = MAXVAL;
    }

    Solve(B);
    //BA
    //BN
    Dt[B][A] = visited[A];
    Dt[B][N] = visited[N];

    for(int i = 1;i<=N;i++){
        visited[i] = MAXVAL;
    }

    Solve(A);
    Dt[A][B] = visited[B];
    Dt[A][N] = visited[N];


    //1ABN
    //1BAN

    int FirstPath = MAXVAL;
    if(Dt[1][A] != MAXVAL && Dt[A][B] != MAXVAL && Dt[B][N] != MAXVAL){
        FirstPath = Dt[1][A] + Dt[A][B] + Dt[B][N];
    }  

    int SecondPath = MAXVAL;
    if(Dt[1][B] != MAXVAL && Dt[B][A] != MAXVAL && Dt[A][N] != MAXVAL){
        SecondPath = Dt[1][B] + Dt[B][A] + Dt[A][N];
    }

    if(FirstPath == MAXVAL && SecondPath == MAXVAL){
        cout << -1;
    }
    else{
        cout << min(FirstPath,SecondPath);
    }

    
}