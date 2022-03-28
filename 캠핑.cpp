#include <stdio.h>
 //백준 4796 캠핑
int main(void){
    int count = 1;
    while(1){
        int l,p,v;
        scanf("%d %d %d",&l,&p,&v);
        if(l == 0 && p == 0 && v == 0){
            break;
        }
        else{
           if(v%p < l){ 
           printf("Case %d: %d\n",count,(v/p)*l + v%p);
           }
            else{
                printf("Case %d: %d\n",count,(v/p)*l + l);
            }
        }
        count++;
    }
}