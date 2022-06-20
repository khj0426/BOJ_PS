#include <stdio.h>
 
int height[7];
int input[9];
int flag;
 
void combination(int sum, int cnt, int idx)
{        
    if(cnt == 7)
    {        
        if(sum == 100)
        {
            flag = 1;
            return;
        }
        else
        {
            return;
        }
    }
    
    for(int i = idx; i < 9; i++)
    {
        height[cnt] = input[i];
        combination(sum + height[cnt], cnt+1, i+1);
        if(flag == 1)
        {
            return;
        }
    }
}
 
int main(void)
{
//    freopen("B2309_input.txt", "r", stdin);
    
    for(int i = 0; i < 9; i++)
    {
        scanf("%d", &input[i]);
    }
    
    combination(0, 0, 0);
    
    // 버블 정렬 -> 오름차순 출력을 위해 
    for(int i = 6; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(height[j] > height[j+1])
            {
                int temp = height[j];
                height[j] = height[j+1];
                height[j+1] = temp;
            }
        }
    }
    
    for(int i = 0; i < 7; i++)
    {
        printf("%d\n", height[i]);
    }
    
    return 0;
}