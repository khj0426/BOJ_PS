#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(void){
    int n;
    cin >> n;
    map<string,int> m;
    map<string,int>::iterator iter;

    int ans = 0;
    for(int i = 0;i<n;i++){
        string str;
        cin >> str;
        iter = m.find(str);
        
        if(iter == m.end()){
            ans++;
            for(int j = 0;j<str.size();j++){
            string temp = "";
            for(int k = j;k<str.size();k++){
                temp = temp + str[k];
            }
                
            for(int q = 0;q<j;q++){
                temp = temp + str[q];
            }

                m.insert({temp,i});
                
        }
        
        }
        else{
            continue;
        }
      
        
        
    }
    cout << ans;
}