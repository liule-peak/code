#include<iostream>
using namespace std;
//将A上面的n-1个盘中通过C移动到B；
//再将A最后一个盘子移动到C；
//再将B上面的n-1个盘子通过A移动C；



void Hanoi(int n,char A,char B,char C){
    if (n == 1){
        cout << A << "->" << C << endl;
        return;
    }

    Hanoi(n - 1, A, C, B);
    cout << A << "->" << C << endl;
    Hanoi(n - 1, B, A, C);
    return;
}

int main(){
    int n;
    cin >> n;
    Hanoi(n, 'A', 'B', 'C');
    return 0;
}