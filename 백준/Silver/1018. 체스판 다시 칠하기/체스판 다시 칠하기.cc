#include <iostream>
#include <algorithm> // min을 사용하기 위해 추가
using namespace std;

char white[8][8];
char black[8][8];

int main(void) {
    char arr[51][51];
    int n, m;

    // 체스판 패턴 초기화
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                white[i][j] = 'W';
                black[i][j] = 'B';
            } else {
                white[i][j] = 'B';
                black[i][j] = 'W';
            }
        }
    }

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int minChanges = 987654321;

    // 8x8 체스판 부분을 확인
    for(int i = 0; i <= n - 8; i++) {
        for(int j = 0; j <= m - 8; j++) {
            // 8*8 확인
            int b = 0; // black 시작일 때의 변경 수
            int w = 0; // white 시작일 때의 변경 수
            for(int p = 0; p < 8; p++) {
                for(int q = 0; q < 8; q++) {
                    if(arr[i + p][j + q] != black[p][q]) {
                        b++;
                    }
                    if(arr[i + p][j + q] != white[p][q]) {
                        w++;
                    }
                }
            }
            minChanges = min(minChanges, min(b, w));
        }
    }
    
    cout << minChanges;

    return 0;
}