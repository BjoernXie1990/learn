����һ�����������ҳ�����С��ȡ�

��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������

˵��:?Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ��:

����������?[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
����������С��� ?2.


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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);

        int ans = 1;
        while(!que.empty())
        {
            int size = que.size();

            for(int i = 0; i < size; i++)
            {
                auto f = que.front();
                que.pop();

                if(f->left == nullptr && f->right == nullptr)
                    return ans;
                if(f->left != nullptr)  que.push(f->left);
                if(f->right != nullptr) que.push(f->right);
            }
            ans++;
        }
        return ans;
    }
};
