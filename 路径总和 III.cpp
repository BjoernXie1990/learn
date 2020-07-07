��һ��������������ÿ����㶼�����һ������ֵ��

�ҳ�·���͵��ڸ�����ֵ��·��������

·������Ҫ�Ӹ��ڵ㿪ʼ��Ҳ����Ҫ��Ҷ�ӽڵ����������·��������������µģ�ֻ�ܴӸ��ڵ㵽�ӽڵ㣩��

������������1000���ڵ㣬�ҽڵ���ֵ��Χ�� [-1000000,1000000] ��������

ʾ����

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

���� 3���͵��� 8 ��·����:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11


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
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;

        int ans = 0;
        dfs(root,sum,ans);
        ans += pathSum(root->right,sum);
        ans += pathSum(root->left,sum);
        return ans;
    }

    void dfs(TreeNode* root,int sum,int& ans)
    {
        if(root == nullptr) return;
        if(sum == root->val)
            ans++;
        dfs(root->left,sum - root->val,ans);
        dfs(root->right,sum - root->val,ans);
    }
};
