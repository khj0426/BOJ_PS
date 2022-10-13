#include <iostream>
#include <map>
#include <string>

//백준 생태학

using namespace std;
 
int main(void){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    map<string,int> m;
    map<string,int>::iterator iter;
    string arr;
    
    while(getline(cin,arr)){
        m[arr]++;
    }
 
    int sum = 0;
 
    for(iter = m.begin();iter != m.end();iter++){
        sum = sum + iter->second;    
    }
    
        cout << fixed;
        cout.precision(4);
 
    for(iter = m.begin();iter != m.end();iter++){
 
        double temp = (double)iter->second/(double)sum * 100;
       
        cout << iter->first << " ";
        cout << temp;
        cout << endl;
    }
}