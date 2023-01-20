#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

//return id and nickname
vector<string> parseUserID(string str,string status){
    vector<string> idandNick;
    if(status == "Enter"){
        bool isend = false;
        string newStr = "";
        for(int i = 6;i<str.size();i++){
            if(str[i] == ' '){
                idandNick.push_back(newStr);
                isend = true;
                newStr = "";
                continue;
            }
            newStr += str[i];
        }
        
        idandNick.push_back(newStr);
        return idandNick;
    }
    else if(status == "Change"){
        bool isend = false;
        string newStr = "";
        for(int i = 7;i<str.size();i++){
            if(str[i] == ' '){
                idandNick.push_back(newStr);
                isend = true;
                newStr = "";
                continue;
            }
            newStr += str[i];
        }
        
        idandNick.push_back(newStr);
        return idandNick;
    }
    
    else if(status == "Leave"){
        string newStr = "";
        for(int i = 6;i<str.size();i++){
            newStr += str[i];
        }
        idandNick.push_back(newStr);
        return idandNick;
    }
}

struct data{
    string id;
    string nickname;
    string status;
};

typedef struct data d;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<d> statusArr;
    map<string,string> idtoNick;
    map<string,string>::iterator iter;
    
    for(int i = 0;i<record.size();i++){
        string status = "";
        if(record[i][0] == 'E'){
            status = "Enter";
        }
        else if(record[i][0] == 'L'){
            status = "Leave";
        }
        else if(record[i][0] == 'C'){
            status = "Change";
        }
        
        vector<string> idandNickname = parseUserID(record[i],status);
        if(status != "Leave"){
            idtoNick[idandNickname[0]] = idandNickname[1];
        }
        
        if(status != "Change"){
            statusArr.push_back({idandNickname[0],idtoNick[idandNickname[0]],status});
        }
         
    }
    
    for(int i = 0;i<statusArr.size();i++){
        string originNickname = idtoNick[statusArr[i].id];
        if(originNickname != statusArr[i].nickname){
            statusArr[i].nickname = originNickname;
        }
        
        if(statusArr[i].status == "Enter"){
            string newansStr = statusArr[i].nickname;
            newansStr.append("님이 들어왔습니다.");
            answer.push_back(newansStr);
        }
        else if(statusArr[i].status == "Leave"){
            string newansStr = statusArr[i].nickname;
            newansStr.append("님이 나갔습니다.");
            answer.push_back(newansStr);
        }
    }
    
    return answer;
}