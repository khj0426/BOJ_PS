#include <iostream>
#include <map>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        map<int,int> m;
        int n;
        cin >> n;
        int sum = 0;
        for(int i = 0;i<n;i++){
            int score;
            cin >> score;
            sum += score;
            m.insert({i,score});
        }
        int max_person = 0;
        int max_value = m[0];
        bool valid = false;
        for(int i = 1;i<n;i++){
            if(m[i] > max_value){
                max_value = m[i];
                max_person = i;
            }
        }
        
        for(int i = 0;i<n;i++){
            if(max_person != i){
                if(max_value == m[i]){
                    valid = true;
                }
            }
        }
        if(valid == true){
            cout << "no winner" << '\n';
        }
        else{
           int N = sum/2;
            if(max_value > N){
                cout << "majority winner" << ' ' << max_person + 1 << '\n';
            }
            else{
                cout << "minority winner" << ' ' << max_person + 1<< '\n';
            }
        }
    }
}