// 14.21.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"14.13.h"
#include<ctime>

template <template <typename T> class Thing>
class Crab
{
private:
	Thing <int> s1;
	Thing<double> s2;
public:
	Crab() {};
	bool push(int a, double x) { return s1.push(a) && s2.push(x); }
	bool pop(int& a, double& x) { return s1.pop(a) && s2.pop(x); }
};

int main()
{
	using namespace std;

	Crab<Stack> nebula;
	int ni;
	double nb;
	cout << "Enter int double pairs ,such as 4 3.5 (0 0 to end):" << endl;
	while (cin >> ni >> nb && ni > 0 && nb > 0)
	{
		if (!nebula.push(ni, nb))
			break;
	}
	while (nebula.pop(ni, nb))
		cout << ni << " , " << nb << endl;
	cout << "Done." << endl;


	int secs = 120;                                   //延时120s的程序
	clock_t delay = secs*CLOCKS_PER_SEC;             //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

	return 0;
}
