#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//h번 이상 인용한 논문 h이상 h번 이하 
//h의 최대

//6 5 3 1 0

//1번 이상 
//4 //0
//0 6
// 3
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    
    int l = 0;
    int r = citations[citations.size()-1];
    int maxHindex = -1;
    while(l <= r){
        int mid = (l+r)/2;
        int H = 0;
        int lowerH = 0;
        for(int i = 0;i<citations.size();i++){
            if(citations[i] >= mid){
                H++;
            }
            else{
                lowerH++;
            }
        }
        if(H >= mid && lowerH <= mid){
            maxHindex = max(maxHindex,mid);
        }
        
        if(H < mid){
            r--;
        }
        else{
            l++;
        }
        
    }
    answer = maxHindex;
    return answer;
}