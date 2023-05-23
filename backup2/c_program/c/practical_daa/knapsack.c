#include<stdio.h>
void knapsack(int n,float profit[], float weight[],float capacity)
    {
        int i;
        float x[20];
        float tp=0;
        float u =capacity;
        for ( i = 0; i < n; i++)
        {
            x[i]=0.0;
        }
/*        for ( i = 0; i < n; i++)
        {
            if(weight[i]>u)
                break;
            else
            {
                tp=tp+profit[i];
                u=u-weight[i];
                x[i]=1.0;
            }
            
        }
        if(u!=0)
        {
            x[i]=u/weight[i];
            tp=tp+x[i]*profit[i];
        }*/
      for ( i = 0; i <n; i++)
        {
            
        
        
           if(u!=0)
            {
                if(weight[i]<=u)
                {
                    tp=tp+profit[i];
                    
                    u=u-weight[i];
                    x[i]=1.0;
                }
                else
                {
                    
                    x[i]=u/weight[i];
                    tp=tp+x[i]*profit[i];
                    u=0;
                }
            }
        }
        printf("total profit %f", tp);
        


    }

int main()
{
    printf("Enter objects");
    int n;
    scanf("%d",&n);
    float w[20],p[20],pw[20],cap;
    printf("Enter weight");
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&w[i]);
    }
    printf("Enter profit");
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&p[i]);
    }
    for (int i = 0; i < n; i++)
    {
        pw[i]=p[i]/w[i];
    }
    
    for (int i = 0; i < n-1; i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(pw[j]<pw[j+1])
            {
                int temp= pw[j];
                pw[j]=pw[j+1];
                pw[j+1]=temp;

                 temp= p[j];
                p[j]=p[j+1];
                p[j+1]=temp;

                  temp= w[j];
                w[j]=w[j+1];
                w[j+1]=temp;

                 
            }
        }
    }
    /*for (int i = 0; i < n; i++)
    {
        printf("%f \n",pw[i]);
     
    }
     for (int i = 0; i < n; i++)
    {
        printf("%f \n",p[i]);
     
    }
     for (int i = 0; i < n; i++)
    {
        printf("%f \n",w[i]);
     
    }*/
    printf("enter knapsack size");
    scanf("%f",&cap);
        knapsack(n,p,w,cap);   
return 0;    
}