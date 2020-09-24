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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == nullptr) return -1;
        return dfs(root,root->val);
    }

    int dfs(TreeNode* root,int val) {
        if(root == nullptr) return -1;
        if(root->val > val) return root->val;

        int le = dfs(root->left,val);
        int ri = dfs(root->right,val);
        if(le > val && ri > val) return min(le,ri);

        // le == val || ri == val
        return max(le,ri);
    }
};


����һ���ǿ�����Ķ�������ÿ���ڵ㶼������������ÿ���ڵ���ӽڵ�����ֻ��Ϊ?2?��?0�����һ���ڵ��������ӽڵ�Ļ�����ô�ýڵ��ֵ���������ӽڵ��н�С��һ����

����������һ��������������Ҫ������нڵ��еĵڶ�С��ֵ������ڶ�С��ֵ�����ڵĻ������ -1 ��

ʾ�� 1:

����: 
    2
   / \
  2   5
     / \
    5   7

���: 5
˵��: ��С��ֵ�� 2 ���ڶ�С��ֵ�� 5 ��
ʾ�� 2:

����: 
    2
   / \
  2   2

���: -1
˵��: ��С��ֵ�� 2, ���ǲ����ڵڶ�С��ֵ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
