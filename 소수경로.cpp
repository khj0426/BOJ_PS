#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int dt[10000];
string a,b;
int ans = 987654321;

bool isPrime(int n){
    for(int i = 2;i*i<=n;i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void init(){
    for(int i = 1;i<=10000;i++){
        dt[i] = 987654321;
    }
}


int main(void){

    int n;
    cin >> n;
    while(n--){
        init();
        cin >> a >> b;
        queue<string> q;
        q.push(a);
        dt[stoi(a)] = 0;
        while(!q.empty()){
            string num = q.front();
            q.pop();

            for(int i = 0;i<4;i++){
                string Num = num;
                if(i != 0){
                    for(int j = 0;j<=9;j++){
                        Num[i] = j + 48;
                        if(isPrime(stoi(Num)) && dt[stoi(Num)] > dt[stoi(num)] + 1){
                            q.push(Num);
                            dt[stoi(Num)] = dt[stoi(num)] + 1;
                        }
                    }
                }
                else if(i == 0){
                    for(int j = 1;j<=9;j++){
                        Num[i] = j + 48;
                         if(isPrime(stoi(Num)) && dt[stoi(Num)] > dt[stoi(num)] + 1){
                            q.push(Num);
                            dt[stoi(Num)] = dt[stoi(num)] + 1;
                        }
                    }
                }
            }
        }
        if(dt[stoi(b)] == 987654321){
            cout <<  "Impossible" << '\n';
        }
        else{
            
             cout << dt[stoi(b)] << '\n';
        }


    }
    
}