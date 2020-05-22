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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int lenp = preorder.size();
        int leni = inorder.size();
        return dfs(preorder,0,lenp-1,inorder,0,leni-1);
    }

    TreeNode* dfs(vector<int>& preorder,int lp,int rp,vector<int>& inorder,int li,int ri)
    {
        if(lp > rp || li > ri) return NULL;
        TreeNode* root = new TreeNode(preorder[lp]);
        
        //���������Ҹ��ڵ�
        int pos = Find(inorder,li,ri,preorder[lp]);
        //�������ĳ���
        int lenl = pos - li;
       
        //left
        root->left = dfs(preorder,lp+1,lp+lenl,inorder,li,pos-1);

        //right
        root->right = dfs(preorder,lp+lenl+1,rp,inorder,pos+1,ri);

        return root;
    }

    int Find(vector<int>& arr,int l,int r,int num)
    {
        for(int i = l; i <= r; i++)
            if(arr[i] == num) return i;
        return -1;
    }
};
