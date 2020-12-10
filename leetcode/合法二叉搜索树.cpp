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
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        if(isValidBST(root->left) == false) return false;

        if(pre == nullptr) pre = root;
        else {
            if(pre->val >= root->val) return false;
            pre = root;
        }
       
        if(!isValidBST(root->right)) return false;

        return true;
    }
};


ʵ��һ�����������һ�ö������Ƿ�Ϊ������������

ʾ��?1:
����:
    2
   / \
  1   3
���: true
ʾ��?2:
����:
    5
   / \
  1   4
?    / \
?   3   6
���: false
����: ����Ϊ: [5,1,4,null,null,3,6]��
?    ���ڵ��ֵΪ 5 �����������ӽڵ�ֵΪ 4 ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/legal-binary-search-tree-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
