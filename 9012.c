#include <stdio.h>
#include <string.h>
 
#define True 1 
#define False 0

/*백준 9012 스택의 괄호쌍*/
 
typedef struct CSTACK{ //stack 구조체 선언
 
    char arr[50];
    int topindex;
 
}cSTACK;
 
typedef cSTACK Stack;
 
void Stackinit(Stack *pstack){ //스택의 초기화
    pstack->topindex = -1;
}
 
int Is_empty(Stack *pstack){ //스택이 비어있으면 True, 비어있지 않으면 False
    if(pstack->topindex == -1){
        return True;
    }
    else{
        return False;
    }
}
 
void Push(Stack *pstack,char data){ //스택의 Push연산
    pstack->topindex = pstack->topindex + 1;
    pstack->arr[pstack->topindex] = data;
}
 
void Pop(Stack *pstack){ //스택의 Pop연산
    pstack->topindex = pstack->topindex - 1;
}
 
char return_top(Stack *pstack){ //스택의 top에 해당하는 문자 반환
 
    return pstack->arr[pstack->topindex];
 
}
 
int main(void){
    Stack stack;
    Stackinit(&stack);
 
    int n;
    scanf("%d",&n); //n입력받고
 
    for(int i = 0;i<n;i++){
        char array[50];
        scanf("%s",array); //n만큼 배열 입력받고
 
        Stackinit(&stack); //스택을 초기화한다
 
        for(int i = 0;i<strlen(array);i++){ //괄호문자열의 길이만큼 루프 돌면서
 
            if(Is_empty(&stack) == True){ //스택이 비어있으면 Push연산
                Push(&stack,array[i]);
            }
 
            else{ //비어있지 않고
                if(return_top(&stack) == '(' && array[i] == ')'){ 
                    
                    //top이 ( 이고 괄호문자가 )이면 Pop연산 
                    
                    Pop(&stack);
                    
                }
                else{
                    Push(&stack,array[i]); //그 외에는 Push연산
                }
            }
        }
 
        if(Is_empty(&stack) == True){ 
            //괄호 문자열만큼 루프 돌고 끝났을때 스택이 비어있다 -> 올바른 괄호 문자열이다
            printf("YES\n");
        }
        else{
            printf("NO\n"); //스택이 비어있지 않다 ->올바르지 않은 문자열
        }
 
    }
}