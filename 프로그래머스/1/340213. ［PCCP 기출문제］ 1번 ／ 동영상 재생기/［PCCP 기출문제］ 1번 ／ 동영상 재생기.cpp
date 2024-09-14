#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//00:00 -> 숫자로
vector<int> parsetoNum(string str){
    vector<int> v;
    
    string time = "";
    string min = "";
    time += str[0];
    time += str[1];
    
    int T = stoi(time);
    
    min += str[3];
    min += str[4];
    
    int M = stoi(min);
    v.push_back((T*60) + M);
    v.push_back(T);
    v.push_back(M);
    return v;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    //오프닝위치에 있는지
    string str = "";
    str += pos[0];
    str += pos[1];
    int t = stoi(str);
    
    str = "";
    str += pos[3];
    str += pos[4];
    int m = stoi(str);
    
    for(int i = 0;i<commands.size();i++){
        string command = commands[i];
                //현재 재생 위치가 구간에 있다면
        vector<int> start_pos = parsetoNum(op_start);
        vector<int> end_pos = parsetoNum(op_end);
        
        int current_pos = t*60 + m;
        if(current_pos >= start_pos[0] && current_pos <= end_pos[0]){
            t = end_pos[1];
            m = end_pos[2];
 
        }
        
        if(command == "prev"){
            //10초 전으로 이동
            //만약 10초 미만일 경우
            if(t == 0 && m < 10){
                t = 0;
                m = 0;
            }
            else{
                //00일때 10초전으로 이동
                if(m >= 0 && m < 10){
                    //시간 하나 뺴고
                    t -= 1;
                    int temp = m;
                    
                    m = (50 + temp);
                }
                else{
                    m -= 10;
                }
            }
        }
        else if(command == "next"){
            //10초 미만일 경우
            //남은 기간이 10초 미만일 경우
            vector<int> v = parsetoNum(video_len);
            int lastT = v[0];
            int currentT = (t * 60) + m;
            
            if(lastT - currentT < 10){
                t = v[1];
                m = v[2];
                continue;
            }
            
            //50~59
            if(m >= 50 && m < 60){
                t += 1;
                m = m % 10;
            }
            else{
                m += 10;
            }
            
        }
        

      
    }
    
                //현재 재생 위치가 구간에 있다면
        vector<int> start_pos = parsetoNum(op_start);
        vector<int> end_pos = parsetoNum(op_end);
        
        int current_pos = t*60 + m;
        if(current_pos >= start_pos[0] && current_pos <= end_pos[0]){
            t = end_pos[1];
            m = end_pos[2];
        }
        
    
    string T = "";
    string M = "";
    if(t < 10){
        T += "0";
    }
        
    T += to_string(t);
    if(m < 10){
        M += "0";
    }
    M += to_string(m);
    string ans = "";
    ans += T;
    ans += ":";
    ans += M;
    return ans;
}