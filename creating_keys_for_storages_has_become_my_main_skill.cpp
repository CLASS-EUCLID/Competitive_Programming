#include <stdio.h>
// 060325
void fill(int *v,int n,int f)
{
    for(int i = 0;i<n;i++)
    {
        v[i] = f;
    }
    return;
}

void printv(int *v,int n)
{
    for(int i = 0;i<n;i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
    return;
}


int main(void)
{
    int n;
    int v[200000];
    scanf("%d",&n);
    while(n--)
    {
        int t,x;
        int tmp = 0;
        scanf("%d%d",&t,&x);
        fill(v,t,x);
        for(int i = 0;i < t; i++)
        {
            v[i] = i;
            tmp |= i;
            if((~x) & tmp){
                for(int j = i;j < t;j++)
                {
                    v[i] = x;
                }
                break;
            }
        }
        if(tmp != x)
        {
            v[t-1] = x;
        }
        printv(v,t);
    }
}
