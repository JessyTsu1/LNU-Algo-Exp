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
    int n = 5;   //��Ʒ��
    float c = 10; //��������
    float res = 0;  //����ֵ


    float v[5] = { 6,3,5,4,6 };   //��Ʒ��ֵ
    float w[5] = { 2,2,6,5,4 };   //��Ʒ����
    float a[5];   //��Ʒ��ֵ��ֵ
    float& max = a[0];  //��ֵ���
    int index = 0;  //��ֵ���ֵ���±�
    float visit[5] = { 0 }; //����Ʒȡ����

    //�����Ʒ��ֵ�ı�ֵ
    for (int i = 0; i < 5; i++)
        a[i] = v[i] / w[i];
    index = maxIndex(n, max, a);
    //c = 0
    while (c > 0)
    {
        if (w[index] <= c)
        {	//�����������߷ŵ��£�ȫ�Ž�ȥ
            visit[index] = 1;
            res += v[index];
            c -= w[index];
            a[index] = 0;   //ɾ������Ʒ
            index = maxIndex(n, max, a);//�����ұ�ֵ���
        }
        else
        {   //����Ų��£�����Ʒ�����з�
            res += c * a[index];  //ʣ���װ��
            visit[index] = c / w[index];
            c = 0;
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "��Ʒȡ������" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "��" << i + 1 << "����Ʒ��";
        cout << visit[i] << "   " << visit[i] * v[i] << endl;
    }
    cout << endl << "����ֵ�ǣ�" << res << endl;
    return 0;
}