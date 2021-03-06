// 14.22.cpp: 定义控制台应用程序的入口点。
//模板类中的非模板友元函数
// 并且友元函数使用模板类参数

#include "stdafx.h"
#include<iostream>
#include<ctime>
#include<string>
using namespace std;

template <typename T>
class HasFirend
{
private:
	T item;
	static int ct;
public:
	HasFirend(const T& i) :item(i) { ct++; }
	~HasFirend() { ct--; }
	friend void counts();
	friend void repoters(HasFirend<T> &);                   //函数原型
};

template <typename T>
int HasFirend<T>::ct = 0;

void counts()
{
	cout << "int count: " << HasFirend<int>::ct << "; ";
	cout << "double count" << HasFirend<double>::ct << ": ";
    cout << "string count" << HasFirend<string>::ct << ": " <<endl;
}

void repoters(HasFirend<int> & hf)        // T 为int时的函数定义
{
	cout << "Hasfriend <int>: " << hf.item << endl;
}

void repoters(HasFirend<double> & hf)     // T 为double时的函数定义
{
	cout << "Hasfriend <double>: "<< hf.item << endl;
}

void repoters(HasFirend<string> & hf)     // T 为string时的函数定义
{
	cout << "Hasfriend <string>: " << hf.item << endl;
}

int main()
{
	cout << "No objects declared: ";
	counts();
	HasFirend <int> hfi1(10);
	cout << "After hfi1 declared: ";
	counts();
	HasFirend<int>hfi2(20);
	cout << "After hfi2 declared: ";
	counts();
	HasFirend<double>hfi3(10.5);
	cout << "After hfi3 declared: ";
	counts();
	HasFirend<string>hfi4("asd");
	cout << "After hfi4 declared: ";
	counts();

	repoters(hfi1);
	repoters(hfi2);
	repoters(hfi3);
	repoters(hfi4);

	int secs = 120;                                  //延时120s的程序
	clock_t delay = secs*CLOCKS_PER_SEC;             //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

}

