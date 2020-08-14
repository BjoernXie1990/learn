
����һ����������һ��Ŀ��ͣ��ҵ����дӸ��ڵ㵽Ҷ�ӽڵ�·���ܺ͵��ڸ���Ŀ��͵�·����

˵��:?Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ��:
�������¶��������Լ�Ŀ���?sum = 22��

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
����:

[
   [5,4,11,2],
   [5,8,4,5]
]

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;

        vector<int> cur;
        cur.push_back(root->val);
        dfs(root,ans,cur,root->val,sum);

        return ans;
    }

    void dfs(TreeNode* root,vector<vector<int>>& ans,vector<int>& cur,int num,int sum)
    {
        if((root->left == nullptr) && (root->right == nullptr))
        {
            if(num == sum)
                ans.push_back(cur);
            return ;
        }

        
        if(root->left)
        {
            cur.push_back(root->left->val);
            dfs(root->left,ans,cur,num + root->left->val,sum);
            cur.pop_back();
        }  
        if(root->right) 
        {
            cur.push_back(root->right->val);
            dfs(root->right,ans,cur,num + root->right->val,sum);
            cur.pop_back();
        }
    }
};
