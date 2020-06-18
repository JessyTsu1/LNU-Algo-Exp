#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include <windows.h>
using namespace std;

//设计程序，求1+2+3+…+n前n个整数之和，至少用两种不同的算法实现，并分别分析你编写的多种算法的时间复杂度。
//用了三种方法，一是递归，二是循环，三是数学法化简
int count(int n){
	//递归实现
	int f = 0;
	if (n == 1)
		f = 1;
	else
		f = n + count(n - 1);
	return f;
}
int main(){
	int n, i, tt = 0;
	scanf_s("%d", &n);

	clock_t startTime1 = clock();//1计时开始
	for (i = 1; i <= n; i++)
		tt += i;//循环实现
	Sleep(500);

	printf("循环结果：%d\n", tt);
	clock_t endTime1 = clock();//1计时结束

	clock_t startTime2 = clock();//2计时开始

	Sleep(500);
	printf("递归结果：%d\n", count(n));//递归实现
	clock_t endTime2 = clock();//2计时结束


	clock_t startTime3 = clock();//3计时开始

	Sleep(500);
	printf("数学化简：%d\n",(1+n)*n/2);
	clock_t endTime3 = clock();//3计时结束

	// 输出1运行时间; 
	cout << "The run time1 is:" << (double)(endTime1 - startTime1) / CLOCKS_PER_SEC -0.5 << "s" << endl;
	cout << "The run time2 is:" << (double)(endTime2 - startTime2) / CLOCKS_PER_SEC - 0.5 << "s" << endl;
	cout << "The run time3 is:" << (double)(endTime3 - startTime3) / CLOCKS_PER_SEC - 0.5 << "s" << endl;
	return 0;
}
