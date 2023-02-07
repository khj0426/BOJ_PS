#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int Col = 0;

bool cmp(vector<int> data,vector<int> comparedata){
    if(data[Col-1] != comparedata[Col-1]){
        return data[Col-1] < comparedata[Col-1];
    }
    else if(data[Col-1] == comparedata[Col-1]){
        return data[0] > comparedata[0];
    }
}

int S_I(vector<int> data,int num){
    int sum = 0;
    for(int i = 0;i<data.size();i++){
        sum += (data[i] % num);
    }
    return sum;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    vector<int> sums;
    Col = col;
    sort(data.begin(),data.end(),cmp);
    for(int i = row_begin-1;i<=row_end-1;i++){
        sums.push_back(S_I(data[i],i+1));
    }
    
    for(int i = 0;i<sums.size();i++){
        answer = answer ^ sums[i];
    }
    return answer;
}