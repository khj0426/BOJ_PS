#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//출연 순서 정하기
//순서들을 보고 출연 순서를 정해야 한다.

//143인 경우
 //1 -> 4 -> 3
 // 6 ->2 -> 5 -> 4
 //2 -> 3 순으로 간선 존재

//호출 완료 처리
bool finished[1001];

//방문 정점 처리
bool visited[1001];

//사이클이 발생했는지?

bool hasCycle = false;
int n,m;

//방문순서 기록
vector<int> ansOrder;
vector<int> graph[1001];

void Input(){
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int K;
        cin >> K;
        vector<int> order;
        
        for(int j = 0;j<K;j++){
            int Node;
            cin >> Node;
            order.push_back(Node);
        }

        for(int j = 0;j<K-1;j++){
            graph[order[j]].push_back(order[j+1]);
        }
    }
}

void Init(){
    for(int i = 1;i<=n;i++){
        finished[i] = false;
        visited[i] = false;
    }
}

void dfs(int node){
    visited[node] = true;
    for(int i = 0;i<graph[node].size();i++){
        int NextNode = graph[node][i];
        if(visited[NextNode] == false){
            dfs(NextNode);
        }
        //역간선 존재
        if(visited[NextNode] == true && finished[NextNode] == false){
            hasCycle = true;
            break;
        }
    }
    //호출 완료,순서 기록하게
    finished[node] = true;
   ansOrder.push_back(node);
}


int main(void){
    Input();
    Init();

    for(int i = 1;i<=n;i++){
        if(visited[i] == false){
            dfs(i);
        }    
    }
    //ansOrder의 뒤집은 결과가 위성정렬의 순서가 됨
    reverse(ansOrder.begin(),ansOrder.end());

    if(hasCycle == true){
        cout << '0';
        return 0;
    }
    else{
        for(int i = 0;i<ansOrder.size();i++){
            cout << ansOrder[i] << '\n';
        }
    }
}
