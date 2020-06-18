#include <iostream>
#include <string>
using namespace std;

string LCS(string X, string Y);

void PrintArray(int** a, int n1, int n2)
{
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

string LCS(string X, string Y) {
    unsigned long m = X.size();
    unsigned long n = Y.size();
    int** C = new int* [m + 1];
    int** state = new int* [m + 1];
    for (int i = 0; i <= m; i++) {
        C[i] = new int[n + 1];
        state[i] = new int[n + 1];
        for (int j = 0; j <= n; j++) {
            C[i][j] = 0;
            state[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {  
                C[i][j] = C[i - 1][j - 1] + 1;
                state[i][j] = 3;
            }
            else {
                int c1 = C[i - 1][j];
                int c2 = C[i][j - 1];
                if (c1 >= c2) {
                    C[i][j] = c1;
                    state[i][j] = 1;
                }
                else {
                    C[i][j] = c2;
                    state[i][j] = 2;
                }
            }
        }
    }
    cout << "C[i][j]:" << endl;
    PrintArray(C, m + 1, n + 1);
    cout << "state[i][j]:" << endl;
    PrintArray(state, m + 1, n + 1);
    string lcs = "";
    int i = m;
    int j = n;
    while (i > 0 && j > 0) {
        if (state[i][j] == 3) {
            //string& insert (size_t pos, size_t n, char c);
            lcs.insert(0, 1, X[i - 1]); //insert比+=效率高
            i--;
            j--;
        }
        else if (state[i][j] == 1) {
            i--;
        }
        else if (state[i][j] == 2) {
            j--;
        }
    }
    return lcs;
}

int main()
{
    string X = "ABCBDAB";
    string Y = "BDCABA";
    string lcs = LCS(X, Y);
    cout << "LCS is: " << lcs << endl;
    return 0;
}
