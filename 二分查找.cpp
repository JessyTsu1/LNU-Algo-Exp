#include <iostream>
using namespace std;
int BinarySearch(int* T, int x, int n);
void Print(int a[], int n); //打印数组

int main(){
    int T[] = { 2,6,7,8,10,12,13,23,48,55,62,74 };
    int x;
    Print(T, 12);
    while (1) {
        cout << "input interger to be searched:" << endl;
        cin >> x;
        cout << "position: " << BinarySearch(T, x, 12) << endl<<endl;
    }
    return 0;
}

void Print(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int BinarySearch(int* T, int x, int n) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (T[mid] == x) {
            return (mid + 1);
        }
        else if (T[mid] < x) {
            left = mid + 1;    //注意left可取mid+1，因为mid已经排除
        }
        else {
            right = mid - 1;   //同理right应取mid-1
        }
    }
    return 0;
}
