#include<stdio.h>
int v;
void display(int arr[][v])
{
    for(int i=0;i<v;i++)
    {
        for (int j= 0; j < v; j++)
        {
            printf("%d \t",arr[i][j]);
        }
        printf("\n");
        
    }
}
void dfs(int arr[][v],int visited[],int start)
{
    printf("%d \t",start);
    visited[start]=1;
    for (int i = 0; i < v; i++)
    {
        if (visited[i]!=1 && arr[start][i]==1)

        {
            dfs(arr,visited,i);
        }
        
    }
    
}
void bfs(int arr[][v],int start)
{
    int vis[v];
    for (int i = 0; i < v; i++)
    {
        vis[i]=0;
    }
    int queue[v];
    int f=-1,r=-1;
    f++;
    queue[++r]=start;
    vis[start]=1;
    while (f<=r)
    {
        start=queue[f++];
        printf("%d \t",queue[start]);
        for (int i = 0; i < v; i++)
        {
            if(arr[start][i]==1 && vis[i]!=1)
            {
                queue[++r]=i;
                vis[i]=1;
            }
        }
        
    }
    
    
    
}
int main()
{
    printf("Enter vertex");
    scanf("%d",&v);
    int adj[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            adj[i][j]=0;;
        }
        
    }
    int s,d;
    while (s!=-1 && d!=-1)
    {
        printf("Enter edge from node (0 to %d) to (0 to %d)", v,v);
        scanf("%d%d",&s,&d);
        adj[s][d]=1;
        adj[d][s]=1;
    }
        display(adj); 
        bfs(adj,0);
        int vis[v];
        for (int i = 0; i < v; i++)
        {
            vis[i]=0;
        }
        dfs(adj,vis,0);

   return 0; 
}