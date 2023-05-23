#include<stdio.h>
#include<stdlib.h>
int v;
void print(int colour[])
{ printf("Solution exists \n");
    for (int i = 0; i <v ; i++)
    {
        printf("%d \t",colour[i]);
    }
    
}
int isSafe(int graph[][v],int colour[])
{
    for(int i=0;i<v;i++)
    {
        for(int j=i+1;j<v;j++)
        {
            if(graph[i][j]==1 && colour[i]==colour[j])
                return 0;
        }
    }
    return 1;
}

int graphColouring(int graph[][v],int m,int i,int colour[])
{
    if(i==v)
    {
        if(isSafe(graph,colour)==1)
        {
            print(colour);
            return 1;
        }
        return 0;
    }

    for (int j = 1; j <=m; j++)
    {
        colour[i]=j;
        if(graphColouring(graph,m,i+1,colour)==1)
        {
            return 1;
        }
        colour[i]=0;
    }
        return 0;

}

int main()
{
    int m;
    printf("Enter colour and vertices");
    scanf("%d %d",&m,&v);
 /*   int graph[4][4]={
        {0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0},};*/
        int graph[v][v];
        printf("Enter graph");
        for (int i = 0; i < v; i++)
        {
            for(int j=0;j<v;j++)
            {
                scanf("%d",&graph[i][j]);
            }
        }
        
        int colour[v];
        for (int i = 0; i < v; i++)
        {
            colour[i]=0;
        }
        if(graphColouring(graph,m,0,colour)==0)
        printf("solution doesnt exist");
        return 0;
}