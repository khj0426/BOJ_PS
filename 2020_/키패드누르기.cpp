#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

map<char,pair<int,int>> Distance;
map<char,pair<int,int>>::iterator iter;

int CalculateDistance(int firstx,int firsty,int firstX,int firstY){
    return abs(firstx-firstX) + abs(firsty-firstY);
}

void mapInsert(){
    int firstChar = 1;
    for(int i = 1;i<=3;i++){
        for(int j = 1;j<=3;j++){
            Distance.insert({firstChar + '0',{i,j}});
            firstChar += 1;
        }
    }
    char charArr[3];
    charArr[0] = '*';
    charArr[1] = int(0) + '0';
    charArr[2] = '#';
    
    for(int j = 1;j<=3;j++){
        Distance.insert({charArr[j-1],{4,j}});
    }
}
//엄지 상하좌우 4가지 거리 1
//147은 왼쪽 엄지 
//369는 오른쪽 엄지
//2580은 두 엄지손가락 중 가까운 엄지손가락 
//같다면 오른손잡이는 오른쪽엄지, 왼손잡이는 왼손엄지
string solution(vector<int> numbers, string hand) {
    mapInsert();
    string answer = "";
    char LeftHand = '*';
    char RightHand = '#';
    
    for(int i = 0;i<numbers.size();i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer.append("L");
            LeftHand = numbers[i] + '0';
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer.append("R");
            RightHand = numbers[i] + '0';
        }
        else{
            pair<int,int> Left = Distance[LeftHand];
            pair<int,int> Right = Distance[RightHand];
            pair<int,int> Start = Distance[numbers[i] + '0'];
            int leftDistance = CalculateDistance(Left.first,Left.second,Start.first,Start.second);
            int rightDistance = CalculateDistance(Right.first,Right.second,Start.first,Start.second);
        
            if(leftDistance < rightDistance){
                answer.append("L");
                LeftHand = (numbers[i] + '0');
            }
            else if(leftDistance > rightDistance){
                answer.append("R");
                RightHand = (numbers[i] + '0');
            }
            else{
                if(hand == "left"){
                    answer.append("L");
                    LeftHand = (numbers[i] + '0');
                }
                else{
                    answer.append("R");
                    RightHand = (numbers[i] + '0');
                }
            }
        }
    }
    
    return answer;
}