#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;

//이전에 손님들이 주문할 때 가장 많이 함계 주문한 제품

//최소 2가지 이상

//최소 2명 이상으로부터 주문된 메뉴 조합

//2부터 N까지
//손님이 해당 번호를 주문했는지


//정렬 조건
bool cmp(pair<int,string> a,pair<int,string> b){
    if(a.first != b.first){
        return a.first > b.first;
    }
    else if(a.first == b.first){
        return a.second.size() < b.second.size();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<char> Charater;
    vector<pair<int,string>> sameOrder[11];
    vector<int>::iterator iter;
    
    //알파벳 방문처리
    bool visited[27];
    
    //알페벳 방문배열 초기화
    for(int i = 0;i<=27;i++){
        visited[i] = false;
    }
    
    //가능한 모든 알파벳
    for(int i = 0;i<orders.size();i++){
        for(int j = 0;j<orders[i].size();j++){
            char c = orders[i][j];
            if(visited[c-'A'] == false){
                Charater.push_back(c);
                visited[c-'A'] = true;
            }
        }
    }
    
    for(iter = course.begin();iter != course.end();iter++){
        //메뉴 2개부터 최대 많을 때까지
        int i = *iter;
        
        //1개의 메뉴는 제외대상임
        if(i == 1){
            continue;
        }
        
        vector<int> Combinate;
        for(int j = 0;j<i;j++){
            Combinate.push_back(1);
        }
        
        for(int j = 0;j<Charater.size() - i;j++){
            Combinate.push_back(0);
        }
        
        sort(Combinate.begin(),Combinate.end());
        
        do{
            vector<char> popCharater;
            string str = "";
            for(int j = 0;j<Charater.size();j++){
                if(Combinate[j] == 1){
                    popCharater.push_back(Charater[j]);
                    str += Charater[j];
                }
            }
            
            
            int cntChar = 0;
            //최소 2명 이상이 주문해야 하는 메뉴만 선별
            for(int q = 0;q<orders.size();q++){
                bool valid = false;
                int cnt = 0;
                for(int p = 0;p<orders[q].size();p++){
                    for(int k = 0;k<popCharater.size();k++){
                        if(orders[q][p] == popCharater[k]){
                            cnt++;
                        }
                    }
                }
                
                if(cnt == popCharater.size()){
                    cntChar++;
                }
                
            }
            
            if(cntChar >= 2){
                sameOrder[popCharater.size()].push_back({cntChar,str});
            }
            
            
        }while(next_permutation(Combinate.begin(),Combinate.end()));
    }
    

    //많은 사람이 주문한 순으로, 이어서 알파벳 순으로 오름차순 정렬
    for(iter = course.begin();iter != course.end();iter++){
        int i = *iter;
        if(i == 1){
            continue;
        }
        if(sameOrder[i].size() == 0){
            continue;
        }
        sort(sameOrder[i].begin(),sameOrder[i].end(),cmp);
        int maxCourse = sameOrder[i][0].first;


        //가장 많이 주문한 것이 여러 개일 경우
        
        answer.push_back(sameOrder[i][0].second);
        for(int j = 1;j<sameOrder[i].size();j++){
            if(maxCourse == sameOrder[i][j].first){
                answer.push_back(sameOrder[i][j].second);
            }
        }
        
    }
    
    sort(answer.begin(),answer.end());
    
    //같은 알파벳 문자열은 한번만 나오도록 
    set<string> filter;
    for(int i = 0;i<answer.size();i++){
        sort(answer[i].begin(),answer[i].end());
        filter.insert(answer[i]);
    }
    
    set<string>::iterator filterIter;
    answer.clear();
    
    for(filterIter = filter.begin();filterIter != filter.end();filterIter++){
        answer.push_back(*filterIter);
    }
    

    return answer;
}