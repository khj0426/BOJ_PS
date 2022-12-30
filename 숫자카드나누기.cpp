#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

vector<int> findallMeasures(int num){
    vector<int> measures;
    for(int i = 1;i*i<=num;i++){
        if(num % i == 0){
            measures.push_back(i);
            measures.push_back(num/i);
        }
    }
    sort(measures.begin(),measures.end(),cmp);
    return measures;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int firstA = 0;
    firstA = arrayA[0];
    for(int i = 1;i<arrayA.size();i++){
        firstA = gcd(firstA,arrayA[i]);
    }
    
    vector<int> allmeasures = findallMeasures(firstA);
    for(int i = 0;i<allmeasures.size();i++){
        bool iscannotDivide = false;
        for(int j = 0;j<arrayB.size();j++){
            if(arrayB[j] % allmeasures[i]  == 0){
                iscannotDivide = true;
                break;
            }
        }
        if(iscannotDivide == false){
            answer = allmeasures[i];
            break;
        }
    }
    int firstB = arrayB[0];
    for(int i = 1;i<arrayB.size();i++){
        firstB = gcd(firstB,arrayB[i]);
    }
    vector<int> allmeasuresB = findallMeasures(firstB);
    for(int i = 0;i<allmeasuresB.size();i++){
        bool iscannotDivide = false;
        for(int j = 0;j<arrayA.size();j++){
            if(arrayA[j] % allmeasuresB[i]  == 0 ){
                iscannotDivide = true;
                break;
            }
        }
        if(iscannotDivide == false){
            answer = max(answer,allmeasuresB[i]);
            break;
        }
    }
    if(answer == 1){
        return 0;
    }
    
    return answer;
}