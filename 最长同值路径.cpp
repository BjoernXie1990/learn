����һ�����������ҵ����·�������·���е�ÿ���ڵ������ֵͬ�� ����·�����Ծ���Ҳ���Բ��������ڵ㡣

ע�⣺�����ڵ�֮���·������������֮��ı�����ʾ��

ʾ�� 1:

����:

              5
             / \
            4   5
           / \   \
          1   1   5
���:

2
ʾ�� 2:

����:

              1
             / \
            4   5
           / \   \
          4   4   5
���:

2
ע��: �����Ķ�����������10000����㡣?���ĸ߶Ȳ�����1000��


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
    int ans = 0;
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr) return 0;

        dfs(root,root->val);

        return ans;
    }

    int dfs(TreeNode* root,int val)
    {
        if(root == nullptr) return 0;

        int le = dfs(root->left,root->val);
        int ri = dfs(root->right,root->val);
        ans = max(ans,le + ri);

        if(root->val == val)
            return max(le,ri) + 1;
        return 0;
    }
};
