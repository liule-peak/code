#include <iostream>
using namespace std;

void hanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        cout << A << "->" << C <<endl;
    }
    else
    {
        hanoi(n - 1, A, C, B);
        cout << A << "->" << C << endl;
        hanoi(n - 1, B, A, C);
        return;
    }
}

int main()
{
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}