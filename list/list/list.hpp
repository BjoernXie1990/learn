#pragma  once

#include <iostream>
#include <assert.h>
using std::cin;
using std::cout;
using std::endl;

//���������ÿһ�������Ϣ�Ľṹ��
template<class T>
struct __list_node
{
	T _val;
	__list_node<T>* _pre;
	__list_node<T>* _next;

	__list_node(const T val = T())
	{
		_val = val;
		_pre = _next = nullptr;
	}
};

//���������  Ref����������  Ptr��ָ������ T����ͨ����
template<class T, class Ref, class Ptr>
struct __list_iterator
{
	/*typedef __list_iterator<T, T&, T*>  iterator;
	typedef __list_iterator<T, const T&, const T*> const_iterator;*/
	typedef __list_iterator< T, Ref, Ptr > Self;
	typedef __list_node<T> node;
	node* _node;

	__list_iterator(node* node_)
		:_node(node_)
	{}

	//* ���������������
	Ref operator*()
	{
		return (*_node)._val;
	}

	//-> 
	Ptr operator->()
	{
		//return &_node->_val;
		return &(operator*());
	}

	//++i 
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	//i++ 
	Self operator++(T)
	{
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	//--i
	Self& operator--()
	{
		_node = _node->_pre;
		return *this;
	}

	//i--
	Self operator--(T)
	{
		 Self tmp = *this;
		_node = _node->_pre;
		return tmp;
	}

	//!=
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	//==
	bool operator==(const Self& it)
	{
		return _node == it._node;
	}
	
};

template <class T>
class list
{
public:
	//�Խṹ����з�װ
	typedef __list_node<T> node;
	typedef __list_iterator<T, T&, T*>  iterator;
	typedef __list_iterator<T, const T&, const T*> const_iterator;

	list()
	{
		_head = new node;
		_head->_next = _head->_pre = _head;
	}
	~list()
	{
		clear();
		delete _head;
		_head = nullptr;
	}
	list(const list<T>& it)
	{
		_head = new node;

		_head->_pre = _head->_next = _head;
		for (auto& eoch : it)
			push_back(eoch);
	}

	list<T>& operator=(const list<T>& it)
	{
		if (*this != it)
		{
			clear();
			for (auto eoch : it)
				push_back(eoch);
		}
	}

	//������������ص� ->
	iterator begin()
	{
		return iterator(_head->_next);
	}

	//������������� *
	iterator end()
	{
		return iterator(_head);
	}

	const_iterator begin() const
	{
		return const_iterator(_head->_next);
	}
	const_iterator end() const
	{
		return const_iterator(_head);
	}

	//��ͷ˫��ѭ�������β��
	void push_back(T x)
	{
		/*node* cur = new node(x);

		_head->_pre->_next = cur;
		cur->_pre = _head->_pre;

		_head->_pre = cur;
		cur->_next = _head;*/

		insert(_head,x);
	}
	//βɾ
	void pop_back()
	{
		/*node* del = _head->_pre;

		if (del == _head)
			return;

		del->_pre->_next = _head;
		_head->_pre = del->_pre;

		delete del;*/

		erase(_head->_pre);
	}

	//ͷ��
	void push_front(T x)
	{
		/*node* cur = new node(x);

		_head->_next->_pre = cur;
		cur->_next = _head->_next;

		_head->_next = cur;
		cur->_pre = _head;*/

		insert(_head->_next, x);
	}

	//ͷɾ
	void pop_front()
	{
		//node* del = _head->_next;
		////û��Ԫ�ز���ɾ��
		//if (del == _head)
		//	return;
		//del->_next->_pre = _head;
		//_head->_next = del->_next;

		//delete del;

		erase(_head->_next);
	}

	void insert(iterator pos,const T& x)
	{
		node* cur = new node(x);
		
		//ͨ���������ҵ�������λ��
		node* p = pos._node;
		
		p->_pre->_next = cur;
		cur->_pre = p->_pre;

		cur->_next = p;
		p->_pre = cur;
	}

	//clear
	void clear()
	{
		iterator it = begin();
		/*while (it != end())
		{
			iterator next = it;
			next++;

			delete it._node;
			it = next;
		}
		_head->_next = _head;
		_head->_pre = _head;*/

		while (it != end())
			erase(it++);
	}

	//earse
	iterator erase(iterator pos)
	{
		//û��Ԫ�ص�ʱ����ɾ��
		assert(pos != end());

		//�������ĳ�Ա��node��һ���ṹ��
		node* del = pos._node;
		node* ret = del->_next;
		node* pre = del->_pre;

		pre->_next = ret;
		ret->_pre = pre;
		delete del;

		//����*��������أ����ؽ�����
		return iterator(ret);
	}

private:
	node* _head;
};