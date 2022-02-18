#include <stdio.h>
#define True 1
#define False 0
 
 
typedef struct _CSTACK{
    int arr[500000]; //탑의 높이를 저장할 용도
    int idx[500000]; //탑의 인덱스를 저장할 용도
    int topindex;
}cstack;
 
typedef cstack Stack;
 
void Stackinit(Stack *pstack){
    pstack->topindex = -1;
}
 
int Empty(Stack *pstack){
    if(pstack->topindex == -1){
        return True;
    }
    else{
        return False;
    }
}
 
void Push(Stack *pstack,int data,int i){
    pstack->topindex = pstack->topindex + 1;
    pstack->arr[pstack->topindex] = data;
    pstack->idx[pstack->topindex] = i;
}
 
void Pop(Stack *pstack){
    pstack->topindex = pstack->topindex - 1;
}
 
int Top(Stack *pstack){
    return pstack->arr[pstack->topindex];
}
 
int Topindex(Stack *pstack){
    return pstack->idx[pstack->topindex];
}
 
int main(void){
    Stack stack;
    Stackinit(&stack);
 
    int n;
    scanf("%d",&n);
 
    int arr[500010];
    for(int i = 1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
 
    for(int i = 1;i<=n;i++){
        if(Empty(&stack)){ //스택이 비어있을 때
            printf("0 ");
            Push(&stack,arr[i],i);
        }
        else if(Top(&stack) > arr[i]){ //스택의 Top값이 배열의 값보다 클 때
            printf("%d ",Topindex(&stack));
            Push(&stack,arr[i],i);
        }
        else if(Top(&stack) < arr[i]){ //스택의 Top값이 배열의 값보다 작을 때
            while(!Empty(&stack)){ //스택이 비어있지 않다면
                Pop(&stack); //Pop연산
 
                if(Empty(&stack)){ //Pop연산 후 스택이 비었다 -> 0찍고 배열의 값 Push
                    printf("0 ");
                    Push(&stack,arr[i],i);
                    break;
                }
             else if(Top(&stack) > arr[i]){//Pop연산 후 Top값이 배열의 값보다 크다->Top인덱스값 찍고 Push
                    printf("%d ",Topindex(&stack));
                    Push(&stack,arr[i],i);
                    break;
                }
            }
        }
    }
}