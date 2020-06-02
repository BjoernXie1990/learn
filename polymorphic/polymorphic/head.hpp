#pragma once

#include <iostream>
#include <vld.h>

using namespace std;

class A
{
public:
	void f()
	{
		cout << "f()" << endl;
	}
};

class B : public A 
{
public:
	virtual void f()
	{
		cout << "f()" << endl;
	};
};

class People
{
public:
	People()
	{
		cout << "People ���캯��" << endl;
	}
	virtual void BuyTicket()
	{
		cout << "���ˣ���ȫ��Ʊ" << endl;
	}

	virtual void Fun1()
	{
		cout << "Fun1()" << endl;
	}

	virtual void Fun2()
	{
		cout << "Fun2()" << endl;
	}

	virtual void Fun3()
	{
		cout << "Fun3()" << endl;
	}
protected:
	int _P;
};

class Student:public People
{
public:
	virtual void BuyTicket()
	{
		cout << "ѧ��������Ʊ" << endl;
	}
	virtual void StudentFun4()
	{
		cout << "StudentFun4()" << endl;
	}
protected:
	int _S;
};

class Teacher 
{
public:
	virtual void BuyTicket()
	{
		cout << " ��ʦ, ����" << endl;
	}

	virtual void TeacherFun4()
	{
		cout << "TeacherFun4()" << endl;
	}
};

class Grade : public Student, public Teacher
{
public:
	virtual void BuyTicket()
	{
		cout << "�����ۿ�" << endl;
	}

	virtual void GradeFun4()
	{
		cout << "GradeFun4()" << endl;
	}
};

class computer
{
public:
	virtual void Brand() = 0;
};

class DELL :public computer
{
public:
	virtual void Brand()
	{
		cout << "Dell ����" << endl;
	}
};

class Mac :public computer
{
public:
	virtual void Brand()
	{
		cout << "Mac" << endl;
	}
};