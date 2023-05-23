#include<stdio.h>
void jsd(int n,float profit[],int d[],int max)
{
    int x[20];float tp=0.0;
    for (int i = 0; i <= max; i++)
    {
        x[i]=0;
    }
    for (int i = 1; i <=n; i++)
    {
        if(d[i]<=max)
        {
            if (x[d[i]]==0)
            {
                x[d[i]]=1;
                tp=tp+profit[i];
            }
            else
            {
                for (int j = 1; j <d[i]; j++)
                {
                    if(x[j]==0)
                    {
                        x[j]=1;
                        tp=tp+profit[i];
                        break;
                    }
                }
                
            }
            
        }
    }
    
        printf("total profit %f ",tp);    
}
int main()
{
    int n;
    printf("Enter jobs");
    scanf("%d",&n);
    printf("enter deadlines");
    int d[20];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&d[i]);
    }
    printf("Enter profit");
    float p[20];
    for (int i = 1; i <=n; i++)
    {
        scanf("%f",&p[i]);
    }
    for (int i = 1; i <=n-1; i++)
    {
        for (int j = 1; j <=n-1-i; j++)
        {
            if(p[j]<p[j+1])
            {
                int temp = p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                
                temp = d[j];
                d[j]=d[j+1];
                d[j+1]=temp;

            }

        }
        
    }
    int max=0;
    for (int i = 1; i <= n; i++)
    {
        if(max<d[i])
        max = d[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        printf("%f \n",p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d \n",d[i]);
    }
    printf("%d",max);   
    jsd(n,p,d,max);   
    return 0;    
}