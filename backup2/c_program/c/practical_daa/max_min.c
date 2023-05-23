#include<stdio.h>
int max=0,min=999;
void max_min(int arr[],int l,int h)
{
    if(l==h)
     {
        max=min=arr[l];
     }
     else if (l== h-1)
     {
        if(arr[l]>arr[h])
        {
            max=arr[l];
            min=arr[h];
        }
        else
        max=arr[h];
        min=arr[l];
     }
     else
     {
        int m =(l+h)/2;
        int max1,min1;
        max_min(arr,l,m);
        max1=max;min1=min;
        max_min(arr,m+1,h);
        if(max1>max)
            max = max1;
        if(min1<min)
        min = min1;
        
     }
     
}

int main()
{
    int n;
    printf("Enter array size");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    max_min(arr,0,n-1);
    printf("%d is max and %d is min",max,min);
    return 0;
}