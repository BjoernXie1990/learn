#define _CRT_SECURE_NO_WARNINGS 1

#include "list.hpp"
#include <vld.h>

void show(list<int>& head)
{
	for (auto& eoch : head)
		cout << eoch << ' ';
	cout << endl;
}

void text1()
{
	list<int> head;
	for (int i = 0; i < 5; i++)
		head.push_back(i);
	show(head);
	//head.clear();
	//show(head);

	/*head.pop_front();
	show(head);

	head.pop_back();
	show(head);*/

	list<int>::iterator it = head.begin();
	while (it != head.end())
	{
		head.insert(it, -1);
		it++;
	}
		
	show(head);

	/*head.push_front(-5);
	show(head);*/
}

void text2()
{
	list<int> head;
	for (int i = 0; i < 10; i++)
		head.push_back(i);

	//删除所有偶数
	list<int>::iterator it = head.begin();
	while (it != head.end())
	{
		int num = *it;
		if (num % 2 == 0)
			head.erase(it++);
		it++;
	}
	//打印列表
	show(head);
}

int main()
{
	//text1();
	text2();
	return 0;
}