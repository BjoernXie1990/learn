��һ�������������е��������飬ת��Ϊһ�ø߶�ƽ�������������

�����У�һ���߶�ƽ���������ָһ��������ÿ���ڵ�?���������������ĸ߶Ȳ�ľ���ֵ������ 1��

ʾ��:

������������: [-10,-3,0,5,9],

һ�����ܵĴ��ǣ�[0,-3,9,-10,null,5]�������Ա�ʾ��������߶�ƽ�������������

      0
     / \
   -3   9
   /   /
 -10  5


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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BinarySlove(nums,0,nums.size()-1);
    }

    TreeNode* BinarySlove(vector<int>& nums,int le,int ri)
    {
        if(le > ri) return nullptr;

        int mid = le + (ri - le) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = BinarySlove(nums,le,mid-1);
        root->right = BinarySlove(nums,mid+1,ri);
        return root;
    }
};
