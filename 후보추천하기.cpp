#include <iostream>
#include <algorithm>
 
using namespace std;

//백준 1713 후보 추천하기
 
struct candidate{
    int count; //등장횟수
    int index; //인덱스
    int number; //후보의 번호
};
 
bool compare(struct candidate a,struct candidate b){
    if(a.count != b.count){ //등장횟수가 같지 않다면
        return a.count < b.count; //등장횟수 오름차순
    }
    else if(a.count == b.count){ //등장횟수가 같다면
        return a.index < b.index; //인덱스 기준 오름차순
    }
}
 
bool compare_second(struct candidate a,struct candidate b){
    return a.number < b.number;
}
 
int main(void){
    int N; //사진틀의 개수와
    int student; //전체 학생의 총 추천 횟수
    cin >> N;
    cin >> student;
    struct candidate arr[1000];
 
    int size = 0; //size의 초기값 -> 0으로
    for(int i = 0;i<student;i++){
        int num;
        cin >> num;//추천받은 학생을 입력받고
 
        if(size == 0){ //size가 0인경우 (아직 추천받은 학생이 구조체 배열에 안들어온 경우)
            arr[i].count = 1;  //해당 구조체배열의 등장횟수 0으로 초기화
            arr[i].index = i; //index를 i로
            arr[i].number = num; //후보의 번호 넣어주기
            size++; //크기 1 증가
        }
        else if(size < N){ //크기 < 사진틀인 경우
            bool is_same = false; //같은 후보가 있는지 여부를 알려주는 변수
            for(int j = 0;j<size;j++){
                if(arr[j].number == num){ //만약 같은 후보번호가 있다면
                    arr[j].count++; //해당 후보번호의 등장횟수 증가시키고
                    is_same = true;  //is_same -> true값으로
                }
            }
            if(is_same == false){ //해당 후보번호가 중복 x인경우
                arr[i].count = 1; //size==0일떄처럼 넣어주기
                arr[i].index = i;
                arr[i].number = num;   
            }
             size++;//크기 ++
        }
        else if(size == N){ //크기가 같아진 경우
            bool is_same = false; //후보가 같은지 확인하는 용도
            for(int j = 0;j<size;j++){
                if(arr[j].number == num){ //같은 후보가 있는경우 count ++ 
                    arr[j].count++;
                    is_same = true;
                }
            }
            if(is_same == false){ //같은 후보가 없는 경우
                sort(arr,arr+size,compare); //compare따라 정렬해주고
                arr[0].count = 1; //후보를 넣어주기
                arr[0].index = i;
                arr[0].number = num;
                size = N;
            }
        }
    }
 
    sort(arr,arr+size,compare_second); //후보의 번호 오름차순 정렬
    for(int i = 0;i<size;i++){
        if(arr[i].number != 0){ 
        cout << arr[i].number << '\n';
        }
    }
}