#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define True 1
#define False 0
#define LEN 2000000

//백준 큐2(18258)
 
typedef struct _CQUEUE{
    int front;
    int rear;
    int arr[LEN+1];
}CQUEUE;
 
typedef CQUEUE Queue;
 
void Queueinit(Queue *pq){
    pq->front = 0;
    pq->rear = 0;
}
 
int Empty(Queue *pq){
    if(pq->rear == pq->front){
        return True;
    }
    else{
        return False;
    }
}
 
int Nextidx(int pos){
    if(pos == LEN-1){
        return 0;
    }
    else{
        return pos+1;
    }
}
 
void Enqueue(Queue *pq,int data){
    if(Nextidx(pq->rear) == pq->front){
        exit(0);
    }
    else{
        pq->rear = pq->rear + 1;
        pq->arr[pq->rear] = data;
    }
}
 
int Dequeue(Queue *pq){
    if(Empty(pq)){
        return -1;
    }
    else{
        pq->front = pq->front + 1;
        return pq->arr[pq->front];
    }
}
 
int Front(Queue *pq){
    if(Empty(pq)){
        return -1;
    }
    else{
        return pq->arr[pq->front+1];
}
}
 
int Back(Queue *pq){
    if(Empty(pq)){
        return -1;
    }
    else{
        return pq->arr[pq->rear];
    }
}
 
int Size(Queue *pq){
    return pq->rear - pq->front;
}
 
int main(void){
    Queue q;
    Queueinit(&q);
 
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        char arr[20];
        scanf("%s",arr);
        if(strcmp(arr,"push") == 0){
            int x;
            scanf("%d",&x);
           Enqueue(&q,x);
        }
        else if(strcmp(arr,"pop") == 0){
            printf("%d\n",Dequeue(&q));
        }
        else if(strcmp(arr,"size") == 0){
            printf("%d\n",Size(&q));
        }
        else if(strcmp(arr,"empty") == 0){
            printf("%d\n",Empty(&q));
        }
        else if(strcmp(arr,"front") == 0){
            printf("%d\n",Front(&q));
        }
        else if(strcmp(arr,"back") == 0){
            printf("%d\n",Back(&q));
        }
    }
}