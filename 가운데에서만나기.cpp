#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
#define MAX_LENGTH 987654321
using namespace std;
 
int n,m;
int arr[201][201];
int allSums[201];
int k;
vector<int> C;
 
void Input(){
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i!=j){
                arr[i][j] = MAX_LENGTH;
            }
        }
    }
 
    for(int i = 0;i<m;i++){
        int A,B,T;
        cin >> A >> B >> T;
        arr[A][B] = min(arr[A][B],T);
    }
 
    cin >> k;
    for(int i = 0;i<k;i++){
        int city;
        cin >> city;
        C.push_back(city);
    }
}
 
void floyd(){
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(i != j){
                    arr[i][j] = min(arr[i][j],arr[i][k] + arr[k][j]);
                }
            }
        }
    }
}
 
 vector<pair<int,int>> CalculateMinDistanceCity(vector<int> city){
    //왕복시간들 중 최소가 되는 도시
 
   vector<pair<int,int>> ans; 
 
   int MIN_City = -1;
   int MIN_Value = MAX_LENGTH;
   for(int i = 1;i<=n;i++){
        int sum = 0;
        for(int j = 0;j<city.size();j++){
            //왕복시간
            if(i != city[j]){
               sum = max(arr[i][city[j]]+arr[city[j]][i],sum);
            }
        }
        if(sum <= MIN_Value){
            MIN_Value = sum;
            MIN_City = i;
            ans.push_back({i,sum});
        }
   }
   return ans;
}
 
int main(void){
    Input();
    floyd();
 
    vector<pair<int,int>> getAllCites = CalculateMinDistanceCity(C);
    sort(getAllCites.begin(),getAllCites.end());
    int MIN_DISTANCE = MAX_LENGTH;
    for(int i = 0;i<getAllCites.size();i++){
        MIN_DISTANCE = min(MIN_DISTANCE,getAllCites[i].second);
    }   
 
 
    for(int i = 0;i<getAllCites.size();i++){
        if(getAllCites[i].second == MIN_DISTANCE){
            cout << getAllCites[i].first << ' ';
        }
    }
}