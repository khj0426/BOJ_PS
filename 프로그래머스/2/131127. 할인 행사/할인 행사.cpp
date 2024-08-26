#include <string>
#include <vector>

#include <iostream>
#include <map>



//일정한 금액 -> 10일동안 회원자격

//매일 한가지 제품 할인 -> 하루 하나 구매

//내가 원하는 제품과 수량이 할인하는 날짜 -> 10일 연속 일치

//바나나 3 사과 2 쌀 2 돼지고기 2 냄비 1

//14일 

//

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    //원하는 제품 ->
    map<string,int> m;
    map<string,int>::iterator iter;
    
    map<string,int>::iterator m_iter;
    for(int i = 0;i<number.size();i++){
        m[want[i]] = number[i];
    }
    
    for(int i = 0;i<discount.size()-9;i++){
        //i부터 want의 개수까지

        map<string,int> getFruits;
        
        for(int j = i;j<i+10;j++){
            iter = getFruits.find(discount[j]);
            if(iter == getFruits.end()){
                getFruits[discount[j]] = 1;
            }
            else{
                int getFruitCount = iter->second;
                getFruits[discount[j]] = getFruitCount + 1;
            }
        }
        
        bool flag = false;
        
        for(iter = getFruits.begin();iter != getFruits.end();iter++){
            string fruit = iter->first;
            int fruitCount = iter->second;
            
            m_iter = m.find(fruit);
            if(m_iter == m.end()){
                flag = true;
                break;
            }
            if(fruitCount != m[fruit]){
                flag = true;
                break;
            }
        }
        if(flag == false){
            cout << i+1 << '\n';
            answer++;
        }
        
    }
    
    
    return answer;
}