package javacode.chap1;

import java.util.Random;

public class QuickSort {
    
    public static int partition(final int[] arr, int low, int high) {
        final int pivot = arr[low];
        while (low < high) {
            while (low < high && arr[high] >= pivot) {
                --high;
            }
            arr[low] = arr[high];
            while (low < high && arr[low] <= pivot) {
                ++low;
            }
            arr[high] = arr[low];
        }
        arr[low] = pivot;
        return low;
    }

    public static void quicksort(final int[] arr, final int low, final int high) {

        if (low < high) {
            final int pivotpos = partition(arr, low, high);
            quicksort(arr, low, pivotpos - 1);
            quicksort(arr, pivotpos + 1, high);
        }
    }

    public static void main(final String[] args) {
        final Random random = new Random();

        final int[] A = new int[10];
        for (int i = 0; i < 10; i++) {
            A[i] = random.nextInt(10);
        }
        for (int i = 0; i < A.length; i++) {
            System.out.print(A[i]+" ");
        }
        System.out.println();
        quicksort(A, 0, A.length-1);
        for (int i = 0; i < A.length; i++) {
            System.out.print(A[i]+" ");
        }
    }
}