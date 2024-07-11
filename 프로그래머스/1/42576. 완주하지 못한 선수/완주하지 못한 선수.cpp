#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    vector<string> participant_v;
    vector<string> completion_v;
    
    for(int i = 0;i<participant.size();i++){
        participant_v.push_back(participant[i]);
    }
    
    for(int i = 0;i<completion.size();i++){
        completion_v.push_back(completion[i]);
    }
    
    sort(participant_v.begin(),participant_v.end());
    sort(completion_v.begin(),completion_v.end());
    
    vector<string> vector_diff(participant_v.size());
    auto it = set_difference(
        participant_v.begin(),participant_v.end(),
        completion_v.begin(),completion_v.end(),
        vector_diff.begin());
    
    vector_diff.resize(it-vector_diff.begin());
    return vector_diff[0];
    
}