����һ���������ĸ���㣬�����ҳ����ִ�����������Ԫ�غ͡�һ�����ġ�����Ԫ�غ͡�����Ϊ�Ըý��Ϊ���Ķ����������н���Ԫ��֮�ͣ�������㱾����

����Ҫ���س��ִ�����������Ԫ�غ͡�����ж��Ԫ�س��ֵĴ�����ͬ���������г��ִ�����������Ԫ�غͣ�����˳�򣩡�

?

ʾ�� 1��
����:

  5
 /  \
2   -3
����?[2, -3, 4]�����е�ֵ��ֻ����һ�Σ�������˳�򷵻�����ֵ��

ʾ��?2��
���룺

  5
 /  \
2   -5
����?[2]��ֻ�� 2 �������Σ�-5 ֻ���� 1 �Ρ�

?

��ʾ��?������������Ԫ�غ;������� 32 λ�з���������ʾ��



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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans);
        map<int,int> mp;
        int count = INT_MIN;

        for(auto& eoch : ans)
        {
            mp[eoch]++;
            if(mp[eoch] > count)
                count = mp[eoch];
        }

        vector<int> ret;
        for(auto& eoch : mp)
            if(eoch.second == count)
                ret.push_back(eoch.first);
        return ret;
    }

    int dfs(TreeNode* root,vector<int>& ans)
    {
        if(!root)
            return 0;
        
        int left = dfs(root->left,ans);
        int right = dfs(root->right,ans);
        ans.push_back(left + right + root->val);
        return left + right + root->val;
    }
};
