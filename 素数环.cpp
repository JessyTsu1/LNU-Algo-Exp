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
    if (cur == n && isp[A[0] + A[n - 1]]) {//还要测试环的头尾之和是否为素数 
        for (int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    else {
        for (int i = 2; i <= n; i++) {
            if (!vis[i] && isp[i + A[cur - 1]]) {
                A[cur] = i;
                vis[i] = 1;//当前i的值已经放在了cur的位置，当其它层次的递归遍历到值i时，避免重复 
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