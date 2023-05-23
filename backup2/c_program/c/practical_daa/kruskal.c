#include<stdio.h>
int i,j,a,b,u,v,n,ne=1;
int min,mincost=0,parent[10],cost[10][10];
int find(int i)
{
   while (parent[i])
   {
    i=parent[i];
   }
   return i;

}
int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;

}
void main()
{
    printf("Enter vertices");
    scanf("%d",&n);
    printf("Enter costs");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j]==0)
            cost[i][j]=999;
        }
        
    }
    printf("edges are");
        while(ne<n)
        {
            int min=999;
            for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n ; j++)
            {
                /* code */
            
            
            
                if(cost[i][j]<min)
                {
                    min =cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
            
        }   
        u=find(u);
        v=find(v);
        if(uni(u,v))
        {
            printf("%d edge (%d %d) cost is %d \n",ne++,a,b,min);
            mincost+=min;
        }
        cost[a][b]=cost[b][a]=999;
}
printf("total cost is %d",mincost);

}