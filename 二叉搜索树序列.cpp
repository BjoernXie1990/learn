�������ұ���һ�����飬ͨ�����Ͻ����е�Ԫ�ز������п����𲽵�����һ�ö���������������һ���ɲ�ͬ�ڵ���ɵĶ�����������������п������ɴ��������顣

?

ʾ����
�������¶�����

        2
       / \
      1   3
���أ�

[
   [2,1,3],
   [2,3,1]
]

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
    int sum = 0;
    vector<vector<int>> BSTSequences(TreeNode* root) {
        if(root == nullptr) return {{}};
        
        vector<vector<int> > ans;
        vector<int> buf;
        deque<TreeNode*> que;
        que.push_back(root);

        check(ans,buf,que);
        return ans;
    }

    void check(vector<vector<int> >& ans,vector<int>& buf,deque<TreeNode*>& que)
    {
        if(que.empty())
        {
            ans.push_back(buf);
            return;
        }

        size_t size = que.size();
        while(size--)
        {
            auto f = que.front();
            que.pop_front();

            buf.push_back(f->val);
            int child = 0;
            if(f->left)
            {
                child++;
                que.push_back(f->left);
            }
            if(f->right)
            {
                child++;
                que.push_back(f->right);
            }
            check(ans,buf,que);

            while(child--)
                que.pop_back();
            que.push_back(f);
            buf.pop_back();
        }

    }
};
