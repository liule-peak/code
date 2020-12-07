#include<iostream>
using namespace std;

const int MAX =1000;

void Merge(int r[],int r1[],int low,int m,int high)
{
    int i=low;
    int j=m+1;
    int k=low;
    while(i<=m && j <= high)
    {
         if(r[i] <= r[j])
         {
             r1[k++] = r[i++];
         }else{
             r1[k++] = r[j++];
         }
    }
    while(i<=m)
    {
        r1[k++]=r[i++];
    }
    while(j<=high)
    {
        r1[k++]=r[j++];
    }


}

void MergeSort(int r[],int low,int high)
{
    int m;
    int r1[MAX];
    if(low == high)
    {
        return ;
    }else
    {
        m = (low+high)/2;
        {
            MergeSort(r,low,m);
            MergeSort(r,m+1,high);
            Merge(r,r1,low,m,high);
        }
        for(int i=low;i<=high;i++)
        {
            r[i]=r1[i];
        }
    }
    
}


int main()
{
    int arr1[] = {8, 3, 2, 6, 7, 1, 5, 4};
    MergeSort(arr1, 0, 7);
    for (int i = 0; i < 8; i ++)
    {
        cout << arr1[i] << " ";
    }
    return 0;
}