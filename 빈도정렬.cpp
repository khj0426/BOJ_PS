#include <iostream>
#include <cstdlib>
#include <map>
 
//백준 빈도정렬 (BOJ 2910)

using namespace std;
 
struct arr{
    int frequency; //빈도
    int value; //배열의 값
    int index; //index index가 낮은거부터 우선적으로
};
 
int compare(const void *a,const void *b){
    struct arr num1 = *(struct arr *)a;
    struct arr num2 = *(struct arr *)b;
    if(num1.frequency > num2.frequency){ //빈도수가 큰 순서대로
        return -5;
    }
    else if(num1.frequency < num2.frequency){
        return 5;
    }
    else if(num1.frequency == num2.frequency){ //빈도 수가 같다면
        if(num1.index > num2.index){ //index가 낮은거부터 정렬
            return 3;
        }
        else if(num1.index < num2.index){
            return -3;
        }
        else{
            return 0;
        }
    }
 
 
}
 
int main(void){
 
    struct arr array[1001];
    int n;
    int k;
    cin >> n >> k;
 
    map<int,int> m;
    map<int,int> ::iterator iter;
 
    for(int i = 0;i<n;i++){ //array값 입력받고 array값이 key에 해당하는 value값 증가
        cin >> array[i].value;
        m[array[i].value]++;
        array[i].index = -1; //구조체의 index변수를 -1로 초기화
    }
 
 
    for(int i = 0;i<n;i++){ 
        for(int j = i+1;j<n;j++){
            if(array[i].value == array[j].value && array[j].index == -1){ //index에 값 넣기
                array[i].index = i;
                array[j].index = i;
            }
        }
    }
 
    for(int i = 0;i<n;i++){ //i가 j가 같지 않은 경우 -1인 상태니깐 그 경우에 index 따로 부여
        if(array[i].index == -1){
            array[i].index = i;
        }
    }
 
    for(int i = 0;i<n;i++){ //array[i]에 해당하는 빈도 값 구조체에 저장
        iter = m.find(array[i].value);
        array[i].frequency = iter->second;
    }
 
    qsort(array,n,sizeof(struct arr),compare); //qsort ->위의 compare함수를 근거로
 
    for(int i = 0;i<n;i++){ 
        cout << array[i].value << ' ';
    }
 
 
}