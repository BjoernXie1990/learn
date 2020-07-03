#pragma once
#include "head.hpp"

using namespace dcl;//չ��Ͱ��ϣ�������ռ�

namespace dcl_map
{
	template<class K,class V,class Hash = _Hash<K> >
	class unordered_map
	{
		//����Ȩֵ�����ݵķ�����
		struct MapKOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename HashTable<K, pair<K, V>, MapKOfT, Hash>::iterator iterator;
		//������
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ans = _ht.insert(make_pair(key, V()));
			return ans.first->second;
		}

		pair<iterator, bool> insert(const pair<K, V>& data)
		{
			return _ht.insert(data);
		}
	private:
		HashTable<K, pair<K, V>, MapKOfT, Hash> _ht;
	};


	
}