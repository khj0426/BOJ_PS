#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
 
map<string,int> m;
map<string,int>::iterator iter;
vector<pair<string,string>> myv;
 
bool compare(pair<string,string> A,pair<string,string> B){
    return A.second < B.second;
}
 
void init(){
    bool is_first_n = false;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string str = "abkdeghilmnngoprstuwy";
    for(int i =0;i<str.size();i++){
        if(str[i] != 'n'){
            string temp = "";
            temp = temp + str[i];
            m.insert(pair<string,int>(temp,i));
        }
        else if(str[i] == 'n'){
            if(is_first_n == false){
                is_first_n = true;
                string temp = "";
                temp = temp + str[i];
                m.insert(pair<string,int>(temp,i));
            }
            else if(is_first_n == true){
                string temp = "";
                for(int j = i;j<=i+1;j++){
                    temp = temp + str[j];
                    m.insert(pair<string,int>(temp,i));
                }
                i = i + 1;
            }
        }
    }
    
    int N = 0;
    for(iter = m.begin();iter != m.end();iter++){
        N = iter->second;
    }
    N++;
    cout << N << '\n';
    
    for(int i = 0;i<alpha.size();i++){
        string temp = "";
        temp = temp + alpha[i];
        iter = m.find(temp);
        if(iter == m.end()){
            m.insert(pair<string,int>(temp,N));
            N++;
        }
    }
 
}
int main(void){
    int t;
    cin >> t;
    init();
 
    for(int i = 0;i<t;i++){
        string str;
        cin >> str;       
        string order = "";
 
        for(int i = 0;i<str.size();i++){
            if(str[i] != 'n'){
                string temp = "";
                temp = temp + str[i];
                iter = m.find(temp);
                int find_str = iter->second;
                order = order.append(to_string(find_str));
            }
            else if(str[i] == 'n'){
                if(str[i+1] == 'g'){
                    string temp = "";
                    temp = temp + str[i];
                    temp = temp + str[i+1];
                    iter = m.find(temp);
                    int find_str = iter->second;
                    order = order.append(to_string(find_str));
                    i++;
                }
                else if(str[i+1] != 'g'){
                    string temp = "";
                    temp = temp + str[i];
                    iter = m.find(temp);
                    int find_str = iter->second;
                    order = order.append(to_string(find_str));
                }
            }
        }
        myv.push_back({str,order});
 
    }

    sort(myv.begin(),myv.end(),compare);
    for(int i = 0;i<myv.size();i++){
        cout << myv[i].first << ' ' << myv[i].second << '\n';
    }
 
 
}
