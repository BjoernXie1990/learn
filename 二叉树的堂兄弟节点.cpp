�ڶ������У����ڵ�λ����� 0 ����ÿ�����Ϊ k �Ľڵ���ӽڵ�λ����� k+1 ����

����������������ڵ������ͬ�������ڵ㲻ͬ����������һ�����ֵܽڵ㡣

���Ǹ����˾���Ψһֵ�Ķ������ĸ��ڵ� root���Լ�����������ͬ�ڵ��ֵ x �� y��

ֻ����ֵ x �� y ��Ӧ�Ľڵ������ֵܽڵ�ʱ���ŷ��� true�����򣬷��� false��

?

ʾ�� 1��


���룺root = [1,2,3,4], x = 4, y = 3
�����false
ʾ�� 2��


���룺root = [1,2,3,null,4,null,5], x = 5, y = 4
�����true
ʾ�� 3��



���룺root = [1,2,3,null,4], x = 2, y = 3
�����false
?

��ʾ��

�������Ľڵ�������?2 ��?100?֮�䡣
ÿ���ڵ��ֵ����Ψһ�ġ���ΧΪ?1 ��?100?��������


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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            int size = que.size();
            int sum = 0;
            while(size--)
            {
                auto f = que.front();
                que.pop();
                
                int tmp = 0;
                if(f->left)
                {
                    if(f->left->val == x || f->left->val == y)
                    {
                        sum++;
                        tmp++;
                    }
                        
                    que.push(f->left);
                }
                if(f->right)
                {
                    if(f->right->val == x || f->right->val == y)
                    {
                        sum++;
                        tmp++;
                    }
                    que.push(f->right);
                }

                if(tmp == 2) return false;//ͬһ�����׽ڵ�
            }

            if(sum == 2)    return true;//���ֵܽڵ�
            if(sum != 0)    return false;//ֻ�ҵ�һ���ڵ�
        }
        return false;
    }
};
