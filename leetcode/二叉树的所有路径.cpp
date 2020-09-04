����һ�����������������дӸ��ڵ㵽Ҷ�ӽڵ��·����

˵��:?Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ��:

����:

   1
 /   \
2     3
 \
  5

���: ["1->2->5", "1->3"]

����: ���и��ڵ㵽Ҷ�ӽڵ��·��Ϊ: 1->2->5, 1->3


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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == nullptr) return ans;

        dfs("",ans,root);
        return ans;
    }

    void dfs(string str,vector<string>& ans,TreeNode* root){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(str + to_string(root->val));
            return ;
        }

        dfs(str + to_string(root->val) + "->",ans,root->left);
        dfs(str + to_string(root->val)  + "->",ans,root->right);
    }
};
