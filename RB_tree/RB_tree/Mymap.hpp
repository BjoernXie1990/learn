#pragma once

#include "head.hpp"
#include <string>

namespace dcl
{
	template<class K,class V>
	class map
	{
		//�Ƚϵĺ���
		struct MapKOfV
		{
			const K& operator()(const pair<K, V>& data)
			{
				return data.first;
			}
		};
		typedef typename RBTree<K, pair<K, V>, MapKOfV> RB_type;
		typedef typename RB_type::iterator iterator;
	public:
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}
		
		V& operator[](const K& k)
		{
			pair<iterator, bool> ans = _t.Insert(make_pair(k, V()));
			return ans.first->second;
		}
	private:
		RB_type _t;//�����
	};

	void text2()
	{
		string strs[] = { "����", "ӣ��", "����", "ƻ��", "����", "����", "����", "ƻ��" };
		map<string, int> countMap;
		for (auto& str : strs)
		{
			// 1��������ݲ���map�У���operator[]�����pair<str, 0>, ����ӳ�����(����)�����ý�����++��
			// 2�����������map�У���operator[]�������ݶ�Ӧ��ӳ�����(����)�����ã�����++��
			countMap[str]++;
		}

		for (auto kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}
}