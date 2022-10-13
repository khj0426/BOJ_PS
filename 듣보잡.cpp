#include <iostream>
#include <map>
#include <string>
#include <algorithm>
 
using namespace std;

//백준 듣보잡

int main(void){
    map<string,string> m;
    int n;
    cin >> n;
    int M;
    cin >> M;
    for(int i = 0;i<n;i++){
        string temp;
        cin >> temp;
        m.insert(pair<string,string>(temp,temp)); //듣도 못한 사람을 map에 저장 (key값인 동시에 value값)
    }
 
    int count = 0;
    map<string,string>::iterator iter; 
 
    string arr[500010]; //듣도 보도 못한 사람을 담을 배열
    int idx = 0;
 
    for(int i = 0;i<M;i++){
        string temp;
        cin >> temp; //보도 못한 사람의 이름을 입력받고
        iter = m.find(temp); //map에서 보도 못한 사람의 이름을 찾는다.

        if(iter != m.end()){ //map에 보도못한 사람의 이름이 있으면 해당 사람은 듣도 보도 못한 사람이 된다.
            count++; //count증가
            arr[idx] = arr[idx] + temp; //듣도 보도 못한 사람의 이름을 담아준다
            idx++;
        }
    }
    
    sort(arr,arr+idx); //배열 사전순 정렬
    
    cout << count;
    cout << '\n';
    for(int i = 0;i<idx;i++){
        cout << arr[i] << '\n';
    }
}