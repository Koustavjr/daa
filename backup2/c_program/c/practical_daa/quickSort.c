#include<stdio.h>
void swap(int *a, int *b)
{
    int t =*a;
    *a=*b;
    *b=t;
}
int partition(int arr[],int l,int h)
{
    int p=arr[h];
    int k=l-1;
    for (int i = l; i <h ; i++)
    {if(arr[i]<=p){
        k++;
    swap(&arr[k],&arr[i]);
    }
    
    }
    swap(&arr[k+1],&arr[h]);
    return (k+1);
}
void quickSort(int arr[],int l,int h)
{
    if(l<h)
    {
        int p= partition(arr,l,h);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,h);
    }

}

int main()
{
    int arr[5]={40,80,90,1,70};
    quickSort(arr,0,4);
    for (int i = 0; i < 5; i++)
    {
        printf("%d \t",arr[i]);
    }
    return 0;
}