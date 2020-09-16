����һ�������ظ�Ԫ�ص��������顣һ���Դ����鹹�������������������£�

�������ĸ��������е����Ԫ�ء�
��������ͨ�����������ֵ��߲��ֹ����������������
��������ͨ�����������ֵ�ұ߲��ֹ����������������
ͨ�����������鹹�������������������������ĸ��ڵ㡣

?

ʾ�� ��

���룺[3,2,1,6,0,5]
�������������������ĸ��ڵ㣺

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
?

��ʾ��

����������Ĵ�С�� [1, 1000] ֮�䡣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-binary-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums,0,nums.size()-1);
    }

    TreeNode* dfs(vector<int>& nums,int le,int ri) {
        if(le > ri) return nullptr;
        int idx = le;
        for(int i = idx + 1; i <= ri; i++)  
            if(nums[i] > nums[idx]) idx = i;
        
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = dfs(nums,le,idx-1);
        root->right = dfs(nums,idx+1,ri);
        return root;
    }
};
