/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int dist[501][501];

void init(){
   cin >> n >> m;
   for(int i = 0;i<m;i++){
       int first,second;
       cin >> first >> second;
       
       dist[first][second] = 1;

       
   }
}

void floyd(){
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(dist[i][k] == 1  && dist[k][j] == 1){
                    dist[i][j] = 1;
                }
                
            }
        }
    }
}


int main(void){
    init();
    floyd();
    
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(dist[j][i] == 1){
                dist[i][j] = 1;
            }
           
        }
        
    }
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        bool valid = false;
        for(int j = 1;j<=n;j++){
            if(i!=j){
                if(dist[i][j] == 0){
                    valid = true;
                    break;
                }
            }
        }
        if(valid == false){
            cnt+=1;
        }
    }
    cout << cnt;
}