#include <iostream>
#include <map>
 
 //백준 숫자카드2

using namespace std;
 
int main(void){
    ios::sync_with_stdio(false); /*cin,cout최적화 코드*/
    cin.tie(NULL);
    cout.tie(NULL);
    
    map<int,int> m;
    map<int,int>::iterator iter;
 
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int card;
        cin >> card;
        m[card]++;
    }
    int M;
    cin >> M;
    for(int i = 0;i<M;i++){
        int find_card;
        cin >> find_card;
        iter = m.find(find_card);
        if(iter != m.end()){
            cout << iter->second;
        }
        else{
            cout << '0';
        }
        cout << ' ';
    }
}