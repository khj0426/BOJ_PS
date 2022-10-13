#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define True 1
#define False 0

//백준 17413 단어 뒤집기 2
 
typedef struct _cstack{
 
    char arr[200000];
    int topindex;
 
}CSTACK;
 
typedef CSTACK Stack;
 
int Empty(Stack *pstack){
    if(pstack->topindex == -1){
        return True;
    }
    else{
        return False;
    }
}
void Stackinit(Stack *pstack){
    pstack->topindex = -1;
}
 
void Push(Stack *pstack,char data){
    pstack->topindex = pstack->topindex + 1;
    pstack->arr[pstack->topindex] = data;
}
 
char Pop(Stack *pstack){
   char data = pstack->arr[pstack->topindex];
    pstack->topindex = pstack->topindex - 1;
    return data;
}

 
int main(void){
    char array[100010];
    gets(array);
 
    int bool = 0;
 
    Stack stack;
    Stackinit(&stack);
 
    for(int i = 0;i<strlen(array);i++){
        if(array[i] == '<'){
            printf("<");
            bool = 1;
        }
        else if(array[i] == '>'){
            printf(">");
            bool = 0;
        }
        else{
 
            if(bool != 1 && array[i]!= ' '){
            Push(&stack,array[i]);
                                        }
            
            if(bool == 1){
                printf("%c",array[i]);
            }
            
       else if(array[i+1] == '<' || array[i] == ' ' || i == strlen(array)-1){
                while(1){
                    if(Empty(&stack)){
                        break;
                    }
                    printf("%c",Pop(&stack));
                } 
                if(array[i+1] != '<'){
                      printf(" ");
                }
        }
 
    }
}}