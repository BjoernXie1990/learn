//����һ�ö�������ÿ���ڵ��ֵΪ 1 �� 9 �����ǳƶ������е�һ��·���� ��α���ġ��ģ��������㣺·�����������нڵ�ֵ�������У�����һ���������С�

//���㷵�شӸ���Ҷ�ӽڵ������·����?α����?·������Ŀ��




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
    int arr[10];
    int ans;
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    void dfs(TreeNode* root)
    {
        arr[root->val]++;
        
        
        if(root->left)
        {
            dfs(root->left);
        }
        
        if(root->right)
        {
            dfs(root->right);
        }
        if(!root->left && !root->right)
            if(chose()) ans++;
        arr[root->val]--;
    }
    
    bool chose()
    {
        int ret = 0;
        for(int i = 1; i <= 9; i++)
        {
            if(arr[i] & 1) ret++;
            
            if(ret > 1) return false;
        }
        return true;
    }
};
