#include <iostream>
#include <map>
using namespace std;
int main(void){
    map<string,string> m;
    map<string,string>::iterator iter;
 
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        string str;
        cin >> str;
 
        if(str == "ENTER"){
            cnt = cnt + m.size();
            m.clear();
        }
        else{
            m.insert(pair<string,string>(str,str));
        }
 
    }
    cnt = cnt + m.size();
    cout << cnt;
}