#include <iostream>
#include <string>
using namespace std;
int main(void){
    int max_a = 66;
    int max_b = 130;
    int max_c = 8;
 
    int n,a,b;
    cin >> n >> a >> b;
    if(a >= max_a && b >= max_b){
        cout << "Nice";
        return 0;
    }
    
    for(int i = 0;i<10;i++){ 
        n++;
        if(n > max_c){
            break;
        }
        int alpha,beta;
        cin >> alpha >> beta;
        
        a = a + (alpha * 3);
        int temp = 6 - alpha;
            b = b + (alpha * 3);
        
            if(temp <= beta){
                 b = b + (temp * 3);
            }
        else{
            b = b + (beta * 3);
        }
           

    }
 
    if(a >= max_a && b >= max_b){
        cout << "Nice";
    }
    else{
        cout << "Nae ga wae";
    }
}