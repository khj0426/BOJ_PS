#include <iostream>
#include <set>
#include <map>
#include <string>

//백준 21939 문제 추천 시스템 Verseion 1

using namespace std;
/* 난이도- 문제번호 순으로 멀티셋에 넣고 , 문제번호-난이도를 맵에 넣어준다(문제번호는 고유함).
solved가 들어왔을떄, {문제번호,난이도} 세트를 멀티셋에서 찾아서 제거.
recommend시 멀티셋은 키값기준 오름차순 정렬이니깐, 1일떄 뒤에서 , -1일때 앞에서 찾아준다.
*/
 
int main(void){
    multiset<pair<int,int>> m;
    multiset<pair<int,int>>::iterator iter;
    multiset<pair<int,int>>::reverse_iterator riter; //문제번호-난이도 세트의 멀티셋(난이도 기준)
 
    map<int,int> m_set;
    map<int,int>::iterator miter; //문제번호 -난이도 저장하는 맵 (문제번호 기준)
 
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int number,hard;
        cin >> number >> hard;
        m.insert(pair<int,int>(hard,number)); //멀티셋에 난이도-문제번호 쌍을 넣어주고
        m_set[number] = hard; //문제번호에 대한 난이도 맵에 저장
    }
 
    int l;
    cin >> l;
    for(int i = 0;i<l;i++){
        string cmd;
        cin >> cmd;
        if(cmd == "recommend"){
            int x;
            cin >> x;
            if(x == 1){ //뒤에서 뽑기
                riter = m.rbegin();
                cout << riter->second << '\n';
            }
            else if(x == -1){ //앞에서 뽑기
                iter = m.begin();
                cout << iter->second << '\n';
            }
        }
        else if(cmd == "add"){
            int number,hard;
            cin >> number >> hard;
            m.insert(pair<int,int>(hard,number));
            m_set[number] = hard;
        }
        else if(cmd == "solved"){
            int num; //문제번호
            cin >> num;
            
            /*난이도 꺼내오기*/
            miter = m_set.find(num); 
            int hard = miter->second;
            
            m.erase(m.find(pair<int,int>(hard,num))); //멀티셋에서 {난이도,문제번호} 쌍 제거
 
        }
    }
 
 
}