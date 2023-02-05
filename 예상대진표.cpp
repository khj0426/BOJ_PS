#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;


//1 2  23 34  n-1 n
//2 2 5 7

//

// 8 4 7
// 2 4

// 1 2 
// 12 34 56 78

// 14 57 
//12345678

//2357
//1234
// 4 



int solution(int n, int a, int b)
{
    int answer = 0;
    
    while(1){
        int valueMin = min(a,b);
        int valueMax = max(a,b);
        if(abs(a-b) == 1){
            int odd = 0;
            int even = 0;
            if(valueMax % 2 == 0){
                odd = valueMax;
                even = valueMin;
            }
            else if(valueMin % 2 == 0){
                odd = valueMin;
                even = valueMax;
            }
            if(odd - even == 1){
                break;
            }
            // 12 34 56 78
            
        
            //
        }
        
        if(a % 2 == 0){
            a = a / 2;
        }
        else if(a % 2 != 0){
            a = (a / 2) + 1;
        }
        
        if(b % 2 == 0){
            b = b / 2;
        }
        else if(b % 2 != 0){
            b = (b / 2) + 1;
        }
        answer++;
        
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    
    return answer + 1;
}