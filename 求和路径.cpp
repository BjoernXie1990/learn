����һ�ö�����������ÿ���ڵ㶼����һ��������ֵ(��ֵ������)�����һ���㷨����ӡ�ڵ���ֵ�ܺ͵���ĳ������ֵ������·����������ע�⣬·����һ���ǵôӶ������ĸ��ڵ��Ҷ�ڵ㿪ʼ������������䷽���������(ֻ�ܴӸ��ڵ�ָ���ӽڵ㷽��)��

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

3
���ͣ���Ϊ 22?��·���У�[5,4,11,2], [5,8,4,5], [4,11,7]
��ʾ��

�ڵ����� <= 10000


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
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
       
        return dfs(root,0,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
    }

    int dfs(TreeNode* root,int n,int sum)
    {
        if(root == nullptr) return 0;
        n += root->val;
        int ret = 0;
        if(n == sum) ret++;

        ret += dfs(root->left,n,sum) + dfs(root->right,n,sum);

        // int num = root->val;
        // if(root->left && root->right)
        // {
        //     num += root->left->val + root->right->val;
        //     ret += (num == sum);
        // }
        
        return ret;
    }
};
