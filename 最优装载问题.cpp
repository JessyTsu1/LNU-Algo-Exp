#include<iostream>
// ����sort������ͷ�ļ�
#include<algorithm>
using namespace std;
// C++������ų���
const int N = 1000005;
double w[N];
int main()
{
    double c;
    int n;
    cout << "������������c���Ŷ�����n��" << endl;
    cin >> c >> n;
    cout << "������ÿ���Ŷ����������ÿո�ֿ���" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    //���Ŷ�������������
    sort(w, w + n);
    //tmpΪ��װ�ص����ϵĹŶ�������ansΪ��װ�صĹŶ�����
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
    cout << "��װ��ĹŶ��������ΪAns=";
    cout << ans << endl;
    return 0;
}