#pragma once

#include <iostream>
#include <cmath>
#include <assert.h>
#include <map>
#include <algorithm>

using namespace std;

template<class Key,class Val>
struct tree_node
{
	typedef tree_node<Key, Val> node;
	typedef pair<Key, Val> data_type;

	node* _parent;	//˫�׽ڵ�
	node* _left;	//���ӽڵ�
	node* _right;	//�Һ��ӽڵ�
	data_type _data;//�ڵ��ֵ
	int _bf;		//ƽ������

	tree_node(const data_type& data)
		:_data(data), _bf(0)
	{
		_parent = _left = _right = nullptr;
	}
};

template<class key, class val>
class avl_tree
{
public:
	typedef key key_type;
	typedef val val_type;
	typedef tree_node<key_type,val_type> node;
	avl_tree()
		:root(nullptr)
	{}

	bool insert(const pair<key_type,val_type>& data)
	{
		//�������û�нڵ�
		if (root == nullptr)
		{
			root = new node(data);
			return true;
		}

		node* parent = nullptr;
		node* cur = root;
		
		//�ҵ�Ҫ�����λ��
		while (cur)
		{
			if (cur->_data.first == data.first) return false;
			parent = cur;
			//cur = (cur->_data.first < data.first) ? cur->_right : cur->_left;
			if (cur->_data.first < data.first)
			{
				//cur->_bf++;
				cur = cur->_right;
			}
			else if (cur->_data.first > data.first)
			{
				//cur->_bf--;
				cur = cur->_left;
			}
		}

		cur = new node(data);
		//���� cur ��ָ��λ��
		if (parent->_data.first < data.first)
			parent->_right = cur;
		else
			parent->_left = cur;
		cur->_parent = parent;

		//����ƽ������
		while (parent)
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else if (cur == parent->_left)
			{
				parent->_bf--;
			}

			if (parent->_bf == 0)
			{
				break;
			}
			else if (abs(parent->_bf) == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				//��ʱparent�������Ѿ���ƽ�⣬��Ҫ����
				if (parent->_bf == -2) //��߸�
				{
					if (cur->_bf == -1)//��ߵ���߸�
						Left_Left(parent);
					else if (cur->_bf == 1)
						Left_Right(parent);
				}
				else if (parent->_bf == 2)
				{
					if (cur->_bf == 1) //�ұߵ��ұ߸�
						Right_Right(parent);
					else
						Right_Left(parent);
				}

				return true;
			}
			else
			{
				//�����ʾ�����˲��Ϸ���ƽ������
				assert(false);
			}
		}

		return true;
	}

	//�������
	void Show()
	{
		_midShow(root);
		cout << endl;
	}

	//�ж��Ƿ���ƽ�������
	bool IsBF()
	{
		return _IsBF(root);
	}
private:
	//�ң��ң�����
	void Right_Right(node* parent)
	{
		//�������׵ĸ��׽ڵ�
		node* pParent = parent->_parent;
		//���׵��ҽڵ�
		node* pRight = parent->_right;
		//�ҽڵ����ڵ�
		node* pRLeft = pRight->_left;

		//�Ȱ� pRLeft �� parent �ڵ���������
		parent->_right = pRLeft;
		//���� pRLeft �ĸ��׽ڵ�Ϊ parent
		if (pRLeft) pRLeft->_parent = parent;

		//��ʼ����
		pRight->_left = parent;
		parent->_parent = pRight;

		//pRight ��ʱ��Ϊ�µĸ��׽ڵ㣬��Ҫ�ж��Ƿ����µĸ��ڵ�
		//������ pRight �� pParent 
		if (pParent == nullptr)
			root = pRight;
		else
			(pParent->_left == parent) ? pParent->_left = pRight : pParent->_right = pRight;
		
		pRight->_parent = pParent;
		pRight->_bf = parent->_bf = 0;
	}

	//��������
	void Left_Left(node* parent)
	{
		// �������׵ĸ��׽ڵ�
		node* pParent = parent->_parent;
		//���׵���ڵ�
		node* pLeft = parent->_left;
		//��ڵ���ҽڵ�
		node* pLRight = pLeft->_right;

		//�Ȱ� pLRight �� parent �ڵ���������
		parent->_left = pLRight;
		//���� pLRight �ĸ��׽ڵ�Ϊ parent
		if (pLRight) pLRight->_parent = parent;

		//��ʼ����
		pLeft->_right = parent;
		parent->_parent = pLeft;

		//pLeft ��ʱ��Ϊ�µĸ��׽ڵ㣬��Ҫ�ж��Ƿ����µĸ��ڵ�
		//������ pLeft �� pParent 
		if (pParent == nullptr)
			root = pLeft;
		else
			(parent == pParent->_left) ? pParent->_left = pLeft : pParent->_right = pLeft;

		pLeft->_parent = pParent;
		pLeft->_bf = parent->_bf = 0;
	}

	//���ң�˫��
	void Left_Right(node* parent)
	{
		node* pLeft = parent->_left;
		node* pLRight = pLeft->_right;
		int pLRbf = pLRight->_bf;
		//�ң��ң�����
		Right_Right(pLeft);

		//���󣬵���
		Left_Left(parent);

		if (pLRbf == 1)
		{
			parent->_bf = 0;
			pLeft->_bf = -1;
			pLRight->_bf = 0;
		}
		else if (pLRbf == -1)
		{
			parent->_bf = 1;
			pLeft->_bf = 0;
			pLRight->_bf = 0;
		}
		else if (pLRbf == 0)
		{
			parent->_bf = 0;
			pLeft->_bf = 0;
			pLRight->_bf = 0;
		}
	}

	void Right_Left(node* parent)
	{
		node* pRight = parent->_right;
		node* pRLeft = pRight->_left;
		int pRLbf = pRLeft->_bf;
		//���󣬵���
		Left_Left(pRight);

		//�ң��ң�����
		Right_Right(parent);

		if (pRLbf == 1)
		{
			parent->_bf = -1;
			pRight->_bf = 0;
			pRLeft->_bf = 0;
		}
		else if (pRLbf == -1)
		{
			parent->_bf = 0;
			pRight->_bf = 1;
			pRLeft->_bf = 0;
		}
		else if (pRLbf == 0)
		{
			parent->_bf = 0;
			pRight->_bf = 0;
			pRLeft->_bf = 0;
		}
	}

	//show
	void _midShow(node* root)
	{
		if (root == nullptr) return;

		_midShow(root->_left);
		cout << root->_data.first << ' ';
		_midShow(root->_right);
	}

	//�ж��Ƿ���ƽ��
	bool _IsBF(node* root)
	{
		if (root == nullptr) return true;

		int leH = _Height(root->_left);//�������߶�
		int riH = _Height(root->_right);//�������߶�

		if (riH - leH != root->_bf)
		{
			cout << root->_data.first << " ƽ�������쳣" << endl;
			return false;
		}
			
		return _IsBF(root->_left) && _IsBF(root->_right);
	}

	//�ɸ��ڵ�ȷ�������߶�
	int _Height(node* root)
	{
		if (root == nullptr)
			return 0;
		return 1 + max(_Height(root->_left), _Height(root->_right));
	}
private:
	node* root;
};