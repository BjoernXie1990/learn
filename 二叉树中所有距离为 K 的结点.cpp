����һ�������������и����?root����?һ��Ŀ����?target?����һ������ֵ K ��

���ص�Ŀ���� target ����Ϊ K �����н���ֵ���б� �𰸿������κ�˳�򷵻ء�

?

ʾ�� 1��

���룺root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
�����[7,4,1]
���ͣ�
������Ϊ��Ŀ���㣨ֵΪ 5������Ϊ 2 �Ľ�㣬
ֵ�ֱ�Ϊ 7��4���Լ� 1



ע�⣬����� "root" �� "target" ʵ���������ϵĽ�㡣
�������������Ƕ���Щ������������л�������
?

��ʾ��

���������Ƿǿյġ�
���ϵ�ÿ����㶼����Ψһ��ֵ?0 <= node.val <= 500?��
Ŀ����?target?�����ϵĽ�㡣
0 <= K <= 1000.
ͨ������6,088�ύ����


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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int> > map;

        dfs(map,root,nullptr);

        queue<int> que;
        que.push(target->val);
        vector<bool> vis(520,false);
        vis[target->val] = true;

        while((k--) > 0 && !que.empty())
        {
            int size = que.size();
            for(int i = 0; i < size; i++)
            {
                int f = que.front();
                que.pop();

                for(auto& v : map[f])
                {
                    if(vis[v] == true)  continue;
                    que.push(v);
                    vis[v] = true;
                }
            }
        }

        vector<int> ans;
        while(!que.empty())
        {
            int f = que.front();
            que.pop();

            ans.push_back(f);
        }

        return ans;
    }

    void dfs(unordered_map<int,vector<int> >& map,TreeNode* root,TreeNode* pre)
    {
        if(root == nullptr) return;

        dfs(map,root->left,root);
        if(pre != nullptr)
        {
            map[root->val].push_back(pre->val);
            map[pre->val].push_back(root->val);
        }
        dfs(map,root->right,root);
    }
};
