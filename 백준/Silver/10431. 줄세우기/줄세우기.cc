//뒤로 물러나는 횟수
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int t;
    cin >> t;
    
    while(t--){
        int testNum;
        cin >> testNum;
        
        
        int count = 0;
        vector<int> inputArr;
        vector<int> v;
        vector<int>::iterator iter;
        
        for(int i = 0;i<20;i++){
            int num;
            cin >> num;
            inputArr.push_back(num);
        }
        
        for(int i = 0;i<inputArr.size();i++){
            if(v.size() == 0){
                v.push_back(inputArr[i]);
            }
            else{
                int findIdx = -1;
                for(int j = 0;j<v.size();j++){
                    if(v[j] > inputArr[i]){
                        findIdx = j;
                        break;
                    
                    }
                }
                if(findIdx == -1){
                    v.push_back(inputArr[i]);
                }
                else{
                    iter = v.begin();
                    count += v.size()-findIdx;
                    v.insert(v.begin() + findIdx,inputArr[i]);
                }
            }
        }
        cout << testNum << ' ' << count << '\n';
    }
}
