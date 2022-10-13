//k번 물탱크 방문시 청정수 > 고인물인 경우 청정수
 
/*
5 3 3
1 0 1 1 0
1 2
3 4
4 5
1
5
4
 
청정 고인 청정 청정 고인
1-2 1 0
3-4 2 0
4 5 1 0
 
3-4-5 3 0
 
 
 
*/
 
#include <iostream>
#include <algorithm>
using namespace std;
 
int parents[100001];
pair<int,int> sizes[100001];
 
int find(int x){
    if(parents[x] == x){
        return x;
    }
    else{
        parents[x] = find(parents[x]);
        return parents[x];
    }
}
 
void merge(int a,int b){
    int A = find(a);
    int B = find(b);
    if(A == B){
        return;
    }
    if(A < B){
        parents[B] = A;
        sizes[A].first += sizes[B].first;
        sizes[A].second += sizes[B].second;
 
    }
    else if(A > B){
        parents[A] = B;
        sizes[B].first += sizes[A].first;
        sizes[B].second += sizes[A].second;
    }
}
 
void set_parent(){
    for(int i = 1;i<=100000;i++){
        parents[i] = i;
        sizes[i].first = 0; //고인물 몇 명인지
        sizes[i].second = 0; //청정수 몇 명인지
    }
}
int n,m,q;
 
void init(){
    set_parent();
    cin >> n >> m >> q;
    for(int i = 1;i<=n;i++){
        int x;
        cin >> x;
        if(x == 0){ // 고인물
            sizes[i].first = 1;
        }
        else if(x == 1){ //청정수
            sizes[i].second = 1;
        }
 
    }
    for(int i = 0;i<m;i++){
        int first,second;
        cin >> first >> second;
        merge(first,second);
    }
 
}
 
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    for(int i = 0;i<q;i++){
        int node;
        cin >> node;
        int first_size = sizes[find(node)].first; //고인
        int second_size = sizes[find(node)].second; //청정
        if(first_size < second_size){
            cout << 1 << '\n';
        }
        else{
            cout << 0 << '\n';
        }
    }
}
 
 