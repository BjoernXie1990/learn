����һ�ö����������㷵�������������������нڵ��ֵ֮�ͣ�

�ýڵ���游�ڵ��ֵΪż������һ���ڵ���游�ڵ���ָ�ýڵ�ĸ��ڵ�ĸ��ڵ㡣��
����������游�ڵ�ֵΪż���Ľڵ㣬��ô����?0 ��

?

ʾ����



���룺root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
�����18
���ͣ�ͼ�к�ɫ�ڵ���游�ڵ��ֵΪż������ɫ�ڵ�Ϊ��Щ��ɫ�ڵ���游�ڵ㡣
?

��ʾ��

���нڵ����Ŀ��?1 ��?10^4?֮�䡣
ÿ���ڵ��ֵ��?1 ��?100 ֮�䡣

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
    int sumEvenGrandparent(TreeNode* root) {
        int ans = dfs(root,-1,-1);

        return ans;
    }

    int dfs(TreeNode* root,int parent,int grandparent)
    {
        if(root == nullptr) return 0;

        int ret = 0;
        if((grandparent & 1) == 0)
            ret += root->val;
        
        ret += dfs(root->left,root->val,parent);
        ret += dfs(root->right,root->val,parent);

        return ret;
    }
};
