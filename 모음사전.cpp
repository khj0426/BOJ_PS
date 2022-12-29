#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool visited[6];
vector<string> ans;
int ansCount = 0;
void dfs(int depth,string word,vector<char> alphas,string currentStr){
    if(currentStr.size() > alphas.size()){
        return;
    }
    ans.push_back(currentStr);
    if(currentStr == word){
        ansCount = ans.size() - 1;
        return;
    }
    for(int i = 0;i<alphas.size();i++){
            visited[i] = true;
            dfs(depth+1,word,alphas,currentStr + alphas[i]);
            visited[i] = false;
    }
}

int solution(string word) {
    int answer = 0;
    vector<char> allAlpha;
    
    string allAlphaStr = "AEIOU";
    for(int i = 0;i<allAlphaStr.size();i++){
        allAlpha.push_back(allAlphaStr[i]);
    }
    
   dfs(0,word,allAlpha,"");
   answer = ansCount;
    
    return answer;
}