#include <iostream>
#include <string>
#define MAX 36
using namespace std;
 
//백준 1331 나이트 투어

int map[MAX][MAX];

/*나이트가 이동할 수 있는 경로 (x,y)에서 이동한다면
(x-1,y+2),(x+1,y+2),(x+2,y+1),(x+2,y-1),(x+1,y-2),(x-1,y-2),(x-2,y-1),(x-2,y+1)
*/

int dx[8] = {-1,1,2,2,1,-1,-2,-2};
int dy[8] = {2,2,1,-1,-2,-2,-1,1};
 
int check_night(int x,int y,int next_x,int next_y){ 
    /*나이트가 이동할 수 있는지 확인하는 함수
    조건1 . (직전 좌표->현재 좌표로 이동가능한가)
    조건2 . (한번도 방문한 적 없는 좌표인가)
    */
    
    for(int i = 0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
     
        //범위 초과시 continue
        if(nx < 0 || ny < 0 || nx >= 6 || ny >= 6){
            continue;
        }
        //좌표가 같고 방문한 적 없다면 ++해주고 1 리턴
        if(nx == next_x && ny == next_y){
            if(map[nx][ny] == 0){
                map[nx][ny]++;
                return 1;
            }
            //그외에는 옳지 않은 경로->-1리턴
            else if(map[nx][ny] == 1){
                return -1;
            }
        }
 
    }
    //경로를 찾을 수 없는 경우
       return -1;
}
 
int main(void){
    int first_x = 0; 
    int first_y = 0;
    
    /*최초의 좌표 firstx,firsty*/
    
    
    //직전좌표와 입력받은 좌표(직전->현재로 이동해야 함)
    int pre_x = 0;
    int pre_y = 0;
    int curx = 0;
    int cury = 0;
    string str;
    
    for(int i = 0;i<MAX;i++){
        cin >> str;
 
        if(i == 0){ //x좌표 
            if(str[0] == 'A'){
                curx = 0;
            }
            else if(str[0] == 'B'){
                curx = 1;
            }
            else if(str[0] == 'C'){
                curx = 2;
            }
            else if(str[0] == 'D'){
                curx = 3;
            }
            else if(str[0] == 'E'){
                curx = 4;
            }
            else if(str[0] == 'F'){
                curx = 5;
            }
            cury = (str[1]-48) - 1; //y좌표
            first_x = curx;
            first_y = cury;
 
        }
        else{
            //좌표 갱신
            pre_x = curx;
            pre_y = cury;
 
             if(str[0] == 'A'){
                curx = 0;
            }
            else if(str[0] == 'B'){
                curx = 1;
            }
            else if(str[0] == 'C'){
                curx = 2;
            }
            else if(str[0] == 'D'){
                curx = 3;
            }
            else if(str[0] == 'E'){
                curx = 4;
            }
            else if(str[0] == 'F'){
                curx = 5;
            }
            cury = (str[1]-48) - 1;
            
            int N = check_night(pre_x,pre_y,curx,cury);
            if(N == -1){
                //check_night가 -1을 반환하면 옳바르지 않은 좌표
                cout << "Invalid";
                return 0;
            }
            else{
                continue;
            }
        }
    }
    
    //마지막좌표->처음좌표로 이동가능한지 확인
    int N = check_night(curx,cury,first_x,first_y);
    if(N == -1){
        cout << "Invalid";
        return 0;
    }
    cout << "Valid";
    return 0;
}