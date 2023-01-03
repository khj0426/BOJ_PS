#include <iostream>
#include <set>
using namespace std;

int n;
int arr[101][101];
set<int> s;
set<int>::iterator iter;
int sum;


bool init(){
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> arr[i][j];
            if(s.count(arr[i][j]) != 0){
                return false;
            }
            s.insert(arr[i][j]);
        }
    }
    sum = (n* (n*n + 1)) / 2;
    return true;
}

bool checkRow(){
    int sumofRow = 0;
    for(int i = 0;i<n;i++){
        sumofRow = 0;
        for(int j = 0;j<n;j++){
            sumofRow += arr[i][j];
        }
        if(sumofRow != sum){
            return false;
        }
    }
    return true;
}

bool checkColumn(){
    int sumofColumn = 0;
    for(int i = 0;i<n;i++){
        sumofColumn = 0;
        for(int j = 0;j<n;j++){
            sumofColumn += arr[j][i];
        }
        if(sumofColumn != sum){
            return false;
        }
    }
    return true;
}

bool checkrowDiagonal(){
    int sumofrowDiagonal = 0;
    for(int i = 0;i<n;i++){
        sumofrowDiagonal += arr[i][i];
    }
    if(sumofrowDiagonal != sum){
        return false;
    }
    return true;
}

bool checkCoulmnDiagonal(){
    int sumofColumnDiagonal = 0;
    for(int i = 0;i<n;i++){
        sumofColumnDiagonal += arr[i][n-i-1];
    }
    if(sumofColumnDiagonal != sum){
        return false;
    }
    return true;
}
int main(void){

    bool isNotValid = false;
    if(init() == false){
        isNotValid = true;
    }
    if(!checkRow()){
        isNotValid = true;
    }
    if(!checkColumn()){
        isNotValid = true;
    }
    if(!checkrowDiagonal()){
        isNotValid = true;
    }
    if(!checkCoulmnDiagonal()){
        isNotValid = true;
    }
    if(isNotValid){
        cout << "FALSE";
        
    }
    else{
        cout << "TRUE";
    }
}