#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int table_to[51][51];
bool visited[51][51];
int table_from[51][51];
int gift_count[51];
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    map<string,int> num;
    
    for(int i = 0;i<friends.size();i++){
        num[friends[i]] = i;
    }
    
    //A가 B에게 선물을 줌
    for(int i = 0;i<gifts.size();i++){
        //A->B
        string name = "";
        string from = "";
        string to = "";
        for(int j = 0;j<gifts[i].size();j++){
            if(gifts[i][j] == ' '){
                to = name;
                name = "";
            }
            else{
                name += gifts[i][j];
            }
        }
        from = name;
        table_to[num[to]][num[from]]++;
        table_from[num[from]][num[to]]++;
    }
    
    //선물지수 계산
    map<string,int> gift_weight;
    
    
    //준선물과 받은선물
    
    for(int i = 0;i<friends.size();i++){
        for(int j = 0;j<friends.size();j++){
            cout << table_to[i][j] << ' ';
        }
        cout << '\n';
    }
    
    for(int i = 0;i<friends.size();i++){
        //i가 준선물-받은선물
        //준선물계산
        int toCount = 0;
        for(int j = 0;j<friends.size();j++){
            if(i != j){
                toCount += table_to[i][j];
            }
        }
        
        //받은선물계산
        int fromCount = 0;
        for(int j = 0;j<friends.size();j++){
            if(i != j){
                fromCount += table_from[i][j];
            }
        }
        
        gift_weight[friends[i]] = toCount - fromCount;
    
    }
    
    //다음달 선물 계싼
    for(int i = 0;i<friends.size();i++){
        for(int j = 0;j<friends.size();j++){
            if(i == j){
                continue;
            }
            if(visited[i][j] || visited[j][i]){
                continue;
            }
            //i가 j에게 선물을 준 
            int to_ = table_to[i][j];
            //i가 j에게 선물을 받은
            int from_ = table_from[i][j];
            if(to_ != 0 || from_ != 0){
                //더 많이 선물을 준 사람이 다음달 선물을 받는다
                int max_ = max(to_,from_);
                if(to_ > from_){
                    gift_count[i]++;
                }
                else if(to_ < from_){
                    gift_count[j]++;
                }
                visited[i][j] = true;
                visited[j][i] = true;
            }
            
            if(to_ == from_ || to_ == 0  && from_ == 0){
                //선물지수 확인하기
                int toWeight = gift_weight[friends[i]];
                int fromWeight = gift_weight[friends[j]];
                cout << toWeight << ' ' << fromWeight << '\n';
                //선물지수가 큰 사람
                if(toWeight != fromWeight){
                    if(toWeight > fromWeight){
                        gift_count[i]++;
                    }
                    else{
                        gift_count[j]++;
                    }
                }
               
                
            }
            visited[i][j] = true;
            visited[j][i] = true;
       
        }   
    }
    
    int maxC = -987654321;
    for(int i = 0;i<friends.size();i++){
        maxC = max(maxC,gift_count[i]);
        cout << gift_count[i] << '\n';
    }
    return maxC;
}