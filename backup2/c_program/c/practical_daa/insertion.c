#include<stdio.h>
void insertion(int arr[],int n)
{
    int key,j;
    for (int i = 1; i < n; i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && key<arr[j])
        {
         arr[j+1]=arr[j];
         j--;
        }
        arr[j+1]=key;
    }
    
}
int main()
{
    int arr[5]={40,80,90,1,70};
    insertion(arr,5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d \t",arr[i]);
    }
 return 0;   
}