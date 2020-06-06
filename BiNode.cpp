���������ݽṹTreeNode��������ʾ������������left�ÿգ�rightΪ��һ������ڵ㣩��ʵ��һ���������Ѷ���������ת��Ϊ��������Ҫ��ֵ��˳�򱣳ֲ��䣬ת������Ӧ��ԭַ�ģ�Ҳ������ԭʼ�Ķ�����������ֱ���޸ġ�

����ת����ĵ��������ͷ�ڵ㡣

ע�⣺�������ԭ�������Ķ�

?

ʾ����

���룺 [4,2,5,1,3,null,6,0]
����� [0,null,1,null,2,null,3,null,4,null,5,null,6]
��ʾ��

�ڵ��������ᳬ�� 100000��

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
    TreeNode* convertBiNode1(TreeNode* root) {
        TreeNode* tmp = nullptr;
        TreeNode* ret = nullptr;
        dfs(root,tmp,ret);

        return ret;
    }

    void dfs(TreeNode* root,TreeNode*& pre,TreeNode*& ret)
    {
        if(!root) return ;

        if(root->left) dfs(root->left,pre,ret);

        if(!ret) ret = root;
        
        root->left = nullptr;
        if(pre) pre->right = root;
        pre = root;

        if(root->right) dfs(root->right,pre,ret);
    }

    //�ǵݹ�
    TreeNode* convertBiNode(TreeNode* root)
    {
        if(!root) return root;

        stack<TreeNode*> st;
        TreeNode* r = root;
        TreeNode* head = new TreeNode(-1);
        TreeNode* p = head;

        while(r || !st.empty())
        {
            if(r)
            {
                st.push(r);
                r = r->left;
                continue;
            }

            //�Ѿ��������һ��û�з��ʵ���ڵ�
            r = st.top();
            st.pop();
            r->left = nullptr;
            p->right = r;
            p = r;
            r = r->right;
            
        }

        TreeNode* ret = head->right;
        delete head;
        return ret;
    }
};
