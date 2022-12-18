#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define MAX_DISTANCE 987654321
 
using namespace std;
 
struct dataset{
    int x;
    int y;
    int number;
};
 
int ans = MAX_DISTANCE;
int n,m;
int arr[51][51];
int numof_chicken = 0;
 
vector<struct dataset> chicken; 
vector<int> combination;
vector<struct dataset> getRandomChicken;
vector<pair<int,int>> house;
 
void getInput(){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
               struct dataset temp_data;
               temp_data.x = i+1;
               temp_data.y = j+1;
               temp_data.number = numof_chicken;
               chicken.push_back(temp_data);
               numof_chicken += 1;
            }
            else if(arr[i][j] == 1){
                house.push_back({i+1,j+1});
            }
        }
    }
 
}
 
void setCombinate(){
    for(int i = 0;i<m;i++){
        combination.push_back(1);
    }
    for(int i = 0;i<numof_chicken - m;i++){
        combination.push_back(0);
    }
    sort(combination.begin(),combination.end());
}
 
void Init(){
    setCombinate();
}
 
void setRandomChicken(){
    getRandomChicken.clear();
}
 
int getDistance(int housex,int housey,int chickenx,int chickeny){
    return abs(housex-chickenx) + abs(housey-chickeny);
}
 
int CalculateDistance(){
    int totalDistance = 0;
    for(int i = 0;i<house.size();i++){
        int temp_distance = MAX_DISTANCE;
        for(int j = 0;j<getRandomChicken.size();j++){
            temp_distance =  min(getDistance(house[i].first,house[i].second,getRandomChicken[j].x,getRandomChicken[j].y),temp_distance);
        }
        totalDistance += temp_distance;
    }
 
    return totalDistance;
}
 
 
 
void pickChicken(){
    do{
        setRandomChicken();
        for(int i = 0;i<numof_chicken;i++){
            if(combination[i] == 1){
                getRandomChicken.push_back(chicken[i]);
            }
        }
       
        ans = min(ans,CalculateDistance());
    }while(next_permutation(combination.begin(),combination.end()));
}
 
int main(void){
    getInput();
    Init();
    pickChicken();
    cout << ans;
 
}
 