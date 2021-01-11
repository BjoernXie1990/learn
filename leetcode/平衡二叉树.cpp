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
    unordered_map<TreeNode*,int> mp;
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(fun(root->left) - fun(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int fun(TreeNode* root) {
        if(!root) return 0;
        if(mp.count(root)) return mp[root];

        int le = 0, ri = 0;
        le = fun(root->left);
        ri = fun(root->right);
        int res = max(le,ri) + 1;
        mp[root] = res;
        return res;
    }
};


����һ�ö������ĸ��ڵ㣬�жϸ����ǲ���ƽ������������ĳ������������ڵ���������������������1����ô������һ��ƽ���������

?

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

?

���ƣ�

1 <= ���Ľ����� <= 10000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
