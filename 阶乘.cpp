#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include <windows.h>
using namespace std;

int Recur(int n){
    //递归计算N 
    int result = 1;
    if (n == 1 || n == 0)
        result = 1;
    else{
        //递归的体现 
        result = n * Recur(n - 1);
    }
    return result;
}
int NonR(int n) {
    //非递归计算N 
    int i,result = 1;
    if (n == 1 || n == 0)
        result = 1;
    else {
        //循环的体现 
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


    clock_t startTime3 = clock();//3计时开始

    Sleep(500);

    cout << "Result:" << Recur(N) << endl;//递归
    clock_t endTime3 = clock();//3计时结束

    clock_t startTime4 = clock();//3计时开始
    Sleep(500);
    cout << "Result:" << NonR(N) << endl;//非递归
    clock_t endTime4 = clock();//3计时结束



    cout << "The run time1 is:" << (double)(endTime3 - startTime3) / CLOCKS_PER_SEC << "s" << endl;

    cout << "The run time2 is:" << (double)(endTime4 - startTime4) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}

//本例递归时间复杂度O（n！）,空间复杂度O（n）
//非递归时间复杂度O（n），空间复杂度o（1）
