#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include <windows.h>
using namespace std;

int Recur(int n){
    //�ݹ����N 
    int result = 1;
    if (n == 1 || n == 0)
        result = 1;
    else{
        //�ݹ������ 
        result = n * Recur(n - 1);
    }
    return result;
}
int NonR(int n) {
    //�ǵݹ����N 
    int i,result = 1;
    if (n == 1 || n == 0)
        result = 1;
    else {
        //ѭ�������� 
        for(i = 1; i <= n;i++) {
            result = i * result;
        }
    }
    return result;
}

int main(){
    int N;
    cout << "Input:";
    cin >> N;


    clock_t startTime3 = clock();//3��ʱ��ʼ

    Sleep(500);

    cout << "Result:" << Recur(N) << endl;//�ݹ�
    clock_t endTime3 = clock();//3��ʱ����

    clock_t startTime4 = clock();//3��ʱ��ʼ
    Sleep(500);
    cout << "Result:" << NonR(N) << endl;//�ǵݹ�
    clock_t endTime4 = clock();//3��ʱ����



    cout << "The run time1 is:" << (double)(endTime3 - startTime3) / CLOCKS_PER_SEC << "s" << endl;

    cout << "The run time2 is:" << (double)(endTime4 - startTime4) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}

//�����ݹ�ʱ�临�Ӷ�O��n����,�ռ临�Ӷ�O��n��
//�ǵݹ�ʱ�临�Ӷ�O��n�����ռ临�Ӷ�o��1��
