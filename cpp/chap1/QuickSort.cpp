#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot = arr[low];
    while(low<high){
        while(low<high && arr[high]>=pivot){
        --high;
        }
        arr[low] = arr[high];
        while(low<high && arr[low]<=pivot){
        ++low;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

void quicksort(int arr[],int low,int high){
    
    if(low<high){
        int pivotpos = partition(arr, low, high);
        quicksort(arr, low, pivotpos - 1);
        quicksort(arr, pivotpos + 1, high);
    }
}

int main(){
    int list[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    quicksort(list, 0, 7);
    for (int i = 0; i < 8; i++){
        cout << list[i] << endl;
    }
    return 0;
}