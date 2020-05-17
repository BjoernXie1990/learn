//����һ�ø�Ϊ root �Ķ����������㷵�ض������кýڵ����Ŀ��

//���ýڵ㡹X ����Ϊ���Ӹ����ýڵ� X �������Ľڵ��У�û���κνڵ��ֵ���� X ��ֵ��

// ���룺root = [3,1,4,3,null,1,5]
//�����4
//���ͣ�ͼ����ɫ�ڵ�Ϊ�ýڵ㡣
//���ڵ� (3) ��Զ�Ǹ��ýڵ㡣
//�ڵ� 4 -> (3,4) ��·���е����ֵ��
//�ڵ� 5 -> (3,4,5) ��·���е����ֵ��
//�ڵ� 3 -> (3,1,3) ��·���е����ֵ��


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
    int ans = 1;
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        
        dfs(root,root->val);
        
        return ans;
    }
    
    void dfs(TreeNode* root,int maxNum)
    {
        if(!root) return ;
        
        if(root->left)
        {
            TreeNode* node = root->left;
            if(node->val >= maxNum)
            {
                ans++;
               // cout<<node->val<<' ';
                dfs(node,node->val);
            }
            else
            {
                dfs(node,maxNum);
            }
        }
        
        if(root->right)
        {
            TreeNode* node = root->right;
            if(node->val >= maxNum)
            {
                ans++;
               // cout<<node->val<<' ';
                dfs(node,node->val);
            }
            else
                dfs(node,maxNum);
        }
    }
};
