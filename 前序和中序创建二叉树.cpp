�����������ǰ��ͺ������ƥ����κζ�������

?pre?��?post?�����е�ֵ�ǲ�ͬ����������

?

ʾ����

���룺pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
�����[1,2,3,4,5,6,7]
?

��ʾ��

1 <= pre.length == post.length <= 30
pre[]?��?post[]?����?1, 2, ..., pre.length?������
ÿ�����뱣֤������һ���𰸡�����ж���𰸣����Է�������һ����

ֻ��ÿ���ڵ��Ϊ2����0��ʱ��ǰ��ͺ������Ψһȷ��һ�Ŷ�������ֻ��һ���ӽڵ����޷�ȷ���ģ���Ϊ�޷��ж���������������������



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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int l1 = 0;
        int l2 = 0;
        return dfs(pre,l1,pre.size() - 1,
                post,l2,post.size() - 1);
    }

    TreeNode* dfs(vector<int>& pre, int& l1, int r1, 
                vector<int>& post,int& l2, int r2)
    {
        if(l1 > r1 && l2 > r2) return nullptr;

        TreeNode* root = new TreeNode(pre[l1++]);
        //�ȹ��������� 
        if(root->val != post[l2])
            root->left = dfs(pre,l1,r1,post,l2,r2);
        
        //�ڹ��������� 
        if(root->val != post[l2])
            root->right = dfs(pre,l1,r1,post,l2,r2);
        l2++;
        return root;
    }
};
