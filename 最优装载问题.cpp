#include<iostream>
// 调用sort函数的头文件
#include<algorithm>
using namespace std;
// C++定义符号常量
const int N = 1000005;
double w[N];
int main()
{
    double c;
    int n;
    cout << "请输入载重量c及古董个数n：" << endl;
    cin >> c >> n;
    cout << "请输入每个古董的重量，用空格分开：" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    //按古董重量升序排序
    sort(w, w + n);
    //tmp为已装载到船上的古董重量，ans为已装载的古董个数
    double tmp = 0.0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        tmp += w[i];
        if (tmp <= c)
            ans++;
        else
            break;
    }
    cout << "能装入的古董最大数量为Ans=";
    cout << ans << endl;
    return 0;
}