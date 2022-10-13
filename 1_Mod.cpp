#include <iostream>
//백준 4375 1

/*모듈러 산술 성질 
(A+B)%mod C = (A mod C + B mod C)%C
(A-B)%mod C = (A mod C - B mod C)%C
*/

using namespace std;
int main(void){
    
    long long n;
    while(cin >> n){
        long long first = 1; //1부터시작
        long long count = 1; //1로만 이루어진 수의 자릿수
        while(1){
            first = first % n; //first가 n의 배수일 경우 탈출
            if(first == 0){
                break;
            }
            first = (first * 10)%n + 1%n; 
            /* first 1 -> 11로 갈떄 (현재 1일때)
            11 % n = (first * 10 mod n + 1 mod n) % n
            
            first  11 -> 111로 갈떄(현재 11일떄)
            111 % n -> (10*11 + 1)%n == (10*11%n + 1%n)%n
            */
            count++; //자릿수 증가
        }
        cout << count << '\n';
    }
}