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
    int ans = 0;
    int countPairs(TreeNode* root, int distance) {
        dfs(root,distance);
        return ans;
    }

    vector<int> dfs(TreeNode* root, int d) {
        vector<int> ret;
        if(root == nullptr) return ret;
        if(!root->left && !root->right) return {0};

        // left
        vector<int> le = dfs(root->left,d);
        for(auto& e : le) {
            if(++e > d) continue;
            ret.push_back(e);
        }

        // right
        vector<int> ri = dfs(root->right,d);
        for(auto& e : ri) {
            if(++e > d) continue;
            ret.push_back(e);
        }

        // merge
        for(auto& e : le) 
            for(auto& eo : ri)
                if(e + eo <= d) ans++;
        return ret;
    }
};

����������ĸ��ڵ� root ��һ������ distance ��

��������������� Ҷ �ڵ�֮��� ���·������ С�ڻ��ߵ��� distance �������ǾͿ��Թ���һ�� ��Ҷ�ӽڵ�� ��

�������� ��Ҷ�ӽڵ�Ե����� ��

?

ʾ�� 1��

?



���룺root = [1,2,3,null,4], distance = 3
�����1
���ͣ�����Ҷ�ڵ��� 3 �� 4 ������֮������·���ĳ����� 3 ������Ψһ�ĺ�Ҷ�ӽڵ�ԡ�
ʾ�� 2��



���룺root = [1,2,3,4,5,6,7], distance = 3
�����2
���ͣ���Ҷ�ӽڵ��Ϊ [4,5] �� [6,7] �����·�����ȶ��� 2 ������Ҷ�ӽڵ�� [4,6] ������Ҫ����Ϊ����֮������·������Ϊ 4 ��
ʾ�� 3��

���룺root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
�����1
���ͣ�Ψһ�ĺ�Ҷ�ӽڵ���� [2,5] ��
ʾ�� 4��

���룺root = [100], distance = 1
�����0
ʾ�� 5��

���룺root = [1,1,1], distance = 2
�����1
?

��ʾ��

tree �Ľڵ����� [1, 2^10] ��Χ�ڡ�
ÿ���ڵ��ֵ���� [1, 100] ֮�䡣
1 <= distance <= 10

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/number-of-good-leaf-nodes-pairs
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
