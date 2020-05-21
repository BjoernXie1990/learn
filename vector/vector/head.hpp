#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <assert.h>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template<class T>
class vector
{
public:
	//�嶨�������������
	typedef T* iterator;
	typedef const T* const_iterator;

	//���캯��
	vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _end_of_storage(nullptr)
	{}

	//��������
	~vector()
	{
		delete[] _start;
		_start = _finish = _end_of_storage = nullptr;
	}

	//��������
	vector(const vector<T>& obj)
	{
		_start = new T[obj.size()];
		_finish = _end_of_storage = _start + obj.size();

		memcpy(_start, obj._start, obj.size() * sizeof(T));
	}
	//��ֵ���������
	vector<T>& operator=(vector<T> obj)
	{
		//������Ҫ��thisָ�룬�������swap����������еĽ���������������std�ռ��е�
		this->swap(obj);
		return *this;
	}
	void swap(vector<T>& obj)
	{
		std::swap(_start, obj._start);
		std::swap(_finish, obj._finish);
		std::swap(_end_of_storage, obj._end_of_storage);
	}

	//[] ���������
	T& operator[](size_t pos)
	{
		assert(pos < size());//����Խ�����
		return _start[pos];
		//return *(_start + pos);
	}

	//����������С
	size_t size() const
	{
		return _finish - _start;
	}
	//������������
	size_t capacity() const
	{
		return _end_of_storage - _start;
	}

	//����
	//reserve
	void reserve(size_t n)
	{
		//�����û����������Ҫ���ݣ���һ����ʼֵ2
		if (capacity() == 0 && n == 0)
			n = 2;
		//ֻ�б�ԭ���������������
		if (n > capacity())
		{
			size_t len = size();
			
			T* tmp = new T[n];
			//��ֹ���� _start == nullptr ������
			if (_start)
			{
				memmove(tmp, _start, len * sizeof(T));
				delete[] _start;
			}

			_start = tmp;
			_finish = _start + len;
			_end_of_storage = _start + n;
		}
	}

	//��Ϊ���ﲻȷ�� ģ��T �����ͣ�����ȱʡֵ����ֱ�Ӹ�0����Ϊ�Զ������͸�0�Ļ����ܻ����
	void resize(size_t n, const T& value = T())
	{
		//���������������Ҫ��Ĵ�С����������
		//���ﲻ�ܼ� = ����Ϊ size() ���صĴ�С��һ������ҿ������β�������һ��ֵ�ǲ����ڵ�
		if (n < size())
		{
			_finish = _start + n;
		}
		else  //��������С��Ҫ��Ĵ�С
		{
			//�ж��Ƿ��������
			if (n > capacity())
				reverse(n);

			//����Ҫ����ֵ����ں���
			while (_finish != _start + n)
				*(_finish++) = value;
		}
	}

	//β��
	void push_back(const T& x)
	{
		//�ж��Ƿ���Ҫ����
		if (_finish == _end_of_storage)
			reserve(capacity() * 2);//����2�����ݣ�Ҳ����1.5������

		*(_finish++) = x;
	}

	//βɾ
	void pop_back()
	{
		assert(_finish > _start);//��֤������������
		_finish--;
	}

	//�м����Ԫ��
	void insert(iterator pos, const T& x)
	{
		assert(pos <= _finish);//����λ�ñ���Ϸ�

		if (_finish == _end_of_storage)//�Ƿ���Ҫ����
		{
			size_t offset = pos - _start;//����ƫ����
			reserve(capacity() * 2);
			pos = _start + offset;//�����µĲ���λ��
		}

		//��posλ�ú���������Ų��һλ
		iterator end = _finish - 1;
		while (end >= pos)
		{
			*(end + 1) = *end;
			end--;
		}
		*pos = x;
		_finish++;
	}

	//��������
	iterator erase(iterator pos)
	{
		assert(pos <= _finish);//�������ݵ�λ�ñ���Ϸ�
		iterator it = pos + 1;
		while (it != _finish)
		{
			*(it - 1) = *it;
			it++;
		}
		_finish--;
		return pos;
	}

	//������
	//��������Ŀ�ʼλ��
	iterator begin()
	{
	return _start;
	}
	const_iterator begin() const
	{
		return _start;
	}
	//����ĩβλ�ã�ĩβ��һ��������
	iterator end()
	{
		return _finish;
	}
	const_iterator end() const
	{
		return _finish;
	}

private:
	iterator _start;
	iterator _finish;
	iterator _end_of_storage;
};