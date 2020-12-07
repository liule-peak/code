#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    while (low < high)
    {
        while (low < high && pivot <= arr[high])
        {
            --high;
        }
        arr[low] = arr[high];
        while (low < high && pivot >= arr[low])
        {
            ++low;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

void QS(int arr[], int low, int high)
{
    if (low > high)
    {
        return;
    }
    else
    {
        int pivotpos = partition(arr, low, high);
        QS(arr, low, pivotpos - 1);
        QS(arr, pivotpos + 1, high);
    }
}

int main()
{
    int arr1[] = {8, 3, 2, 6, 7, 1, 5, 4};
    QS(arr1, 0, 7);
    for (int i = 0; i < 8; i++)
    {
        cout << arr1[i] << " ";
    }
    return 0;
}