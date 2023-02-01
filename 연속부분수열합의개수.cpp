#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
//합으로 만들 수 있는 수

//79114

map<int,bool> Exist;
map<int,bool>::iterator iter;

int getCount(vector<int> v,int k){
    int count = 0;
    int index = 0;
    for(int i = 0;i<v.size();i++){
        int sum = 0;
        for(int j = i;j<i+k;j++){
            sum += v[j%v.size()];
        }
        
        iter = Exist.find(sum);
        if(iter == Exist.end() && sum != 0){
            count++;
            Exist.insert({sum,true});
        }
    }
    
    return count;
}
int solution(vector<int> elements) {
    int answer = 0;
    for(int i = 1;i<=elements.size();i++){
        answer += getCount(elements,i);
    }
    return answer;
}