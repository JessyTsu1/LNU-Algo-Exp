#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include <windows.h>
using namespace std;

//��Ƴ�����1+2+3+��+nǰn������֮�ͣ����������ֲ�ͬ���㷨ʵ�֣����ֱ�������д�Ķ����㷨��ʱ�临�Ӷȡ�
//�������ַ�����һ�ǵݹ飬����ѭ����������ѧ������
int count(int n){
	//�ݹ�ʵ��
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

	clock_t startTime1 = clock();//1��ʱ��ʼ
	for (i = 1; i <= n; i++)
		tt += i;//ѭ��ʵ��
	Sleep(500);

	printf("ѭ�������%d\n", tt);
	clock_t endTime1 = clock();//1��ʱ����

	clock_t startTime2 = clock();//2��ʱ��ʼ

	Sleep(500);
	printf("�ݹ�����%d\n", count(n));//�ݹ�ʵ��
	clock_t endTime2 = clock();//2��ʱ����


	clock_t startTime3 = clock();//3��ʱ��ʼ

	Sleep(500);
	printf("��ѧ����%d\n",(1+n)*n/2);
	clock_t endTime3 = clock();//3��ʱ����

	// ���1����ʱ��; 
	cout << "The run time1 is:" << (double)(endTime1 - startTime1) / CLOCKS_PER_SEC -0.5 << "s" << endl;
	cout << "The run time2 is:" << (double)(endTime2 - startTime2) / CLOCKS_PER_SEC - 0.5 << "s" << endl;
	cout << "The run time3 is:" << (double)(endTime3 - startTime3) / CLOCKS_PER_SEC - 0.5 << "s" << endl;
	return 0;
}
