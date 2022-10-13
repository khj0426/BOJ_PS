#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(void){
    
    int t;
    cin >> t;
   
    while(t--){
        int n,m;
        cin >> n >> m;
        deque<pair<int,int>> v;
        deque<pair<int,int>>::iterator iter;
        vector<pair<int,int>> my_v;
        
        for(int i = 0;i<n;i++){
            int x;
            cin >> x;
            v.push_back({i,x});
        }
        
  
        while(!v.empty()){
            
            bool valid = false;
            
            int first_index = v.front().first;
            int first_value = v.front().second;
            for(iter = v.begin();iter != v.end();iter++){
                
                int v_second_value = iter->second;
                if(v_second_value > first_value){
                    v.push_back({first_index,first_value});
                    v.pop_front();
                    valid = true;
                    break;
                }
            }
            if(valid == false){
                my_v.push_back({v.front().first,v.front().second});
                v.pop_front();
            }
        }
        
        for(int i = 0;i<my_v.size();i++){
            if(my_v[i].first == m){
                cout << i + 1;
                break;
            }
        }
        
        cout << '\n';
      

    }
       
    
}