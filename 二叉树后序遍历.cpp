

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
    vector<int> postorderTraversal1(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* r = root;
        TreeNode* node = NULL;

        while(!st.empty() || r)
        {
            if(r)   //���ڵ㲻�ǿգ�˵����ǰ�ڵ���Ч������ջ�б���
            {
                st.push(r);
                r = r->left;//���Ľڵ�Ϊ����
            }
            else    //���ڵ�Ϊ�գ�˵��ǰһ���ڵ���һ��Ҷ�ӽڵ�
            {
                r = st.top();
                //��Ҫ�������ڵ����������
                //һ������û���Һ��ӣ����������ǿ�
                //��һ���������Һ��ӱ�������
                if(!r->right || r->right == node)
                {
                    ans.push_back(r->val);
                    st.pop();
                    node = r;
                    r=NULL;
                }
                else
                    r = r->right;

            }
        }
        return ans;
    }


    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) 
            return ans;
        stack<TreeNode*> st;
        st.push(root);
        

        while(!st.empty())
        {
            TreeNode* node = st.top();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);

            if(!node->left && !node->right)
            {
                ans.push_back(node->val);
                st.pop();
            }
            node->left = node->right = NULL;
        }
        return ans;
    }
};
