
����һ�ö����������㷵�ز��������Ҷ�ӽڵ�ĺ͡�

?

ʾ����



���룺root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
�����15
?

��ʾ��

���нڵ���Ŀ��?1?��?10^4?֮�䡣
ÿ���ڵ��ֵ��?1?��?100 ֮�䡣

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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int ans = 0;
        while(!que.empty())
        {
            int size = que.size();

            int num = 0;
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);

                num += node->val;
            }

            ans = num;
        }
        return ans;
    }
};
