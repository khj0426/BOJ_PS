#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool visited[4];
vector<int> percents;
string percent = "";

map<string,string> m;
map<string,string>::iterator iter;

void dfs_combinate(int index,int cnt,int emoSize){
    if(cnt == emoSize){
        iter = m.find(percent);
        if(iter == m.end()){
            m[percent] = percent;
        }
        return;
    }
    for(int i = index;i<emoSize;i++){
        for(int j = 0;j<4;j++){
                visited[j] = true;
                percent.append(to_string(j));
                dfs_combinate(i,cnt+1,emoSize);
                percent.pop_back();
                visited[j] = false;
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    int maxUser = -1;
    int maxSendPrice = -1;
    
    map<char,float> convertPercent;
    convertPercent['0'] = 0.1;
    convertPercent['1'] = 0.2;
    convertPercent['2'] = 0.3;
    convertPercent['3'] = 0.4;
    
    //3개의 이모티콘이 있다면
    
    //{10,20,30,40}
    
    //3 3 3 3
    
    //12 개 중에서 4개 뽑는 거니깐
    
    //7개의 이모티콘이 있다면
    
    //{10 20 30 40}이 7개 있는 거니깐
    
    //28 개중에서 7개를 뽑아야 함
    dfs_combinate(0,0,emoticons.size());
    
    
    for(iter = m.begin();iter != m.end();iter++){
        int sumofUsersEmoticon = 0;
        int sumofUsersEmoticonPlus = 0;
        
        string percents = iter->second;
        
        for(int i = 0;i<users.size();i++){
            
            int sumofEmoticon = 0;
            int sumofEmoticonPlus = 0;
            vector<int> userDetail = users[i];
            
            for(int j = 0;j<percents.size();j++){
                if(convertPercent[percents[j]]*100 >= userDetail[0]){
                    sumofEmoticon++;
                    
                    //할인된 가격으로 삼
                    
                    //10000의 10프로
                    //10000 - (10000 * 0.1)
                    sumofEmoticonPlus += (emoticons[j] - int(emoticons[j] * convertPercent[percents[j]]));
                    
                }
            }
            if(sumofEmoticonPlus >= userDetail[1]){
                sumofUsersEmoticonPlus++;
                sumofEmoticonPlus = 0;
            }
            sumofUsersEmoticon += sumofEmoticonPlus;
        }
        
        if(maxUser < sumofUsersEmoticonPlus){
            maxUser = sumofUsersEmoticonPlus;
            maxSendPrice = sumofUsersEmoticon;
        }
        else if(maxUser == sumofUsersEmoticonPlus){
            maxSendPrice = max(maxSendPrice,sumofUsersEmoticon);
        }
    }
    
    answer.push_back(maxUser);
    answer.push_back(maxSendPrice);
    
    
    
    return answer;
}