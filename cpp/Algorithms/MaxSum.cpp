#include <iostream>
using namespace std;

int MaxSum(int a[], int left, int right)
{
    int sum = 0, midSum = 0, leftSum = 0, rightSum = 0;
    int center, s1, s2, lefts, rights;

    if (left == right)
    {
        sum = a[left];
    }
    else
    {
        center = (left + right) / 2;
        leftSum = MaxSum(a, left, center);
        rightSum = MaxSum(a, center + 1, right);

        s1 = 0, lefts = 0;
        for (int i = center; i >= left; i--)
        {
            lefts += a[i];
            if (lefts > s1)
            {
                s1 = lefts;
            }
        }
        s2 = 0, rights = 0;
        for (int j = center + 1; j <= right; j++)
        {
            rights += a[j];
            if (rights > s2)
            {
                s2 = rights;
            }
        }
        midSum = s1 + s2;

        if (midSum < leftSum)
        {
            sum = leftSum;
        }
        else
        {
            sum = midSum;
        }
        if (sum < rightSum)
        {
            sum = rightSum;
        }
    }
    return sum;
}

int main()
{
    int a[] = {-20, 11, -4, 13, -5, -2};
    cout << MaxSum(a, 0, 5);
}