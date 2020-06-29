#pragma once

#include <iostream>
#include <map>

using namespace std;

enum Color
{
	BLACK,
	RED,
};

template<class T>
struct RBTreeNode
{
	typedef RBTreeNode<T> node;

	node* _left;
	node* _right;
	node* _parent;
	T _data;
	Color _col;

	RBTreeNode(const T& data)
	{
		_left = _right = _parent = nullptr;
		_data = data;
		_col = RED;
	}
};

template<class T,class Ref,class Ptr>
struct __TreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __TreeIterator<T, Ref, Ptr> Self;
	Node* _node;

	__TreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	Self& operator++()
	{
		//�����������������ô��һ���ڵ��������������С���Ǹ��ڵ�
		if (_node->_right)
		{
			Node* cur = _node->_right;
			while (cur->_left)
				cur = cur->_left;
			_node = cur;
		}
		else
		{
			//�����������ڣ�
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	Self& operator--()
	{
		if (_node->_left != nullptr)
		{
			//�ҵ�������������һ���ڵ�
			Node* cur = _node->_left;
			while (cur->_right)
				cur = cur->_right;
			_node = cur;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}

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

template<class K,class T,class KOfT>
class RBTree
{
public:
	typedef RBTreeNode<T> node;
	//������
	typedef __TreeIterator<T, T&, T*> iterator;
	typedef __TreeIterator<T, const T&, const T*> const_iterator;
public:
	RBTree()
		:_root(nullptr)
	{}

	//������
	iterator begin()//������С�Ľڵ��iterator������
	{
		node* cur = _root;
		while (cur && cur->_left)
			cur = cur->_left;
		return iterator(cur);
	}

	iterator end()//�������Ԫ�ص���һ��Ԫ�أ���Ϊ��
	{
		return iterator(nullptr);
	}

	//����
	pair<iterator,bool> Insert(const T& data)
	{
		//�ҵ�����ڵ�
		if (_root == nullptr)
		{
			_root = new node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root),true);
		}

		KOfT koft;//�Ƚϵĺ���
		node* parent = nullptr;
		node* cur = _root;
		while (cur)
		{
			if (koft(cur->_data) == koft(data))
				return make_pair(iterator(cur),false);
			parent = cur;
			cur = (koft(cur->_data) < koft(data)) ? cur->_right : cur->_left;
		}

		//��ʱcurΪ����ڵ��λ�ã�cur��Ϊnullptr
		cur = new node(data);
		node* newNode = cur;
		if (koft(parent->_data) < koft(cur->_data))
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else if (koft(parent->_data) > koft(cur->_data))
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//����
		while (parent && parent->_col == RED)
		{
			//�ҵ����׵ĸ��׽ڵ�
			node* grandfather = parent->_parent;
			//ͨ��grandfather�ڵ㣬�ҵ�cur������ڵ�
			
			if (grandfather->_left == parent)
			{
				//����ڵ�Ϊgrandfather�ҽڵ�
				node* uncle = grandfather->_right;
				
				// 1. uncle ���ڣ����Ҹýڵ�Ϊ��ɫ
				if (uncle != nullptr && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//�������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//3.cur ��parent���������ڵ�
					if (cur == parent->_right)
					{
						Right_Right(parent);
						swap(parent, cur);
					}

					//2.uncle�ڵ�Ϊnullptr��˵��cur���һ���������ڵ㣬���������ϵ�����Ľڵ�
					//uncle�ڵ���ڣ���ô��ʱ��һ���Ǻ�ɫ�ڵ�
					//��grandfather����һ������
					Left_Left(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;

					break;
				}
			}
			else if (grandfather->_right = parent)
			{
				node* uncle = grandfather->_left;

				if (uncle != nullptr && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						Left_Left(parent);
						swap(parent, cur);
					}

					Right_Right(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;

					break;
				}
			}
		}

		_root->_col = BLACK;
		return make_pair(iterator(newNode),true);
	}

	//�������
	void Inorder()
	{
		_Inorder(_root);
	}

	//�ж��Ƿ��Ǻ����
	bool IsRBTree()
	{
		node* proot = _root;
		//����Ҳ�Ǻ����
		if (nullptr == proot)
			return true;

		//���ڵ����Ϊ��ɫ
		if (BLACK != proot->_col)
		{
			cout << "���ڵ㲻Ϊ��ɫ" << endl;
			return false;
		}

		//��ȡ����һ��·���У���ɫ�ڵ������
		size_t blackNum = 0;
		node* cur = proot;
		while (cur != nullptr)
		{
			if (BLACK == cur->_col)
				blackNum++;
			cur = cur->_left;
		}

		size_t k = 0;
		return _IsRBTree(proot, k, blackNum);
	}

	iterator Find(const K& key)
	{
		KOfT koft;
		node* cur = _root;
		while (cur)
		{
			if (koft(cur) == key)
				return iterator(cur);
			cur = (koft(cur->_data) < key) ? cur->_right : cur->_left;
		}
		return iterator(nullptr);
	}
private:
	bool _IsRBTree(node* root, size_t k, size_t blackNum)
	{
		//�ߵ���Ҷ�ӽڵ㣬�жϺ�ɫ�ڵ��Ƿ����
		if (nullptr == root)
		{
			if (k != blackNum)
			{
				cout << "·���к�ɫ�ڵ����������" << endl;
				return false;
			}
			return true;
		}

		// ͳ�ƺ�ɫ�ڵ�ĸ���
		if (BLACK == root->_col)
			k++;

		// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
		node* pParent = root->_parent;
		if (pParent != nullptr && RED == pParent->_col && RED == root->_col)
		{
			cout << "�����������ĺ�ɫ�ڵ�" << endl;
			return false;
		}
		return _IsRBTree(root->_left, k, blackNum) && _IsRBTree(root->_right, k, blackNum);
	}
	//����
	void Left_Left(node* parent)
	{
		node* pParent = parent->_parent;
		node* pLeft = parent->_left;
		node* pLRight = pLeft->_right;

		parent->_left = pLRight;
		if (pLRight)	pLRight->_parent = parent;

		pLeft->_right = parent;
		parent->_parent = pLeft;

		if (pParent == nullptr)
			_root = pLeft;
		else
			(parent == pParent->_left) ? pParent->_left = pLeft: pParent->_right = pLeft;
		pLeft->_parent = pParent;
	}

	//����
	void Right_Right(node* parent)
	{
		node* pParent = parent->_parent;
		node* pRight = parent->_right;
		node* pRLeft = pRight->_left;

		parent->_right = pRLeft;
		if(pRLeft)	pRLeft->_parent = parent;

		pRight->_left = parent;
		parent->_parent = pRight;

		if (pParent == nullptr)
			_root = pRight;
		else
			(pParent->_left == parent) ? pParent->_left = pRight : pParent->_right = pRight;
		pRight->_parent = pParent;
	}

	//�������
	void _Inorder(node* root)
	{
		if (root == nullptr)
			return;

		_Inorder(root->_left);
		cout << root->_data.first << " : " << root->_data.second << endl;
		_Inorder(root->_right);
	}
private:
	node* _root;
};