#include "stdio.h"
void main(){
	int n;
	scanf_s("%d", &n);
	if (n == 1){
		printf("1=1\n");
		return;
	}
	if (n == 2){
		printf("2=1+1\n");
		return;
	}
	int* a = new int(n);
	int top = 0;
	a[0] = n - 1;
	a[1] = 1;
	top = 2;
	int i;
	do{
		printf("%d=%d", n, a[0]);
		for (i = 1; i < top; i++)
		{
			printf("+%d", a[i]);
		}
		printf("\n");
		int s = 0;
		do {
			s += a[--top];
		} while (top >= 0 && a[top] == 1);
		if (top == -1)
		{
			break;
		}
		int d = a[top] - 1;
		if (d == 1)
		{
			while (s > 0)
			{
				a[top++] = 1;
				s--;
			}
		}
		else
		{
			do {
				a[top++] = d;
				s -= d;
			} while (s >= d);
			if (s != 0)
			{
				a[top++] = s;
			}
		}
	} while (1);
}

int part(int l, int r) {//排序并返回分界点
	int key = a[l];
	while (l < r) {
		while (l < r && a[r] >= key)r--;
		a[l] = a[r];

		while (l < r && a[l] <= key)l++;
		a[r] = a[l];
	}
	a[l] = key;
	return l;
}

void qsort(int l, int r) {
	if (l >= r)return;
	int p = part(l, r);
	qsort(l, p - 1);//对分界点左边快排
	qsort(p + 1, r);//对分界点右边快排
}



#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;

const int RLEN = 1 << 18 | 1;
inline char nc() {
	static char ibuf[RLEN], * ib, * ob;
	(ib == ob) && (ob = (ib = ibuf) + fread(ibuf, 1, RLEN, stdin));
	return (ib == ob) ? -1 : *ib++;
}
inline int rd() {
	char ch = nc(); int i = 0, f = 1;
	while (!isdigit(ch)) { if (ch == '-')f = -1; ch = nc(); }
	while (isdigit(ch)) { i = (i << 1) + (i << 3) + ch - '0'; ch = nc(); }
	return i * f;
}

const int N = 5e4 + 50, B = 350, mod = 1e9 + 7;
inline int add(int x, int y) { return (x + y >= mod) ? (x + y - mod) : (x + y); }
int n, f[N][B];

int main() {
	cin >> n; f[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i && j < B; j++)
			f[i][j] = add(f[i - j][j], f[i - j][j - 1]);
	int ans = 0;
	for (int j = 1; j < B; j++) ans = add(ans, f[n][j]);
	cout << ans << endl;
}


#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;

const int RLEN = 1 << 18 | 1;
inline char nc() {
	static char ibuf[RLEN], * ib, * ob;
	(ib == ob) && (ob = (ib = ibuf) + fread(ibuf, 1, RLEN, stdin));
	return (ib == ob) ? -1 : *ib++;
}
inline int rd() {
	char ch = nc(); int i = 0, f = 1;
	while (!isdigit(ch)) { if (ch == '-')f = -1; ch = nc(); }
	while (isdigit(ch)) { i = (i << 1) + (i << 3) + ch - '0'; ch = nc(); }
	return i * f;
}

const int N = 5e4 + 50, B = 350, mod = 1e9 + 7;
inline int add(int x, int y) { return (x + y >= mod) ? (x + y - mod) : (x + y); }
inline int dec(int x, int y) { return (x - y < 0) ? (x - y + mod) : (x - y); }
inline int mul(int x, int y) { return (long long)x * y % mod; }
int n, f0[N], f1[N], f[N][B];
int main() {
	cin >> n; f0[0] = f1[0] = 1;
	for (int j = 1; j < B && j <= n; j++) for (int i = j; i <= n; i++) f0[i] = add(f0[i], f0[i - j]);
	f[0][0] = 1;
	for (int i = B; i <= n; i++)
		for (int j = 1; j <= B; j++) {
			f[i][j] = add((i >= B) ? f[i - B][j - 1] : 0, f[i - j][j]);
			f1[i] = add(f1[i], f[i][j]);
		}
	int ans = 0;
	for (int i = 0; i <= n; i++) ans = add(ans, mul(f0[i], f1[n - i]));
	cout << ans << endl;
}



#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e5 + 50, G = 3, mod = 998244353;
inline int add(int x, int y) { return (x + y >= mod) ? (x + y - mod) : (x + y); }
inline int dec(int x, int y) { return (x - y < 0) ? (x - y + mod) : (x - y); }
inline int mul(int x, int y) { return (LL)x * y % mod; }
inline int power(int a, int b, int rs = 1) { for (; b; b >>= 1, a = mul(a, a)) if (b & 1) rs = mul(rs, a); return rs; }
int n, k, g[N * 8], f[N * 8], tp[N * 8], w[N * 8], pos[N * 8];
inline void init(int len) { k = len << 1; for (int i = 1; i < k; i++) pos[i] = (i & 1) ? ((pos[i >> 1] >> 1) ^ (k >> 1)) : (pos[i >> 1] >> 1); }
inline void dft(int* a) {
	for (int i = 1; i < k; i++) if (pos[i] > i) swap(a[pos[i]], a[i]);
	for (int bl = 1; bl < k; bl <<= 1) {
		int tl = bl << 1, wn = power(G, (mod - 1) / tl);
		w[0] = 1; for (int i = 1; i < bl; i++) w[i] = mul(w[i - 1], wn);
		for (int bg = 0; bg < k; bg += tl)
			for (int j = 0; j < bl; j++) {
				int& t1 = a[bg + j], & t2 = a[bg + j + bl], t = mul(t2, w[j]);
				t2 = dec(t1, t); t1 = add(t1, t);
			}
	}
}
inline void calc_inverse(int* a, int* b, int len) {
	if (len == 1) { b[0] = power(a[0], mod - 2); return; }
	if (len != 1) calc_inverse(a, b, len >> 1);
	init(len);
	for (int i = 0; i < len; i++) tp[i] = a[i];
	for (int i = len; i < k; i++) tp[i] = 0;
	dft(b); dft(tp);
	for (int i = 0; i < k; i++) b[i] = dec(mul(2, b[i]), mul(tp[i], mul(b[i], b[i])));
	reverse(b + 1, b + k); dft(b);
	const int inv = power(k, mod - 2);
	for (int i = 0; i < len; i++) b[i] = mul(b[i], inv);
	for (int i = len; i < k; i++) b[i] = 0;
}
int main() {
	cin >> n;
	for (int k = 1; (3 * k * k - k) / 2 <= n; ++k) {
		int v = (k & 1) ? mod - 1 : 1;
		g[(3 * k * k - k) / 2] += v;
		g[(3 * k * k + k) / 2] += v;
	} g[0] = 1;
	for (k = 1; k <= n; k <<= 1);
	calc_inverse(g, f, k);
	cout << f[n] << endl;
}