#include <iostream>
using namespace std;

//백준 1110 더하기 사이클
int main(void) {
    int n;
    cin >> n;
    int first = n;
    if (n == 0) {
        n = 1;
        cout << n;
        return 0;
    }
    int cnt = 0;

    if (n < 10) {
        n = n * 10;
        first = n;
    }

    while (1) {
        int divide = n / 10;
        int mod = n % 10;

        int sum = (divide + mod) % 10;

        n = mod * 10 + sum;

        cnt++;

        if (n == first) {
            cout << cnt;
            return 0;
        }

    }
}