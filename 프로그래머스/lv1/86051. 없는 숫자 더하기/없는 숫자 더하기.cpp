#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    bool arr[10] = {false, };
    for(int i = 0;i<numbers.size();i++){
        arr[numbers[i]] = true;
    }
    for(int i =0;i<10;i++){
        if(arr[i] == false){
            answer = answer + i;
        }
    }
    return answer;
}