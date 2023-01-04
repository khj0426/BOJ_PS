#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;
set<string> m;
set<string> s;
map<string,int> count;
vector<pair<int,int>> ans;


vector<int> solution(vector<string> gems) {
    vector<int> answer;

    for(int i = 0;i<gems.size();i++){
        s.insert(gems[i]);
    }

    int MAX_LENGTH = 987654321;
    int l = 0;
    int r = 0;
    int minL = 0;
    int minR = 0;

    m.insert(gems[l]);
    count[gems[l]] = 1;
    while(l<=r && r<gems.size()-1){
    
        if(m.size() >= s.size()){
            if(count[gems[l]] == 1){
                m.erase(gems[l]);
                count[gems[l]] = 0;
            }            
            else if(count[gems[l]] > 1){
                count[gems[l]]--;
            }
            if(r-l < MAX_LENGTH){
                minL = l + 1;
                minR = r + 1;
                MAX_LENGTH = r-l;
            }
            l++;
        }
        
        else if(m.size() < s.size()){
            r++;
            if(m.count(gems[r]) == 0){
                m.insert(gems[r]);
                count[gems[r]] = 1;
            }
            else{
                count[gems[r]]++;
            }
            
        }
         

    }

    for(int i = l;i<gems.size();i++){
        if(count[gems[i]] > 1){
            l++;
            count[gems[i]]--;
        }
        else{
            break;
        }
    }
   
    if(r-l < minR-minL && m.size() == s.size()){
        minL = l + 1;
        minR = r + 1;
    }


    answer.push_back(minL);
    answer.push_back(minR);
    if(minL == 0 && minR == 0){
        answer.clear();
        answer.push_back(l+1);
        answer.push_back(r+1);
    }

    return answer;
}