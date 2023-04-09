#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second != b.second){
        return a.second > b.second;
    }
    else{
        return a.first < b.first;
    }
}

int returnMineralValue(string str){
    if(str == "diamond"){
        return 25;
    }
    else if(str == "iron"){
        return 5;
    }
    return 1;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int valueArr[2001];
    //미네랄을 5개씩 끊어서 합 저장
    memset(valueArr,-1,sizeof(valueArr));
    int pickSize = picks[0] + picks[1] + picks[2];
    vector<pair<int,int>> ValueofMinerals;
    for(int i = 0;i<minerals.size();i+=5){
        int sumofMinerals = 0;
        if(pickSize == 0){
            break;
        }
        for(int j = i;j<i+5;j++){
            if(j >= minerals.size()){
                break;
            }
            sumofMinerals += returnMineralValue(minerals[j]);
        }
        ValueofMinerals.push_back({i,sumofMinerals});
        pickSize--;
    }
    
    vector<pair<int,int>> tempMinerals = ValueofMinerals;
    sort(ValueofMinerals.begin(),ValueofMinerals.end(),cmp);
    int ordering = 0;
    for(int i = 0;i<ValueofMinerals.size();i++){
        valueArr[ordering] = ValueofMinerals[i].first;
        ordering++;
    }
    
    int pickArr[2001];
    int orderPick = 0;
    memset(pickArr,-1,sizeof(pickArr));
    for(int i = 0;i<picks.size();i++){
        for(int j = 0;j<picks[i];j++){
            pickArr[orderPick] = i;
            orderPick++;
        }
    }
    
    for(int i = 0;i<ordering;i++){
        if(pickArr[i] == -1){
            break;
        }
        for(int j = valueArr[i];j<valueArr[i] + 5;j++){
            if(j >= minerals.size()){
                break;
            }
            if(minerals[j] == "diamond"){
                if(pickArr[i] == 0){
                    answer+=1;
                }
                else if(pickArr[i] == 1){
                    answer += 5;
                }
                else if(pickArr[i] == 2){
                    answer += 25;
                }
            }
            else if(minerals[j] == "iron"){
                 if(pickArr[i] == 0){
                    answer+=1;
                }
                else if(pickArr[i] == 1){
                    answer += 1;
                }
                else if(pickArr[i] == 2){
                    answer += 5;
                }
            }
            else if(minerals[j] == "stone"){
                 if(pickArr[i] == 0){
                    answer+=1;
                }
                else if(pickArr[i] == 1){
                    answer += 1;
                }
                else if(pickArr[i] == 2){
                    answer += 1;
                }
            }
        }
        
    }
    
    
    
    
    
    return answer;
}