#include<stdio.h>
int main()
{
    int n;
    printf("Enter");
    scanf("%d",&n);
    int p[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&p[i]);
    }
    int m[n][n];
    int s[n][n];
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++)
        {
            m[i][j]=0;
            s[i][j]=0;
        }
    }
    int min;
    for(int d=1;d<n-1;d++)
    {
        for(int i=1;i<n-d;i++)
        {
            min=999; int j=i+d;
            for(int k=1;k<=j-1;k++)
        {
            int q= m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
            if(q<min)
            {
                min=q;
                s[i][k]=k;
            }
        }
            m[i][j]=min;   
        }
    }    
    printf("%d",m[1][n-1]);
}