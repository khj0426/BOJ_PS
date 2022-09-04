#include <iostream>
using namespace std;
 
int parent[1000001];
int n,m;
 
int Find(int x){
    if(parent[x] == x){
        return x;
    }
    else{
        parent[x] = Find(parent[x]);
        return parent[x];
    }
}
 
void Union(int a,int b){
    int parent_a = Find(a);
    int parent_b = Find(b);
    if(parent_a != parent_b){
        if(parent_a < parent_b){
            parent[parent_b] = parent_a;
        }
        else{
            parent[parent_a] = parent_b;
        }
    }
}
 
void init(){
    for(int i = 1;i<=n;i++){
        parent[i] = i;
    }
}
 
int main(void){
    scanf("%d %d",&n,&m);
    init();
    for(int i = 0;i<m;i++){
        int type;
        scanf("%d",&type);
        if(type == 0){
            int first,second;
            scanf("%d %d",&first,&second);
            Union(first,second);
        }
        else if(type == 1){
            int first,second;
            scanf("%d %d",&first,&second);
            int FIRST = Find(first);
            int SECOND = Find(second);
            if(FIRST == SECOND){
                printf("YES \n");
            }
            else{
                printf("NO \n");
            }
        }
    }
}