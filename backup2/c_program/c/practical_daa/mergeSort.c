#include<stdio.h>
void merge(int arr[],int l,int m,int h)
{
    int n1=m-l+1;
    int n2= h-m;
    int L[10], R[10];
    for (int i = 0; i < n1; i++)
    {
        L[i]=arr[i+l];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i]=arr[m+1+i];
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j< n2)
    {
        if (L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;k++;
    }
    while (j<n2)
    {
        arr[k]=R[j];
        k++;j++;
    }
    }
    void mergeSort(int arr[],int l,int h)
    {
        if(l<h)
        {
            int m=(l+h)/2;
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,h);
            merge(arr,l,m,h);
        }
    

}

int main()
{
    int arr[5]={40,80,90,1,70};
    mergeSort(arr,0,4);
    for (int i = 0; i < 5; i++)
    {
        printf("%d \t",arr[i]);
    }
    return 0;
}