#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
struct numcard{
    int value;
    string card;
};
 
bool compare(struct numcard a,struct numcard b){
    return a.card < b.card;
}
int main(void){
 
    int n;
    int M;
    cin >> n >> M;
   struct numcard arr[100];
    int index = 0;
 
    for(int i = n;i<=M;i++){
        string temp = to_string(i);
        string sum = "";
        for(int j = 0;j<temp.size();j++){
                  if(temp[j] == '0'){
                      sum = sum + "zero";
                  }
            else if(temp[j] == '1'){
                sum = sum + "one";
            }
            else if(temp[j] == '2'){
                sum = sum + "two";
            }
            else if(temp[j] == '3'){
                sum = sum + "three";
            }
            else if(temp[j] == '4'){
                sum = sum + "four";
            }
            else if(temp[j] == '5'){
               sum = sum + "five";
            }
            else if(temp[j] == '6'){
                sum = sum + "six";
            }
            else if(temp[j] == '7'){
                sum = sum + "seven";
            }
            else if(temp[j] == '8'){
                sum = sum + "eight";
            }
            else if(temp[j] == '9'){
                sum = sum + "nine";
            }
 
        }
        arr[index].value = i;
        arr[index].card = arr[index].card + sum;
        index++;
    }
    sort(arr,arr+index,compare);
 
    for(int i = 0;i<index;i++){
       cout << arr[i].value << " ";
        if(i%10 == 9){
            cout << '\n';
        }
 
    }
 
 
 
 
}