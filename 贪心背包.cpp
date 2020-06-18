#include<iostream>
#include<iomanip>
using namespace std;

int maxIndex(int n, float max, float a[5]){
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            index = i;
        }
    }
    return index;
}

int main(){
    int n = 5;   //物品数
    float c = 10; //背包容量
    float res = 0;  //最大价值


    float v[5] = { 6,3,5,4,6 };   //物品价值
    float w[5] = { 2,2,6,5,4 };   //物品重量
    float a[5];   //物品价值比值
    float& max = a[0];  //比值最大
    int index = 0;  //比值最大值的下标
    float visit[5] = { 0 }; //该物品取多少

    //求出物品价值的比值
    for (int i = 0; i < 5; i++)
        a[i] = v[i] / w[i];
    index = maxIndex(n, max, a);
    //c = 0
    while (c > 0)
    {
        if (w[index] <= c)
        {	//如果单价最高者放得下，全放进去
            visit[index] = 1;
            res += v[index];
            c -= w[index];
            a[index] = 0;   //删除该物品
            index = maxIndex(n, max, a);//继续找比值最大
        }
        else
        {   //如果放不下，则将物品进行切分
            res += c * a[index];  //剩余的装满
            visit[index] = c / w[index];
            c = 0;
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "物品取得量：" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "第" << i + 1 << "个物品：";
        cout << visit[i] << "   " << visit[i] * v[i] << endl;
    }
    cout << endl << "最大价值是：" << res << endl;
    return 0;
}