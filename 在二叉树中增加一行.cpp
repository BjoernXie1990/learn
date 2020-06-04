����һ�������������ڵ�Ϊ��1�㣬���Ϊ 1�������?d?��׷��һ��ֵΪ?v?�Ľڵ㡣

��ӹ��򣺸���һ�����ֵ d ������������������Ϊ d-1 ���ÿһ�ǿսڵ� N��Ϊ N ��������ֵΪ?v?������������������

��?N ԭ�ȵ�������������Ϊ�½ڵ�?v ������������?N ԭ�ȵ�������������Ϊ�½ڵ�?v ����������

��� d ��ֵΪ 1����� d - 1 �����ڣ��򴴽�һ���µĸ��ڵ� v��ԭ�ȵ�����������Ϊ v ����������

ʾ�� 1:

����: 
������������ʾ:
       4
     /   \
    2     6
   / \   / 
  3   1 5   

v = 1

d = 2

���: 
       4
      / \
     1   1
    /     \
   2       6
  / \     / 
 3   1   5   

ʾ�� 2:

����: 
������������ʾ:
      4
     /   
    2    
   / \   
  3   1    

v = 1

d = 3

���: 
      4
     /   
    2
   / \    
  1   1
 /     \  
3       1


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow1(TreeNode* root, int v, int d) {
        if(d == 1)
        {
            TreeNode* ret = new TreeNode(v);
            ret->left = root;
            return ret;
        }
        queue<TreeNode*> que;
        que.push(root);
        int height = 2;
        while(!que.empty())
        {
            int size = que.size();

            for(int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();

                if(height == d)
                {
                    TreeNode* left = new TreeNode(v);
                    if(node->left) left->left = node->left;
                    node->left = left;
                    
                    TreeNode* right = new TreeNode(v);
                    if(node->right) right->right = node->right;
                    node->right = right;
                }
                else
                {
                    if(node->left) que.push(node->left);
                    if(node->right) que.push(node->right);
                }

            }

            if(height == d) break;
            height++;
        }
        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int v, int d)
    {
        if(d == 1 || d == 0)
        {
            TreeNode* ret = new TreeNode(v);
            d == 1 ? ret->left = root : ret->right = root;;
            return ret;
        }

        if(root && d > 1)
        {
            root->left = addOneRow(root->left,v,d > 2 ? d - 1 : 1);
            root->right = addOneRow(root->right,v,d > 2 ? d - 1 : 0);
        }

        return root;
    }
};
