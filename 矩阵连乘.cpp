#include <iostream>
using namespace std;

void PrintArray(int** a, int n1, int n2){
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            cout << a[i][j] << " \t";
        }
        cout << endl;
    }
}

int MatrixChain(int P[], int n, int** s) {
    int** m = new int* [n];
    for (int i = 0; i < n; i++) {
        m[i] = new int[n];
        for (int j = 0; j < n; j++) {
            m[i][j] = 0;
        }
    }

    for (int r = 1; r < n; r++) { //������
        for (int i = 0; i < n - r; i++) { //��ÿ��m[i][i+r]������i��i+r֮��ÿ��k�Ļ��ֽ��
            int j = i + r;  // jȡ���Ҿ����±�
            m[i][j] = m[i + 1][j] + P[i] * P[i + 1] * P[j + 1]; //��ʼ����ȡk=i�����
            s[i][j] = i;
            for (int k = i + 1; k < j; k++) { //(Ai...Ak)(Ak+1...Aj)
                int temp = m[i][k] + m[k + 1][j] + P[i] * P[k + 1] * P[j + 1];
                if (temp < m[i][j]) {
                    m[i][j] = temp;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << "m[i][j]:" << endl;
    PrintArray(m, n, n);
    cout << "s[i][j]:" << endl;
    PrintArray(s, n, n);

    return m[0][n - 1];
}



void TraceSolution(int i, int j, int** state) {
    if (j - i < 2) {
        return;
    }
    cout << state[i][j] << endl;
    TraceSolution(i, state[i][j], state);
    TraceSolution(state[i][j] + 1, j, state);
}


int main() {
    int n = 5;
    int P[] = { 30, 35, 15, 5, 10, 20 };
    int** state = new int* [n];
    for (int i = 0; i < n; i++) {
        state[i] = new int[n];
    }
    int t = MatrixChain(P, n, state);
    cout << "Min multiply times: " << t << endl;
    cout << "Solution is: " << endl;
    TraceSolution(0, n - 1, state);
    return 0;
}


void PrintArray(int** a, int n1, int n2);
int MatrixChain(int P[], int n, int** state);
void TraceSolution(int i, int j, int** state);