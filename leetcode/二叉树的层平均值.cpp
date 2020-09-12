����һ���ǿն�����, ����һ����ÿ��ڵ�ƽ��ֵ��ɵ����顣

?

ʾ�� 1��

���룺
    3
   / \
  9  20
    /  \
   15   7
�����[3, 14.5, 11]
���ͣ�
�� 0 ���ƽ��ֵ�� 3 ,  ��1���� 14.5 , ��2���� 11 ����˷��� [3, 14.5, 11] ��
?

��ʾ��

�ڵ�ֵ�ķ�Χ��32λ�з���������Χ�ڡ�

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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        vector<double> ans;

        while(!que.empty()) {
            int size = que.size();
            double sum = 0;
            for(int i = 0; i < size; i++) {
                auto f = que.front();
                que.pop();
                sum += f->val;
                if(f->left) que.push(f->left);
                if(f->right) que.push(f->right);
            }
            ans.push_back(sum/(double)size);
        }

        return ans;
    }
};
