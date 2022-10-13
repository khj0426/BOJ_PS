#include <stdio.h>
#include <string.h>
 
int Num[11];
int count = 0;
char arr[25];
 
void Calculate_room(int i){
 
        if(arr[i] == '1'){
            Num[1]++;
        }
        else if(arr[i] == '0'){
            Num[0]++;
        }
        else if(arr[i] == '2'){
            Num[2]++;
        }
        else if(arr[i] == '3'){
            Num[3]++;
        }
        else if(arr[i] == '4'){
            Num[4]++;
        }
        else if(arr[i] == '5'){
            Num[5]++;
        }
        else if(arr[i] == '7'){
            Num[7]++;
        }
        else if(arr[i] == '8'){
            Num[8]++;
        }
        else if(arr[i] == '6' || arr[i] == '9'){
            count++;
            if(count%2 == 0){
                Num[9]++;
            }
            else if(count%2 != 0){
                Num[6]++;
            }
        }
 
}
 
int main(void){
 
    scanf("%s",arr);
    for(int i = 0;i<strlen(arr);i++){
        Calculate_room(i);
    }
 
    int Max = -1;
 
   for(int i = 0;i<=10;i++){
       if(Num[i] > Max){
           Max = Num[i];
       }
   }
    printf("%d",Max);
}