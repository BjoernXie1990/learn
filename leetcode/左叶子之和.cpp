���������������������Ҷ��֮�͡�

ʾ����

    3
   / \
  9  20
    /  \
   15   7

������������У���������Ҷ�ӣ��ֱ��� 9 �� 15�����Է��� 24

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sum-of-left-leaves
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;

        int res = 0;
        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
            res += root->left->val;

        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + res;
    }
};
