#pragma once
#include <iostream>
#include <string>
#include <vld.h>
using namespace std;


class People
{
public:
	string _name;//����
	int _age;	//����
};

//ѧ����
class Student :virtual public People
{
protected:
	int _Sid;	//ѧ��
};

//�̳еĽ�ʦ��
class Teacher :virtual public People
{
protected:
	int _Tid;//��ʦ��
};

//�༶��
class Grade :public Student, public Teacher
{
protected:
	int _Gid;
};


class A
{
private:
	int _a[1000];
	class B;
};
// class B : public A
class B : public A
{
public:
	int _b;
};

// class C : public A
class C : public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};




//class A
//{
//public:
//	A(int a = 0)
//		:_protected(a)
//		,_private(a)
//	{}
//	friend class B;
//protected:
//	int _protected;
//private:
//	int _private;
//};
//
//class B
//{
//public:
//	static int _sum;
//protected:
//	int _b;
//};
//
//int B::_sum = 0;
//
//class C:public B
//{
//public:
//	static int _sum;
//protected:
//	int _c;
//};
//
//int C::_sum = 0;
//
//



class Boy : public Student
{
protected:
	int _Sex;
};

class Girl : public Student
{
protected:
	int _Sex;
};