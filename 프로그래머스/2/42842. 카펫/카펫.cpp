#include <string>
#include <vector>
#include <math.h>
//10 2 43 
// 8 1 33
// 24 24 86
// 
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x,y;
    int v = brown + yellow;
    for(int i =1;i*i<=v;i++){
        if(v % i == 0){
            int z1 = i;
            int z2 = v/i;
           
            if((z1-2) * (z2-2) == yellow){
                x = z1;
                y = z2;
            }
        }
    }
    
    answer.push_back(max(x,y));
    answer.push_back(min(x,y));
    
    return answer;
}