#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
struct infomation{
    int x;
    int y;
    int number;
};
 
typedef struct infomation info;
 
int n;
int first = 0;
char map[6][6];
info arr[50];
char copy_array[6][6];
bool is_escape = false;
 
int check_is_valid(int x,int y){
    bool valid = false;
    //오른쪽 탐색
    for(int i = y;i<n;i++){
        if(copy_array[x][i] == 'O'){
            break;
        }
        else if(copy_array[x][i] == 'S'){
            valid = true;
            return 1; //not valid -> 감시피할수 없음
        }
    }
 
    //왼쪽 탐색
    for(int i = y;i>=0;i--){
        if(copy_array[x][i] == 'O'){
            break;
        }
        else if(copy_array[x][i] == 'S'){
            valid = true;
            return 1;
        }
    }
 
    //위 탐색
    for(int i = x;i<n;i++){
        if(copy_array[i][y] == 'O'){
            break;
        }
        else if(copy_array[i][y] == 'S'){
            valid = true;
            return 1;
        }
    }
 
    //아래 탐색
    for(int i = x;i>=0;i--){
        if(copy_array[i][y] == 'O'){
            break;
        }
        else if(copy_array[i][y] == 'S'){
            valid = true;
            return 1;
        }
    }
    return -1; //감시 피할 수 있음
}
 
void init(){
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j] == 'X'){
                 arr[first].x = i;
                 arr[first].y = j;
                 arr[first].number = first;
                 first++;
            }
        }
    }
 
}
 
int permutation(){
    vector<int> combinate;
    for(int i = 0;i<3;i++){
        combinate.push_back(1);
    }
 
    for(int i = 0;i<first-3;i++){
        combinate.push_back(0);
    }
    sort(combinate.begin(),combinate.end());
 
 
    do{
        vector<pair<int,int>> temp;
        for(int i = 0;i<first;i++){
            if(combinate[i] == 1){
                temp.push_back({arr[i].x,arr[i].y});
            }
        }
 
 
        int count = 0;
 
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                copy_array[i][j] = map[i][j];
                if(copy_array[i][j] == 'T'){
                    count++;
                }
            }
        }
        copy_array[temp[0].first][temp[0].second] = 'O';
        copy_array[temp[1].first][temp[1].second] = 'O';
        copy_array[temp[2].first][temp[2].second] = 'O';
 
        int compare_count = 0;
 
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(copy_array[i][j] == 'T'){
                    int temp = check_is_valid(i,j);
                    if(temp == -1){
                        compare_count++;
                    }
                }
            }
 
 
        }
        if(count == compare_count){
            is_escape = true;
            break;
        }
 
 
    }while(next_permutation(combinate.begin(),combinate.end()));
 
    if(is_escape == true){
        return -1; //감시 피할 수 있음
    }
    else{
        return 1; //감시 피할 수 없음
    }
}
 
int main(void){
    init();
    int N = permutation();
    if(N == -1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}