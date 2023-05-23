#include<stdio.h>
#include<stdlib.h>
int board[20],c=0;
void print(int n)
{
    printf("\n  solution %d \n", ++c);
    for (int i = 1 ; i <= n ; i++)
    {
        printf("%d \t",i);
    }
for (int i =1; i <=n; i++)
{
    printf("\n %d",i);
    for(int j=1;j<=n;j++)
    {
        if(board[i]==j)
        printf("Q \t");
        else
        printf("- \t");
        }
    }
}
int place(int row, int col)
{
    for(int i=1;i<=row-1;i++)
    {
        if(board[i]==col || abs(board[i]-col)== abs((row-i)))
          return 0;

    }
    return 1;

}

void queen(int row,int n)
{
    for(int col=1;col<=n;col++)
    {
        if(place(row,col))
        {
            board[row]=col;
            if(row==n)
            print(n);
            else
            queen(row+1,n);
        }
    }
}
int main()
{
    int n;
    printf("Enter queen");
    scanf("%d",&n);
    queen(1,n);
    return 0;
}