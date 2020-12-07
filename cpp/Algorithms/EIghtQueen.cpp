//N皇后问题
#include<cmath>
#include<iostream>
using namespace std;
int N;
int queenPos[100];

void queen(int k){    //0~k-1行已经摆好
    int i;
    if (k == N)           //如果 上一轮的 k+1 == N时，说明 0~N-1 位置已经摆好，可以输出结果了。
    {
        for (i = 0; i < N;i++){
            cout << queenPos[i] + 1 << " ";
        }
        cout << endl;
        return;
    }

    for (i = 0; i < N; i++)      //从第0列开始，检测到N-1列。
    {
        int j;
        for (j = 0; j < k;j++){    //用于检测第k行的第i列是否  与 0~k-1行 已摆好的皇后冲突。
            if (queenPos[j] == i || abs(queenPos[j] - i) == abs(k - j))
            {
                break;          //冲突则跳出，检测下一个位置，第（i+1）列。
            }
        }
        if (j == k){            //如果0~k-1列都没发生冲突，则将此时第k行皇后的位置i，写到数组中。
            queenPos[k] = i;
            queen(k + 1);        //递归 安排k+1行。
        }
    }
}

int main(){
    cin >> N;
    queen(0);
    return 0;
}
