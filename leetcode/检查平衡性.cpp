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
    bool res = true;
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root) {
        if(!root || !res) return 0;

        int le = dfs(root->left);
        int ri = dfs(root->right);
        if(abs(le - ri) > 1) {
            res = false;
            return 0;
        }
        return max(le,ri) + 1;
    }
};

ʵ��һ�����������������Ƿ�ƽ�⡣����������У�ƽ�����Ķ������£�����һ���ڵ㣬�����������ĸ߶Ȳ���� 1��


ʾ�� 1:
���������� [3,9,20,null,null,15,7]
    3
   / \
  9  20
    /  \
   15   7
���� true ��
ʾ�� 2:
���������� [1,2,2,3,3,null,null,4,4]
      1
     / \
    2   2
   / \
  3   3
 / \
4   4
����?false ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/check-balance-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
