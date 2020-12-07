#include<iostream>
using namespace std;

int maxsum(int arr[],int low,int high)
{
    int sum = 0, midsum = 0, sum1 = 0, sum2 = 0;
    int m,s1,lefts,s2,rights;
    if(low == high)
    {
        return arr[low];
    }else{
        m=(low+high)/2;
        sum1 = maxsum(arr,low,m);
        sum2 = maxsum(arr,m+1,high);

        s1=0;
        lefts=0;
        for(int i=m;i>=0;i--)
        {
            lefts+=arr[i];
            if(lefts > s1)
            {
                s1 =lefts;
            }
        }
        s2=0;
        rights=0;
        for(int j=m+1;j<=high;j++)
        {
            rights+=arr[j];
            if(rights > s2)
            {
                s2 = rights;
            }
        }
        midsum= s1+s2;
        
        if(sum1 > midsum)
        {
            sum = sum1;
        }else{
            sum = midsum;
        }

        if(sum2 > sum)
        {
            sum = sum2;
        }
        return sum;
    }
}

int main()
{
    int arr1[] = {-20, 11, -4, 13, -5, -2};
    cout << maxsum(arr1,0,5);
    return 0;
}