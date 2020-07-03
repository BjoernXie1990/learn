#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <ctime>
using namespace std;

namespace dcl
{
	//�ڵ�
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};
	// ǰ������
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	//������
	template<class K,class T,class KeyOfT,class Hash>
	struct __HashTableIterator
	{
		typedef __HashTableIterator<K, T, KeyOfT, Hash> Self;
		typedef HashTable<K, T, KeyOfT, Hash> HT;
		typedef HashNode<T> node;
		node* _node;
		HT* _pht;

		__HashTableIterator(node* n,HT* pht)
			:_node(n)
			, _pht(pht)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &(_node->_data);
		}

		Self operator++()
		{
			if (_node->_next != nullptr)
			{
				_node = _node->_next;
				return *this;
			}

			//��ǰȨֵ��Ͱ�Ѿ������ˣ���Ҫ�ҵ���һ��Ͱ
			KeyOfT koft;
			size_t i = _pht->HashFunc(koft(_node->_data)) % _pht->_table.size();
			i++;//����һ��Ͱ��λ��
			for (; i < _pht->_table.size(); i++)
			{
				node* cur = _pht->_table[i];
				if (cur)
				{
					_node = cur;
					return *this;
				}
			}
			_node = nullptr;//����˵�������������һ��Ͱ
			return *this;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
		bool operator==(const Self& s)
		{
			return _node == s._node;
		}
	};

	//�õ���ǰλ�õ�����
	template<class T>
	struct _Hash
	{
		const T& operator()(const T& key)
		{
			return key;
		}
	};
	//�ػ��ַ�����������
	template<>
	struct _Hash < string >
	{
		size_t operator()(const string& key)
		{
			size_t ans = 0;
			for (size_t i = 0; i < key.size(); i++)
			{
				ans *= 131;
				ans += key[i];
			}
			return ans;
		}
	};


	//Ͱ��ϣ
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable
	{
	public:
		typedef HashNode<T> node;
		//���õ�����Ϊ�Լ�����Ԫ
		friend struct __HashTableIterator < K, T, KeyOfT, Hash > ;
		typedef __HashTableIterator< K, T, KeyOfT, Hash > iterator;
	public:
		HashTable()
			:_num(0)
		{
			_table.clear();
			_table.resize(11);//���ó�ʼ����
		}
		~HashTable()
		{
			Clear();
		}

		//������
		iterator begin()
		{
			for (size_t i = 0; i < _table.size(); i++)
				if (_table[i] != nullptr)
					return iterator(_table[i], this);
			//˵������û������
			return end();
		}
		iterator end()
		{
			return iterator(nullptr, this);
		}

		//�õ���ǰλ�õ����ݣ�תΪ��������
		size_t HashFunc(const K& key)
		{
			Hash hash;
			return hash(key);
		}

		//����
		pair<iterator, bool> insert(const T& data)
		{
			KeyOfT koft;

			//Ͱ��ϣ�У������������ = 1���ͽ�������
			if (_table.size() == _num)
			{
				vector<node*> newTable;
				size_t newSize = _table.size() * 2;
				newTable.resize(newSize);

				for (size_t i = 0; i < _table.size(); i++)
				{
					node* cur = _table[i];
					while (cur != nullptr)
					{
						node* next = cur->_next;
						//����Ӧ�ò��뵽�±��е�λ��
						size_t idx = HashFunc(koft(cur->_data)) % newSize;
						//����ͷ��
						cur->_next = newTable[idx];
						newTable[idx] = cur;
						cur = next;
					}
					//����ڵ��Ծ�û��������
					_table[i] = nullptr;
				}
				_table.swap(newTable);
			}

			//��������µ�����
			//�������λ��
			size_t idx = HashFunc(koft(data)) % _table.size();
			//�ҵ�����ĵط�
			node* cur = _table[idx];
			while (cur != nullptr)
			{
				//�������Ѿ��ڱ��У�����Ҫ������
				if (koft(cur->_data) == koft(data))
					return make_pair(iterator(cur, this), false);
				cur = cur->_next;
			}
			//ȷ������û�и����ݣ�����ͷ��
			node* newNode = new node(data);
			newNode->_next = _table[idx];
			_table[idx] = newNode;

			_num++;
			return make_pair(iterator(newNode, this), true);
		}

		//����
		node* find(const K& key)
		{
			KeyOfT koft;
			size_t idx = HashFunc(koft(key)) % _table.size();
			node* cur = _table[idx];

			while (cur != nullptr)
			{
				if (koft(cur->_data) == key)
					return cur;
				cur = cur->_next;
			}
			//����˵��û���ҵ�
			return nullptr;
		}

		//ɾ��
		bool erase(const K& key)
		{
			KeyOfT koft;
			size_t idx = HashFunc(koft(key)) % _table.size();
			node* cur = _table[idx];
			node* pre = nullptr;

			while (cur != nullptr)
			{
				if (koft(cur->_data) == key)
				{
					if (pre == nullptr)//ɾ����һ���ڵ�
						_table[idx] = cur->_next;
					else
						pre->_next = cur->_next;
					delete cur;
					return true;
				}
				pre = cur;
				cur = cur->_next;
			}
			return false;
		}
	private:
		void Clear()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				node* cur = _table[i];
				while (cur != nullptr)
				{
					node* _next = cur->_next;
					delete cur;
					cur = _next;
				}
				_table[i] = nullptr;
			}
		}
	private:
		vector<node*> _table;
		size_t _num;
	};

	template<class T>
	struct KofT
	{
		const T& operator()(const T& data)
		{
			return data;
		}
	};

	
}



namespace dcl_sanlie
{
	//��ϣ����ÿһ��λ�õ�״̬
	enum Status
	{
		EMPTY,//��
		EXITS,//����
		DELETE,//ɾ��
	};

	//���������
	template<class T>
	struct HashData
	{
		T _data;
		Status _status;//��ǰλ�õ�״̬
	};

	template<class K, class T, class KOfT>
	class HashTable
	{
	public:
		HashTable()
			:_num(0)
		{
			//��ʼ����������Ϊ0,
			_table.resize(10);
		}
		bool Insert(const T& d)
		{
			KOfT _koft;
			//�Ƿ���Ҫ����
			if (_num * 10 / _table.size() >= 7)
			{
				//����
				//��һ��д��������һ��vector
				/*
				vector<HashData<T>> newTable;
				newTable.resize(_table.size() * 2);
				for (size_t i = 0; i < _table.size(); i++)
				{
				if (_table[i]._status == EXITS)
				{
				//�������±��е�����
				size_t idx = _koft(_table[i]._data) % newTable.size();
				//�ҵ�����λ��
				while (newTable[idx]._status == EXITS)
				idx = (idx + 1) % newTable.size();
				newTable[idx]._data = _table[i]._data;
				newTable[idx]._status = EXITS;
				}
				}
				swap(newTable, _table);
				*/

				//�ڶ���д�����½�һ��hashtable
				HashTable<K, T, KofT<K>> newHash;
				newHash._table.resize(_table.size() * 2);
				for (size_t i = 0; i < _table.size(); i++)
					if (_table[i]._status == EXITS)
						newHash.Insert(_table[i]._data);
				_table.swap(newHash._table);
			}


			//����ӳ��λ��
			//����̽��
			/*
			size_t idx = _koft(d) % _table.size();
			while (_table[idx]._status == EXITS)
			{
			//����������Ѿ�����
			if (_koft(_table[idx]._data) == _koft(d))
			return false;

			//�����ҵ�ʱ����Ҫ���һ��ѭ������
			idx = (idx + 1) % _table.size();
			}

			_table[idx]._data = d;
			_table[idx]._status = EXITS;
			_num++;
			*/

			//����̽��
			size_t start = _koft(d) % _table.size();
			size_t idx = start;
			int i = 1;
			while (_table[idx]._status == EXITS)
			{
				if (_koft(_table[idx]._data) == _koft(d))
					return false;
				idx = start + i * i;
				i++;
				idx %= _table.size();
			}
			_table[idx]._data = d;
			_table[idx]._status = EXITS;
			_num++;
			return true;
		}

		//����
		HashData<T>* Find(const K& key)
		{
			size_t idx = key % _table.size();

			size_t start = idx;
			size_t i = 1;

			while (_table[idx]._status != EMPTY)
			{
				if (_table[idx]._data == key)
				{
					if (_table[idx]._status == EXITS)
						return &_table[idx];
					else if (_table[idx]._status == DELETE)
						return nullptr;
				}
				idx = (start + i * i) % _table.size();
				i++;
			}

			return nullptr;
		}

		//ɾ��
		bool Erase(const K& key)
		{
			HashData* ret = Find(key);
			if (ret)
			{
				ret->_status = DELETE;
				_num--;
				return true;
			}

			//���ݲ�����
			return false;
		}

	private:
		vector<HashData<T> > _table;
		size_t _num;//���洢���ݵ�����
	};
}