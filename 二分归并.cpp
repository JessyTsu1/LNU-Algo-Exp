#include <iostream>
using namespace std;
void MergeSort(int* array, int p, int r);
void Print(int a[], int n); //��ӡ����

int main(){
    int a[]= {72,6,57,88,60,42,83,73,48,85,24,110};
   //int a[] = { 10,9,8,7,6,5,4,3,2,1 };
    Print(a, 12);
    MergeSort(a, 0, 11);//ע�����һ������
    Print(a, 12);
    return 0;
}

void Print(int a[], int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

//p...m, m+1...rΪ�������źõĵ������У������Ǻϲ���һ��
void Merge(int* array, int p, int m, int r) {
    int lenA = m - p + 1;
    int lenB = r - m;
    int* A = new int[lenA];
    int* B = new int[lenB];
    memcpy(A, array + p, lenA * sizeof(int));
    memcpy(B, array + m + 1, lenB * sizeof(int)); //ע�����2����λ�ã�����array+p+m+1
    cout << "sorting:" << endl;
    Print(A, lenA);
    Print(B, lenB);
    int i = 0; //ָʾA��Ԫ��
    int j = 0; //ָʾB��Ԫ��
    int k = p; //ָʾarray�д���λ�ã�ע��k����ʼλ��
    while (i < lenA && j < lenB) {
        if (A[i] < B[j]) {
            array[k] = A[i];
            i++;
        }
        else {
            array[k] = B[j];
            j++;
        }
        k++;
    }
    //��û��������飬������array�п�
    if (lenA - i > 0) {
        memcpy(array + k, A + i, (lenA - i) * sizeof(int));
    }
    else {
        memcpy(array + k, B + j, (lenB - j) * sizeof(int));
    }
    delete[] A;  //��������Ҫ��delete[] x,���յ���������delete x
    delete[] B;
}

void MergeSort(int* array, int p, int r) {
    if (r > p) {
        int m = (p + r) / 2;
        MergeSort(array, p, m);
        MergeSort(array, m + 1, r);
        Merge(array, p, m, r);
    }
}

