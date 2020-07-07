#pragma  once

#include <vector>

using namespace std;


template<class T>
class HashBit
{
public:
	HashBit(size_t N)
	{
		_table.resize(N / 32 + 1, 0);// +1 ��ֹ���� 33 / 32 = 1������������
		_num = 0;
	}
	//num ����λ�� ��1
	void set(size_t num)
	{
		size_t idx = num / 32;
		size_t pos = num % 32;

		_table[idx] |= (1 << pos);
	}

	//num ����λ�� ��0
	void reset(size_t num)
	{
		size_t idx = num / 32;
		size_t pos = num % 32;

		//_table[idx] = ((_table[idx] | (1 << pos)) ^ (1 << pos));

		_table[idx] &= ~(1 << pos);
	}

	//num ���Ƿ����������
	bool test(size_t num)
	{
		size_t idx = num / 32;
		size_t pos = num % 32;

		return _table[idx] & (1 << pos);
	}
private:
	vector<int> _table;
	size_t _num = 0;
};