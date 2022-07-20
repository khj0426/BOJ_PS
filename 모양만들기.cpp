#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
 
int group[1001][1001]; //같은 그룹 끼리 그룹화시켜줌
int n,m;
bool visited[1001][1001]; //방문처리용 배열
int arr[1001][1001]; //원래의 배열
int ans = 0; //모양의 최대 개수
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int depth = 1;
vector<pair<int,int>> v; 
int first = 1; //첫번째 그룹->두번째,,...
int max_value = 0; //최대의 높이 값
 
void init(){ //방문배열 초기화
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            visited[i][j] = false;
        }
    }
}
 
void dfs(int x,int y){ //DFS함수 같은 그룹이면 같은 높이를 갖도록
    if(visited[x][y]){
        return;
    }
    visited[x][y] = true;
    for(int i = 0 ;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m){
            continue;
        }
        if(visited[nx][ny] == false && arr[nx][ny] == 1){
            v.push_back({nx,ny});
            group[nx][ny] = first;
            dfs(nx,ny);
            depth++;
        }
    }
}

void grouping_array(){ //배열이 1이고 방문을 안했다면, 벡터에 넣고 DFS진행
    //DFS진행 뒤 -> 같은 그룹은 같은 높이(상,하,좌,우로 인접한 1의 개수)를 지니게 됨
    
     for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i][j] == 1 && visited[i][j] == false){
                v.push_back({i,j});
                group[i][j] = first;
                dfs(i,j);
                for(int i = 0;i<v.size();i++){
                    int F = v[i].first;
                    int S = v[i].second;
                    if(arr[F][S] < depth){
                        arr[F][S] = depth;
                    }
                }
                v.clear();
                depth = 1;
                first++;
            }
 
        }
    }
}

void find_max_height(){
    //배열의 값이 0일떄만 작동
    /*0의 인접한 (상,하,좌,우)가 방문되었다면(원소의 값이 1이라면)
      + 같은 그룹이 아니라면 0 -> 1로 바꾼 높이 값 저장
      최대의 높이 값 갱신 */
    
     for(int i = 0;i<n;i++){
       for(int j = 0;j<m;j++){
           if(arr[i][j] == 0){
               int temp = 0;
               map<int,int> M;
               map<int,int>::iterator iter;
               for(int k = 0;k<4;k++){
                   int nx = i + dx[k];
                   int ny = j + dy[k];
                   if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                       continue;
                   }
                   if(visited[nx][ny] == true){
 
                       iter = M.find(group[nx][ny]);
                       if(iter == M.end()){
                           temp = temp + arr[nx][ny];
                           M.insert({group[nx][ny],group[nx][ny]});
                       }
 
                   }
               }           
               temp++;
               if(temp > max_value){
                   max_value = temp;
               }
 
           }
       }
   }
}
int main(void){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> arr[i][j];
        }
    }
 
    
    
    grouping_array();
    find_max_height();
    cout << max_value;
 
}