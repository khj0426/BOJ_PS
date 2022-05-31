#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
//1일떄 청팀,2일떄 백팀
 
struct student{
    int team;
    int number;
    string name;
};
 
typedef struct student d;
bool cmp(d a,d b){
 
    if(a.team != b.team){
        return a.team < b.team;
    }
 
    if(a.team == b.team){
        if(a.number != b.number){
            return a.number < b.number;
        }
 
    }
 
    if(a.number == b.number){
        if(a.name.size() != b.name.size()){
            return a.name.size() < b.name.size();
        }
        else if(a.name.size() == b.name.size()){
            return a.name < b.name;
        }
    }
 
}
int main(void){
    map<int,int> m;
    map<int,int>::iterator iter;
 
    d arr[1000];
 
    int n,count;
    cin >> n >> count;
    int index = 0;
 
    while(1){
        int room;
        string str;
        cin >> room;
        cin >> str;
        if(room == 0 && str == "0"){
            break;
        }
        iter = m.find(room);
        int value = iter->second;
        if(iter == m.end()){
            m[room]++;
            if(room%2 == 0){
            arr[index].team = 2;
            arr[index].number = room;
            arr[index].name = str;
        }
        else if(room%2 != 0){
            arr[index].team = 1;
            arr[index].number = room;
            arr[index].name = str;
        }
        }
 
        else if(value < count){
            m[room]++;
             if(room%2 == 0){
            arr[index].team = 2;
            arr[index].number = room;
            arr[index].name = str;
        }
        else if(room%2 != 0){
            arr[index].team = 1;
            arr[index].number = room;
            arr[index].name = str;
        }
        } 
        index++;
    }
 
    sort(arr,arr+index,cmp);
    for(int i = 0;i<index;i++){
        if(arr[i].number != 0){
            cout << arr[i].number << ' ' << arr[i].name << '\n';
        }
    }
}