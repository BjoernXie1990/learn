#pragma once

#include <iostream>
#include <vector>

template<class T>
class unionFindSet
{
public:
	unionFindSet(const int size)
	{
		_ufs = vector<T> (size,-1);
	}

	//�ݹ����
	int Find_recu(const int pos)
	{
		if (_ufs[pos] >= 0)
			_ufs[pos] = Find(_ufs[pos]);
		return _ufs[pos];
	}

	//��������
	int Find_iter(const int pos)
	{
		int res = _ufs[pos];
		while (res >= 0)
			res = _ufs[res];
		return res;
	}

	/*
	 **		le_root ri_root			�ֱ�Ϊ�����ڵ�ĸ��ڵ��λ��
	 **			le_root == ri_root	˵�������ڵ���ͬһ�����У�����Ҫ���кϲ�
	 **
	 **			le_root != ri_root	˵������ͬһ�����У���Ҫ���кϲ�
	 **					le λ����Ҫ + riλ������ڵ����;  �ٸ��� ri λ�õĸ��ڵ��±� Ϊ le
	*/
	bool Union(const int le, const int ri)
	{
		int le_root = Find_iter(le);
		int ri_root = Find_iter(ri);

		if (le_root == ri_root)
			return false;

		_ufs[le] += _ufs[ri];
		_ufs[ri] = le;
		return true;
	}
private:
	vector<T> _ufs;
};