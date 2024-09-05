#include <iostream>
#include <string>
#include <map>

using namespace std;

int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

int main() {
    string king, wall;
    int n;
    
    cin >> king >> wall >> n;
    
    int king_x = king[0] - 'A';
    int king_y = king[1] - '1';
    int wall_x = wall[0] - 'A';
    int wall_y = wall[1] - '1';
    
    map<string, int> mapping = {
        {"R", 3}, {"L", 2}, {"B", 1}, {"T", 0},
        {"RT", 4}, {"LT", 6}, {"RB", 5}, {"LB", 7}
    };
    
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        
        int findD_ = mapping[command];
        int nxKing = king_x + dx[findD_];
        int nyKing = king_y + dy[findD_];
        
        if (nxKing < 0 || nyKing < 0 || nxKing >= 8 || nyKing >= 8) {
            continue; // 킹이 체스판 밖으로 나가는 경우
        }
        
        if (nxKing == wall_x && nyKing == wall_y) {
            int nxWall = wall_x + dx[findD_];
            int nyWall = wall_y + dy[findD_];
            
            if (nxWall < 0 || nyWall < 0 || nxWall >= 8 || nyWall >= 8) {
                continue; // 돌이 체스판 밖으로 나가는 경우
            } else {
                wall_x = nxWall;
                wall_y = nyWall;
            }
        }
        
        king_x = nxKing;
        king_y = nyKing;
    }
    
    cout << char(king_x + 'A') << char(king_y + '1') << '\n';
    cout << char(wall_x + 'A') << char(wall_y + '1') << '\n';
    
    return 0;
}
