#include<iostream>
using namespace std;

void merge(int arr[],int arr1[],int low,int m,int high){
    int i=low,j=m+1,k=low;
    while(i<=m&&j<=high)
    {
        if(arr[i]<=arr[j]){
            arr1[k++]=arr[i++];
        }else{
            arr1[k++]=arr[j++];
        }
    }
    while(i<=m){
        arr1[k++]=arr[i++];
    }
    while(j<=high)
    {
        arr1[k++]=arr[j++];
    }
}


void ds(int arr[],int low,int high)
{
    int m,arr1[1000];
    if(low==high)
    {
        return ;
    }else{
        m=(low+high)/2;
        ds(arr,low,m);
        ds(arr,m+1,high);
        merge(arr,arr1,low,m,high);
        for(int i=low;i<=high;i++){
            arr[i]=arr1[i];
        }
    }
}

int main()
{
    int arr[]={6,5,4,3,2,1};
    ds(arr,0,5);
    for(int i=0;i<6;i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}