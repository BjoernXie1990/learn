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
    int d = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs1(root);
        return d;
    }

    int dfs1(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 0;

        int le = (root->left) ? dfs1(root->left) + 1 : 0;
        int ri = (root->right) ? dfs1(root->right) + 1 : 0;
        d = max(d,le + ri);
        return max(le , ri);
    }


};


����һ�ö�����������Ҫ��������ֱ�����ȡ�һ�ö�������ֱ�������������������·�������е����ֵ������·�����ܴ���Ҳ���ܲ���������㡣

?

ʾ�� :
����������

          1
         / \
        2   3
       / \     
      4   5    
����?3, ���ĳ�����·�� [4,2,1,3] ����?[5,2,1,3]��

?

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/diameter-of-binary-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
