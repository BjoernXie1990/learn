#pragma once
#include <vector>
#include <iostream>
#include <functional>//greater�㷨ͷ�ļ�

using std::vector;
using std::cout;
using std::endl;

//�����
template<class T>
struct less
{
	bool operator()(const T& left, const T& right)
	{
		return left < right;
	}
};

//��С��
template<class T>
struct greater
{
	bool operator()(const T& left, const T& right)
	{
		return left > right;
	}
};

//���ȼ�������Ĭ���ǽ�����ѣ�С�ںŵ�����
template<class T, class Container = vector<T>, class Compare = less<T>>
class priority_queue
{
public:
	priority_queue()
		:arr()
	{}


	//���
	void push(T x)
	{
		arr.push_back(x);

		//���ϵ���,ѡ��һ����Ч��λ��
		AdjestUp(arr.size()-1);
	}

	//���ӣ�ɾ����ͷԪ��
	void pop()
	{
		//������Ҫ��Ԫ��
		if (empty())
			return;

		std::swap(arr.front(), arr.back());
		arr.pop_back();
		//���µ���
		AdjestDown(0);
	}

	//�������ȼ�������Ԫ�صĴ�С
	size_t size() const
	{
		return arr.size();
	}

	//�ж����ȼ������Ƿ�Ϊ��
	bool empty() const
	{
		return arr.empty();
	}
	
	//�Ѷ�Ԫ�ز������޸ģ����ܻ��ƻ��ѵĽṹ
	const T& top()const
	{
		return arr.front();
	}
	void show()
	{
		for (size_t i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << ',';
		}
		cout << endl;
	}
private:
	//���ϵ�������ԭ�жѵĻ����ϵ���
	void AdjestUp(size_t child)
	{
		size_t parent = (child - 1) / 2;

		while (child > 0)
		{
			if (com(arr[parent], arr[child]))
			{
				std::swap(arr[child], arr[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}

	//���µ���
	void AdjestDown(size_t parent)
	{
		size_t child = parent * 2 + 1;
		size_t len = arr.size();

		while (child < len)
		{
			//�����Һ���������
			if (child + 1 < len && com(arr[child] , arr[child + 1]))
				child++;

			//�жϺ��Ӻ͸���
			if (com(arr[parent], arr[child]))
			{
				std::swap(arr[child], arr[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				break;
		}
	}

private:
	Container arr;	//�洢ģʽ
	Compare com;	//�Ƚϵķú���
};