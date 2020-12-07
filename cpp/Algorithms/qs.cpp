#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot = arr[low];
    while(low < high)
    {
        while(low < high && arr[high]>=pivot){
            --high;
        }
        arr[low]=arr[high];
        while(low < high && arr[low]<=pivot){
            ++low;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

void qs(int arr[],int low,int high){
    int pivotpos = partition(arr,low,high);
    if(low <high){
        qs(arr,low,pivotpos-1);
        qs(arr,pivotpos+1,high);
    }
}

int main()
{
    int arr[]={6,5,4,3,2,1};
    qs(arr,0,5);
    for(int i=0;i<6;i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}