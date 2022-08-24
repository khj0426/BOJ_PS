#include <iostream>
#include <string>
#include <map>
#include <sstream>
 
using namespace std;
int main(void)
{
    while(1){
        int t;
        cin >> t;
        if(t == 0){
            break;
        }
        
        int cnt = 0;
        string str;
        cin >> str;
        map<int,bool> m;
        map<int,bool>::iterator iter;
        
        char seperator = ',';
        string string_buf = "";
        istringstream iss(str);
        while(getline(iss,string_buf,seperator)){
            
            char second_seperator = '-';
            string temp_buf = "";
            istringstream ISS(string_buf);
            bool first = false;
            bool second = false;
            int first_value = 0;
            int second_value = 0;
            
            while(getline(ISS,temp_buf,second_seperator)){
                if(first == false){
                    first = true;
                    first_value = stoi(temp_buf);
                }
                else if(first == true && second == false){
                    second = true;
                    second_value = stoi(temp_buf);
                }
            }
            
            if(first == true && second == false){
                
                if(first_value <= t && first_value >= 1){
                    iter = m.find(first_value);
                    if(iter == m.end()){
                        m.insert({first_value,true});
                        cnt++;
                    }
                }
            }
            else if(first == true && second == true){
                if(first_value <= second_value){
                    for(int i = first_value;i<=second_value;i++){
                        if(i >= 1 && i <= t){
                            iter = m.find(i);
                            if(iter == m.end()){
                                m.insert({i,true});
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
        
    }
}