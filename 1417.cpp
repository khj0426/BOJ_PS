#include<iostream>
#include<algorithm>

//백준 국회의원 선거
/*-> 1)while문을 돌리면서 내림차순 정렬을 실행.
     2)내림차순 정렬시 원소의 가장 큰 값이 0번째 인덱스에 오니깐 다솜의 투표수와 비교
     3)다솜의 투표수가 크다면 루프 탈출
     4)0번쨰 인덱스의 투표수가 크다면 
     
     ->0번쨰 인덱스 투표수 -- ,다솜의 투표수 ++,count증가
     
     */


using namespace std;

bool compare(int a,int b){ //내림차순 정렬
    return a>b;
}
int main(void){
    int n;
    cin >> n;
    int arr[50];

    int dasom;
    cin >> dasom;
    
    for(int i = 0;i<n-1;i++){
        cin >> arr[i];
    }
    sort(arr,arr+(n-1),compare);
    

    int count = 0;
    
        while(1){
            sort(arr,arr+(n-1),compare); //내림차순 정렬을 while문 돌리면서
            if(dasom > arr[0]){
                break; //다솜의 투표수가 투표 수가 가장 큰 후보보다 크다면 루프 탈출
            }
            else if(dasom <= arr[0]){
                dasom++;
                arr[0]--;
                count++; //다솜의 투표수가 투표수가 가장 큰 후보보다 작거나 같다면 count 증가, 
                //다솜의 표 증가
                // 투표수가 가장 큰 후보 투표수 --
            
            }
            
        }
    
    if(n != 1){ //n이 1이 아니면
    cout << count;
    }
    else if(n == 1){ //n이 1이면 
        cout << '0';
    }
    
    }
