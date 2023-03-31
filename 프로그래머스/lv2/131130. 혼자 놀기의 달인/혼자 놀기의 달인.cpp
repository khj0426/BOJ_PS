#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
//86372514

//8
//12346578

//

bool cmp(int a,int b){
    return a>b;
}
int solution(vector<int> cards) {
    int answer = 0;
    int arr[101];
    
    memset(arr,-1,sizeof(arr));
    vector<int> sizeofCard;
    
    for(int i = 0;i<cards.size();i++){
        if(arr[i] != -1){
            continue;
        }
        int sum = 0;
        int nextIndex = cards[i];
        while(1){
            if(arr[nextIndex-1] != -1){
                break;
            }
            sum++;
            arr[nextIndex-1] = i;
            nextIndex = cards[nextIndex-1];
        }
        sizeofCard.push_back(sum);
    }
    
    if(sizeofCard.size() == 1){
        return 0;
    }
    sort(sizeofCard.begin(),sizeofCard.end(),cmp);
    answer = sizeofCard[0] * sizeofCard[1];
    return answer;
    

}