#include<stdio.h>
void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void maxheapify(int a[],int n,int i)
{
    int largest =i;
    int l=i*2;
    int r=(2*i)+1;
    if(l<=n && a[l]>a[largest])
    {
        largest=l;
    }
    if(r<=n && a[r]>a[largest])
    {
        largest=r;
    }
    if(i!=largest)
    {
        swap(&a[i],&a[largest]);
        maxheapify(a,n,largest);
    }
}

void heapSort(int a[],int n)
{
    for (int i = n/2; i >=1; i--)
    {
        maxheapify(a,n,i);
    }
    for (int i = n; i >=1; i--)
    {
        swap(&a[1],&a[i]);
        maxheapify(a,i-1,1);
    }
    
}
int main()
{
    int n;
    printf("Enter size");
    scanf("%d",&n);
    int arr[20];
    printf("Enter elements");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&arr[i]);
    }
    heapSort(arr,n);
    printf("Heap Sort \n");
     for (int i = 1; i <= n; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}