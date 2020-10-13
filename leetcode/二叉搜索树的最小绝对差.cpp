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
    int minN = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        int pre = -1;
        dfs(root,pre);

        return minN;
    }

    void dfs(TreeNode* root,int& pre) {
        if(root == nullptr) return ;

        dfs(root->left,pre);

        if(pre != -1)   minN = min(minN,root->val - pre);
         
        pre = root->val;
        dfs(root->right,pre);
    }
};

����һ�����нڵ�Ϊ�Ǹ�ֵ�Ķ�����������������������������ڵ�Ĳ�ľ���ֵ����Сֵ��

?

ʾ����

���룺

   1
    \
     3
    /
   2

�����
1

���ͣ�
��С���Բ�Ϊ 1������ 2 �� 1 �Ĳ�ľ���ֵΪ 1������ 2 �� 3����
?

��ʾ��

���������� 2 ���ڵ㡣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
