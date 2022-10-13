#include <stdio.h>
#define LEN 1000000
#define True 1
#define False 0

//백준 오큰수 (오른쪽부터 찾기)
 
typedef struct _cstack{
    int arr[LEN];
    int topindex;
}CSTACK;
 
typedef CSTACK Stack;
 
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
 
void Push(Stack *pstack,int data){
    pstack->topindex = pstack->topindex + 1;
    pstack->arr[pstack->topindex] = data;
}
 
void Pop(Stack *pstack){
    pstack->topindex = pstack->topindex - 1;
}
 
int Top(Stack *pstack){
    return pstack->arr[pstack->topindex];
}
 
int main(void){
    Stack stack;
    Stackinit(&stack);
    int array[LEN];
    int IDX[LEN];
 
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&array[i]);
    }
 
    for(int i = n-1;i>=0;i--){
        if(Empty(&stack)){
            Push(&stack,array[i]);
            IDX[i] = -1;
        }
        else{
            if(Top(&stack) > array[i]){
                IDX[i] = Top(&stack);
                Push(&stack,array[i]);
 
            }
            else if(Top(&stack) <= array[i]){
                while(!Empty(&stack)){
                    Pop(&stack);
                    if(Empty(&stack)){
                        Push(&stack,array[i]);
                        IDX[i] = -1;
                        break;
                    }
                    else if(Top(&stack) > array[i]){
                        IDX[i] = Top(&stack);
                        Push(&stack,array[i]);
                        break;
                    }
                }
            }
        }
    }
 
    for(int i = 0;i<n;i++){
        printf("%d ",IDX[i]);
    }
}