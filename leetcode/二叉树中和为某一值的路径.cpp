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
    vector<vector<int> > ans;
    vector<int> tmp;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root,sum);
        return ans;
    }

    void dfs(TreeNode* root,int sum) {
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) {
            if(sum == root->val) {
                tmp.push_back(root->val);
                ans.push_back(tmp);
                tmp.pop_back();
            }
            return ;
        }

        tmp.push_back(root->val);
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
        tmp.pop_back();
    }
};

����һ�ö�������һ����������ӡ���������нڵ�ֵ�ĺ�Ϊ��������������·���������ĸ��ڵ㿪ʼ����һֱ��Ҷ�ڵ��������Ľڵ��γ�һ��·����

?

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

[
   [5,4,11,2],
   [5,8,4,5]
]
?

��ʾ��

�ڵ����� <= 10000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
