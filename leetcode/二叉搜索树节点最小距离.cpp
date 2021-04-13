/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res;
    int minDiffInBST(TreeNode* root) {
        res = INT_MAX;
        int pre = -1;
        dfs(root,pre);
        return res;
    }

    void dfs(TreeNode* root,int& pre) {
        if(root == nullptr)
            return ;
        dfs(root->left,pre);

        int v = root->val;
        if(pre != -1) 
            res = min(res,v - pre);
        pre = v;

        dfs(root->right,pre); 
    }
};


����һ�������������ĸ��ڵ� root ������ ������������ͬ�ڵ�ֵ֮�����С��ֵ ��

ע�⣺������ 530��https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ ��ͬ

?

ʾ�� 1��


���룺root = [4,2,6,1,3]
�����1
ʾ�� 2��


���룺root = [1,0,48,null,null,12,49]
�����1
?

��ʾ��

���нڵ���Ŀ�ڷ�Χ [2, 100] ��
0 <= Node.val <= 105

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
