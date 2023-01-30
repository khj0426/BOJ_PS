#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(void){
    vector<char> v;

    string str;
    cin >> str;

    string burst;
    cin >> burst;


    for(int i = 0;i<str.size();i++){
        v.push_back(str[i]);
        if(v.size() >= burst.size() && v[v.size()-1] == burst[burst.size()-1]){
            bool flag = false;
            //8size
            //vsize-burstsize
            //6
            for(int j = 0;j<burst.size();j++){
                
                if(burst[j] != v[v.size()-burst.size()+j]){
                    flag = true;
                }
                if(flag == true){
                    break;
                }
            }

            if(flag == false){
                for(int j = 0;j<burst.size();j++){
                    v.pop_back();
                }
            }
        }
       
    }

    if(v.size() == 0){
        cout << "FRULA";
    }
    else{
        for(int i = 0;i<v.size();i++){
            cout << v[i];
        }
    }

}