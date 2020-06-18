#include <iostream>
using namespace std;
void Print(int a[], int n); //��ӡ����
int SelectK(int* S, int l, int r, int k);//�ҵ�kС��

int main(){
    int n = 27;
    int S[] = { 1,3,5,7,9,2,4,6,8,10,11,32,12,24,25,34,46,54,67,76,56,66,88,77,99,98,78 };
    Print(S, 27);
    int k;
    while (1) {
        cout << "input k:";
        cin >> k;
        cout << "the " << k << "th min number is: " << SelectK(S, 0, n - 1, k - 1) << endl << endl;
    }
    return 0;
}
void Print(int a[], int n){
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int Partition(int* S, int l, int r) {
    int i = l;
    int j = r;
    int x = S[l];
    while (i < j) {
        while (i < j && S[j] >= x) {
            j--;
        }
        if (i < j) {
            S[i++] = S[j];
        }
        while (i < j && S[i] <= x) {
            i++;
        }
        if (i < j) {
            S[j--] = S[i];
        }
    }
    S[i] = x;
    return i;
}
//2.4.2 �ҵ�kС��,�ȼ����ҵ�һ��λ��Ϊk��Ԫ�أ�ǰ��Ķ�����С������Ķ�������
//���������ڿ�������Ļ��ַ��������������ÿ��ֻ��������һ�ߣ�ͨ�����㣨���㷨���ۡ�p109����ƽ�����Ӷ�ΪO(n)
int SelectK(int* S, int l, int r, int k) {
    int pivot = Partition(S, l, r);
    if (pivot == k) { //�ҵ���λ��k��ǰ��Ķ�����С������Ķ�������
        return S[pivot];
    }
    else if (pivot > k) { //pivot����Ķ������󣬿��Ժ�����
        return SelectK(S, l, pivot - 1, k); //����ǰ�벿��
    }
    else { //pivotǰ��Ķ�����С��Ҳ���Ժ�����
        return SelectK(S, pivot + 1, r, k); //���ֺ�벿��
    }
}

//����λ�����������ĸ�����ż�������򷵻����������ĵ�N/2����
int Median(int* S, int l, int r) {
    return SelectK(S, l, r, (r - l) / 2);
}

