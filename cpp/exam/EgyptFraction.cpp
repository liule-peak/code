#include<iostream>
using namespace std;

void EgyptFraction(int A, int B)
{
    int E, R;
    cout << A << "/" << B << "=";
    do
    {
        E = B / A + 1;
        cout << "1/" << E << "+";
        A = A * E - B;
        B = B * E;
        R = CommFactor(B, A);
        if (R > 1)
        {
            A = A / R;
            B = B / R;
        }
    } while (A > 1);
    cout << "1/" << B << endl;
    return;
}