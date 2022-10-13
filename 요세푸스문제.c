#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0

//백준 1158 연결리스트 구현
 
typedef struct _Node{
    int data;
    struct _Node *next;
}node;
 
typedef struct _CLIST{
    node *cur;
    node *tail;
    node *before;
    node *head;
    int numofdata;
}CList;
 
typedef CList list;
 
int empty(list *plist){
    if(plist->numofdata == 1){
        return True;
    }
    else{
        return False;
    }
}
 
void listinit(list *plist){
    plist->numofdata = 0;
    plist->tail = NULL;
}
 
void insert(list *plist,int data){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    if(plist->tail == NULL){
        newnode->next = newnode;
        plist->tail = newnode;
    }
    else{
        newnode->next = plist->tail->next;
        plist->tail->next = newnode;
        plist->tail = newnode;
    }
    plist->numofdata = plist->numofdata + 1;
}
int lfirst(list *plist){
    if(plist->tail == NULL){
       return False;
    }
    else{
        plist->before = plist->tail;
        plist->cur = plist->tail->next;
        return True;
    }
}
 
int lNext(list *plist){
    if(plist->tail == NULL){
        return False;
    }
    else{
        plist->before = plist->cur;
        plist->cur = plist->cur->next;
        return True;
    }
}
int lRemove(list *plist){
    node *del = plist->cur;
    int rdata = del->data;
    if(del == plist->tail){  //삭제 대상이 꼬리인 경우
        if(plist->tail == plist->tail->next){
            plist->tail == NULL;
        }
        else{
            plist->tail = plist->before;
        }
    }
 
        plist->before->next = plist->cur->next;
        plist->cur = plist->before;
        free(del);
        plist->numofdata = plist->numofdata - 1;
        plist->cur = plist->before->next;
 
 
    return rdata;
 
 
}
int main(void){
    list lt;
    int n,k;
    scanf("%d %d",&n,&k);
 
    listinit(&lt);
    for(int i = 1;i<=n;i++){  
        insert(&lt,i);
    }
 
    lfirst(&lt);
    printf("<");
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<k-1;j++){
            lNext(&lt);
        }
        if(i != n){
        printf("%d, ",lRemove(&lt));
        }
        else if(i == n){
            printf("%d",lRemove(&lt));
        }
    }
    printf(">");
 
 
 
 
}