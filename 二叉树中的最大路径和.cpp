����һ���ǿն����������������·���͡�

�����У�·��������Ϊһ������������ڵ�������ﵽ����ڵ�����С���·�����ٰ���һ���ڵ㣬�Ҳ�һ���������ڵ㡣

ʾ�� 1:

����: [1,2,3]

       1
      / \
     2   3

���: 6
ʾ��?2:

����: [-10,9,20,null,null,15,7]

?  -10
? ?/ \
? 9 ?20
? ? / ?\
? ?15 ? 7

���: 42


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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root,ans);
        return ans;
    }

    int dfs(TreeNode* root,int& ans)
    {
        if(root == nullptr) return 0;

        //������ҽڵ��ָ���Ǹ�������ô����·��һ���Ǹ��ڵ��ֵ
        int le = max(0,dfs(root->left,ans));
        int ri = max(dfs(root->right,ans),0);

        ans = max(ans,root->val + le + ri);

        return max(le,ri) + root->val;
    }
};
