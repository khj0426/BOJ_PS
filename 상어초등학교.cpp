#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
 
bool isPath[1001][1001];
int n;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int map[1001][1001];
vector<int> order;
 
struct data{
    int x;
    int y;
    int cnt;
};
 
//정렬 조건 설정
bool cmp(struct data a,struct data b){
    if(a.cnt != b.cnt){
        return a.cnt > b.cnt;
    }
    else if(a.cnt == b.cnt){
        if(a.x != b.x){
            return a.x < b.x;
        }
    }
       return a.y < b.y;
 
}
 
 
 
int main(void){
    int n;
    cin >> n;
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            map[i][j] = 0;
            isPath[i][j] = false;
        }
    }
 
 
    for(int i = 0;i<n*n;i++){
        int num;
        cin >> num;
        order.push_back(num);
 
        for(int j = 0;j<4;j++){
            int x;
            cin >> x;
            isPath[num][x] = true;
        }
    }
 
    for(int i = 0;i<order.size();i++){
        //비어있는 칸 중 좋아하는 학생이 인접한 칸에 많은 칸으로
 
        vector<struct data> counts;
        for(int q = 0;q<n;q++){
            for(int p = 0;p<n;p++){
                if(map[q][p] == 0){
                    int cnt = 0;
                    for(int k = 0;k<4;k++){
                        int nx = q + dx[k];
                        int ny = p + dy[k];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n){
                            continue;
                        }
                        if(isPath[order[i]][map[nx][ny]] == true && map[nx][ny] != 0){
                            cnt++;
                        }
                    }
 
                    counts.push_back({q,p,cnt});
                }
 
 
 
                }
            }
 
            sort(counts.begin(),counts.end(),cmp);
            int maxVal = counts[0].cnt;
            vector<struct data> newCounts;
            for(int k = 1;k<counts.size();k++){
                if(counts[k].cnt == maxVal){
                    newCounts.push_back({counts[k].x,counts[k].y,counts[k].cnt});
                }
            }
 
            if(newCounts.size() == 0){
                map[counts[0].x][counts[0].y] = order[i];
            }
 
            else{
 
                vector<struct data> emptySpaces;
                int Empty = 0;
                for(int K = 0;K<4;K++){
                    int nx = counts[0].x + dx[K];
                    int ny = counts[0].y + dy[K];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n){
                        continue;
                    }
                    if(map[nx][ny] == 0){
                        Empty++;
                    }
                }
 
                emptySpaces.push_back({counts[0].x,counts[0].y,Empty});
 
                for(int k = 0;k<newCounts.size();k++){
                    //인접한 칸 중 비어있는 칸 개수 구하기
                    int empty = 0;
                    int X = newCounts[k].x;
                    int Y = newCounts[k].y;
                    for(int K = 0;K<4;K++){
                        int NX = X + dx[K];
                        int NY = Y + dy[K];
                        if(NX < 0 || NY < 0 || NX >= n || NY >= n){
                            continue;
                        }  
                        if(map[NX][NY] == 0){
                            empty++;
                        }
                    }
 
                    emptySpaces.push_back({X,Y,empty});
                }
 
                sort(emptySpaces.begin(),emptySpaces.end(),cmp);
 
                for(int K = 0;K<emptySpaces.size();K++){
                    if(map[emptySpaces[K].x][emptySpaces[K].y] == 0){
 
                        map[emptySpaces[K].x][emptySpaces[K].y] = order[i];
                        break;
                    }
                }
 
            }
        }
 
 
    int sum = 0;
    //만족도 구하기
 
    for(int i = 0;i<n;i++){
 
        for(int j = 0;j<n;j++){
            int cnt = 0;
            for(int k = 0;k<4;k++){
 
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n){
                    continue;
                }
                if(isPath[map[i][j]][map[nx][ny]] == true){
                    cnt++;
                }
            }
            if(cnt == 1){
                sum += 1;
            }
            else if(cnt == 2){
                sum += 10;
            }
            else if(cnt == 3){
                sum += 100;
            }
            else if(cnt == 4){
                sum += 1000;
            }
        }
    }
 
    cout << sum;
 
 
}