#include<stdio.h>
int binarySearch(int arr[],int s,int n,int item)
{
    if(s<=n){   
   int mid= (s+n)/2;
   if(arr[mid]==item)
    return 1;
    else if(arr[mid]>item)
       return binarySearch(arr,0,mid-1,item);
        else if(arr[mid]<item)
            return binarySearch(arr,mid+1,n,item);
    }
            
            return 0;
}
int main()
{
    int arr[5]={40,50,60,70,80};
    printf("Enter item");
    int it;
    scanf("%d",&it);
   int f= binarySearch(arr,0,4,it);
   if(f==1)
   printf("item found");
}