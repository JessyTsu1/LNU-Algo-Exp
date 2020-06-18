#include<iostream>
#include<algorithm>

using namespace std;
int A[100], isp[100], vis[100], n;
int is_prime(int x) {
    for (int i = 2; i < x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
void dfs(int cur) {
    if (cur == n && isp[A[0] + A[n - 1]]) {//��Ҫ���Ի���ͷβ֮���Ƿ�Ϊ���� 
        for (int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    else {
        for (int i = 2; i <= n; i++) {
            if (!vis[i] && isp[i + A[cur - 1]]) {
                A[cur] = i;
                vis[i] = 1;//��ǰi��ֵ�Ѿ�������cur��λ�ã���������εĵݹ������ֵiʱ�������ظ� 
                dfs(cur + 1);
                vis[i] = 0;
                A[cur] = 0;
            }
        }
    }
}
int main() {
    cin >> n;
    for (int i = 2; i <= n * 2; i++) {
        isp[i] = is_prime(i);
    }
    A[0] = 1;
    dfs(1);
}