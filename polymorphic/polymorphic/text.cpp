#define _CRT_SECURE_NO_WARNINGS 1

#include "head.hpp"

void Buy(People* Pobj)
{
	Pobj->BuyTicket();
}

void text1()
{
	People Pobj;
	Student Sobj;

	//����
	//Buy(&Pobj);

	//ѧ��
	//Buy(&Sobj);
}


typedef void(*VIR_Ptr)();
void Show(VIR_Ptr* p)
{
	for (int i = 0; p[i] != 0; i++)
	{
		cout << p[i] << " --> ";
		VIR_Ptr Fun = p[i];
		Fun();
	}
	cout << endl;
}

//����ַ��ӡ
void text2()
{
	/*People Pobj;


	Student Sobj;
	cout << sizeof(Pobj) << endl;
	Show((VIR_Ptr*)(*((int*)&Sobj)));

	cout <<"Show �����ĵ�ַ �� "<< &Show << endl;*/

	Grade Gobj;
	cout << "Gobj.Student ����� " << endl;
	Show((VIR_Ptr*)(*((int*)&Gobj)));

	cout << "Gobj.Teacher ����� " << endl;
	//��ָ���ƶ���Teacher����λ��
	char* ptr = (char*)&Gobj + sizeof(Student);
	Show((VIR_Ptr*)(*((int*)(ptr))));
}

void text3()
{
	//A Aobj;
	/*B* Bobj = new B;
	A* Aobjb = new B;

	cout << "Aobjb : ";
	delete Aobjb;
	cout << endl <<endl<< "Bobj : ";
	delete Bobj;
	cout << endl;*/

	A Aobj;
	B Bobj;
	Bobj.f();
}

void text5(People Aobj)
{
	cout << "void text5(People Aobj) ����� " << endl;
	Show((VIR_Ptr*)(*((int*)&Aobj)));
}

int main()
{
	Student S;
	

	text5(S);

	cout << "Student S ����� " << endl;
	Show((VIR_Ptr*)(*((int*)&S)));
	return 0;
}

//int main()
//{
//	//text1();
//	text2();
//	//text3();
//	return 0;
//}
