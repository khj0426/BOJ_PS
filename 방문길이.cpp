#include <string>
#include <map>
#include <iostream>
#define MIN_RANGE -5
#define MAX_RANGE 5

using namespace std;

map<pair<string,string>,bool> visited;
map<pair<string,string>,bool>::iterator iter;

//좌표를 받아서 문자열로 반환
string makePostoStr(int x,int y){
    return to_string(x) + to_string(y);
}

//범위 확인
bool checkRange(int n){
    if(n >= MIN_RANGE && n <= MAX_RANGE){
        return true;
    }
    return false;
}


//시작좌표,도착예정좌표
bool isVisited(string start,string end){
    pair<string,string> Path;
    Path.first = start;
    Path.second = end;
    

    //반대의 경우 존재할 수도 있음
    pair<string,string> reverse_Path;
    reverse_Path.first = Path.second;
    reverse_Path.second = Path.first;
    
    iter = visited.find(Path);
    if(iter != visited.end()){
        //이미 방문한 경로
        return true;
    }
    iter = visited.find(reverse_Path);
    if(iter != visited.end()){
        return true;
    }
    visited[Path] = true;
    return false;
}

int solution(string dirs) {
    int answer = 0;
    int startX = 0;
    int startY = 0;
    for(int i = 0;i<dirs.size();i++){
        string cur = "";
        string next = "";
        //위로 이동하는 경우
        
        if(dirs[i] == 'U' && checkRange(startY+1)){
            cur = makePostoStr(startX,startY);
            next = makePostoStr(startX,startY+1);
            bool visit = isVisited(cur,next);
            startY++;
            if(!visit){
                answer++;
            }
        }
        else if(dirs[i] == 'D' && checkRange(startY-1)){
            cur = makePostoStr(startX,startY);
            next = makePostoStr(startX,startY-1);
            startY--;
            if(!isVisited(cur,next)){
                answer++;
            }
        }
        else if(dirs[i] == 'R' && checkRange(startX+1)){
            cur = makePostoStr(startX,startY);
            next = makePostoStr(startX+1,startY);
            startX++;
            if(!isVisited(cur,next)){
                answer++;
            }
        }
        else if(dirs[i] == 'L' && checkRange(startX-1)){
            cur = makePostoStr(startX,startY);
            next = makePostoStr(startX-1,startY);
            startX--;
            if(!isVisited(cur,next)){
                answer++;
            }
        }
        cout << cur << ' ' << next << '\n';
    }
    return answer;
}