#pragma once

#include <iostream>
#include <cstdlib>
using namespace std;

//�洢���нڵ�Ľṹ��
template<class T>
struct TreeNode
{
	T _key;
	TreeNode<T>* _left;
	TreeNode<T>* _right;

	TreeNode(const T key = 0)
		:_key(key), _left(nullptr), _right(nullptr)
	{}
};

template<class T>
class STree
{
public:
	typedef TreeNode<T> TreeNode;
public:
	STree()
		:root(nullptr)
	{}
	//��������
	bool Insert(const T key)
	{
		TreeNode* cur = root;
		TreeNode* parent = nullptr;

		//�ҵ���Ҫ�����λ�ã�������λ�����棬˵�������Ǵ�����ĵط�
		while (cur)
		{
			//���ų����ڵ����
			if (cur->_key == key) return true;
			parent = cur;

			//�����ǰ�ڵ��ֵ �� key ��˵��������Ҫ�����Լ��� ������
			//�����ǰ�ڵ��ֵ �� key С��˵��������Ҫ�����Լ��� ������
			cur = cur->_key > key ? cur->_left : cur->_right;
		}

		cur = new TreeNode(key);
		//ע�⵱ǰcur�ڵ�Ϊnullptr������û�е�ַ�ģ�������Ҫ��������Ľڵ�����ĸ��׽ڵ��ֶ�����
		parent == nullptr ? root = cur : (parent->_key > key ? parent->_left = cur : parent->_right = cur);
		return true;
	}

	//�ݹ����
	bool InsertR(const T key)
	{
		return _InsertR(root, key);
	}
	
	//��������
	TreeNode* Find(const T key)
	{
		TreeNode* cur = root;

		while (cur)
		{
			if (cur->_key == key) return cur;

			cur = cur->_key > key ? cur->_left : cur->_right;
		}
		//�����ʱ��curΪnullptr ��˵��û���ҵ�������nullptr
		return nullptr;
	}

	//�ݹ����
	TreeNode* FindR(const T key)
	{
		return _FindR(root, key);
	}

	//�ݹ�ɾ���ڵ�
	bool EarseR(const int key)
	{
		return _EarseR(root,key);
	}

	//����ɾ��
	bool Earse(const T key)
	{
		//�Ȳ��Ҹýڵ㣬ͬʱ�������׽ڵ��λ��
		TreeNode* parent = nullptr;
		TreeNode* cur = root;

		while (cur)
		{
			if (cur->_key == key) break;

			parent = cur;
			cur = cur->_key > key ? cur->_left : cur->_right;
		}

		//���û������ڵ㣬�Ͳ���Ҫɾ��
		if (!cur) return false;

		TreeNode* del = cur;

		//��ʱ��Ҫɾ��cur�ڵ�,ע��Ҫɾ����λ���Ǹ��ڵ�����
		if (!cur->_left)
		{
			if (!parent)
				root = cur->_right;
			else if (cur == parent->_left) //Ҫɾ���Ľڵ���������
				parent->_left = cur->_right;
			else if (cur == parent->_right)	//Ҫɾ���Ľڵ���������
				parent->_right = cur->_right;
		}
		else if (!cur->_right)
		{
			if (!parent)
				root = cur->_left;
			else if (cur == parent->_left)//Ҫɾ���Ľڵ���������
				parent->_left = cur->_left;
			else if (cur == parent->_right)//Ҫɾ���Ľڵ���������
				parent->_right = cur->_left;
		}
		else
		{
			TreeNode* minParent = cur;
			TreeNode* minLeft = cur->_right;
			
			//�ҵ����һ������
			while (minLeft->_left)
			{
				minParent = minLeft;
				minLeft = minLeft->_left;
			}

			//��ʱ��Ҫ��minLeft�ŵ�cur�ڵ��λ�ã�Ȼ��ɾ��minLeft�ڵ�
			cur->_key = minLeft->_key;

			//ɾ��minLeft�ڵ㣬���Ƿ�ֹminLeft���Һ��Ӵ���
			if (minParent->_right == minLeft) //˵����һ���Һ���û������
				minParent->_right = minLeft->_right;
			else	//ɾ��������ӣ�����λ�þ��� ���ӵ��Һ��Ӷ���
				minParent->_left = minLeft->_right;

			del = minLeft;//��ʱ��minLeft�����Ҫɾ���Ľڵ�
		}

		delete del;
		return true;
	}
	

	//��ӡ���������������нڵ㣬������
	void Show()
	{
		//��������ӿ�
		_Inorder(root);
		cout << endl;
	}

	int RootKey()
	{
		return root->_key;
	}

private:
	//��������ӿ�
	void _Inorder(TreeNode* root)
	{
		if (!root) return;

		_Inorder(root->_left);
		cout << root->_key << ' ';
		_Inorder(root->_right);
	}

	//���ҵ��õĽӿ�
	TreeNode* _FindR(TreeNode*& root, const T key)
	{
		//���ڵ�Ϊ�գ����߸��ڵ�ΪKey����ֱ�ӷ���root��
		if (!root || root->_key == key) return root;

		//û�ҵ����͵��������߼�����
		TreeNode* ret = root->_key > key ? _FindR(root->_left, key) : _FindR(root->_right, key);

		return ret;
	}

	//�ݹ����ӿ�
	bool _InsertR(TreeNode*& root, const T key)
	{
		//���ڵ�Ϊ nullptr ������˵�������λ�þ��Ǹ��ڵ��λ��
		if (!root)
		{
			root = new TreeNode(key);
			return true;
		}
		//������ڵ��ֵ��key��ͬ���Ͳ���Ҫ����
		if (root->_key == key) return true;

		//��ǰλ�ò��ǲ���λ�ã��ж���Ҫ�ݹ����������������
		bool ret = root->_key > key ? _InsertR(root->_left, key) : _InsertR(root->_right, key);
		return ret;
	}

	//�ݹ�ɾ���ӿ�
	bool _EarseR(TreeNode*& root,const T key)
	{
		//���ڵ�Ϊ�գ�˵��û��key�Ľڵ�
		if (!root) return false;

		if (root->_key != key)
			return root->_key > key ? _EarseR(root->_left, key) : _EarseR(root->_right, key);

		//�������root->_key == key ���߼�
		//��ʱ����Ҫɾ�� root �ڵ�
		TreeNode* del = root;

		if (!root->_right)	//��Ҫɾ����λ�õ��ҽڵ�Ϊ�գ����ڵ� = ��������
			root = root->_left;
		else if (!root->_left)	//��Ҫɾ��λ�õ���ڵ�Ϊ�գ����ڵ� = �����Һ���
			root = root->_right;
		else  //��Ҫɾ���ڵ����Һ��Ӿ���Ϊ��
		{
			TreeNode* cur = root->_right;
			//�ҵ����һ������
			while (cur->_left)
			{
				cur = cur->_left;
			}

			//��ʱ��Ҫ��cur�ŵ����ڵ��λ�ã�Ȼ��ɾ��cur�ڵ�
			root->_key = cur->_key;

			//������Ա��������������У�ɾ��cur�ڵ�
			return _EarseR(root->_right, cur->_key);

			/*
			//����������������ߵĿ���
			//����λ�õ����ӣ����뵽��һ���Һ��ӵ����һ�����ӵ�λ��
			TreeNode* left = root->_left;
			TreeNode* right = root->_right;

			//�ҵ���һ���Һ��ӵ������У��ҵ����Ŀսڵ�
			TreeNode* cur = right;
			while (cur)
				cur = cur->_left;

			//��������
			cur = left;
			root = right;
			*/
		}

		delete del;
		return true;
	}
private:
	TreeNode* root;
};