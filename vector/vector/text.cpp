#define _CRT_SECURE_NO_WARNINGS 1

#include "head.hpp"
#include <vld.h>

void Show(vector<int>& arr)
{
	for (auto& eoch : arr)
	{
		cout << eoch << ' ';
	}
	cout << endl;
}

void text()
{
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);

	Show(arr);

	//���Կ�������
	vector<int> copy(arr);
	Show(copy);

	//���Ը�ֵ����
	copy = arr;
	Show(copy);

	//����Ԫ��
	cout << "����Ԫ�ز���" << endl;
	arr.insert(arr.begin(), 0);
	arr.insert(arr.begin(), -1);
	arr.insert(arr.begin(), -2);
	arr.insert(arr.begin(), -3);
	arr.insert(arr.begin(), -4);
	Show(arr);
}

int main()
{
	text();

	return 0;
}