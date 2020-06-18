#include <iostream>
using namespace std;
void QuickSort(int s[], int l, int r);
void Print(int a[], int n); //��ӡ����

int main(){
    int a[]= {72,6,57,88,60,42,83,73,48,85,2,24};
    //int a[] = { 10,9,8,7,6,5,4,3,2,1 };
    cout << "Before Sorting:" << endl;
    Print(a, 12);
    cout << "After Sorting:" << endl;
    QuickSort(a, 0, 11);//ע�����һ������
    Print(a, 12);

    return 0;
}

void Print(int a[], int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int QuickSortPartition(int s[], int l, int r) {
    //Swap(s[l], s[(l + r) / 2]); //�����м���Ϊ��׼�����Ƚ��м��������͵�һ������������
    int x = s[l]; //������Ԫ�ؼ�¼��x��
    while (l < r)
    {
        // ���������ҵ�һ��<x����,���迼���±�Խ��
        while (l < r && s[r] >= x)
            r--;
        if (l < r)
            s[l++] = s[r]; //ֱ���滻������Ԫ�أ�����x�д��б��ݣ�

        // ���������ҵ�һ��>x����
        while (l < r && s[l] <= x)
            l++;
        if (l < r)
            //�滻������Ԫ��(��������Ԫ�����б��ݣ�
            //����Ԫ��һ�������ǹ�����û�У�������Ҳ�����Ԫ�ض�>x����ô�㷨����ֹ
            s[r--] = s[l];
    }
    s[l] = x;  //l��λ�÷���x����������඼С��x���Ҳ�y������x
    return l;
}

void QuickSort(int s[], int l, int r)
{
    //�������<�ҽ�������壬����˵�������źã�ֱ�ӷ��ؼ���
    if (l >= r) {
        return;
    }

    // ���֣����ػ�׼��λ��
    int i = QuickSortPartition(s, l, r);

    // �ݹ鴦�����������֣�i��Ϊ�ֽ�㣬���ù�i��
    QuickSort(s, l, i - 1);
    QuickSort(s, i + 1, r);
}
