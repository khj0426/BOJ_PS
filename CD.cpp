#include <iostream>
#include <unordered_map>
 
//백준 4158 CD

using namespace std;
 
int main(void){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
	while(1){
    bool big_cd = false;
    int n,l;
    cin >> n >> l;
    if(n == 0 && l == 0){
    	break;
    }
    if(n > l){ //상근이의 CD 개수가 큰 경우
        big_cd = true;
    }
    else{ //선영의 CD개수가 크거나 같은경우
        big_cd = false;
    }
    unordered_map<int,int> m;
    unordered_map<int,int>::iterator iter;
    int count = 0;
 
    if(big_cd == true){
        for(int i = 0;i<n;i++){
        int input;
        cin >> input;
        m.insert(pair<int,int>(input,input));
        }
 
        for(int i = 0;i<l;i++){
            int check;
            cin >> check;
            iter = m.find(check);
            if(iter != m.end()){
                count++;
            }
 
        }
    }
 
    else if(big_cd == false){
        for(int i = 0;i<l;i++){
            int input;
            cin >> input;
            m.insert(pair<int,int>(input,input));
        }
        for(int i = 0;i<n;i++){
            int check;
            cin >> check;
            iter = m.find(check);
            if(iter != m.end()){
                count++;
            }
        }
    }
 
        cout << count << '\n';

	}
 
 
}