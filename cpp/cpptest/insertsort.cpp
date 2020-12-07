#include<iostream>
using namespace std;

void insertsort(int arr[],int n){
    for (int i = 1; i < n;i++){
        int j;
        int temp = arr[i];
        for (j = i - 1; arr[j] > temp;j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

int main(){
    int arr[] = {13, 12, 11, 10, 8, 5, 2, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertsort(arr, n);
    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}