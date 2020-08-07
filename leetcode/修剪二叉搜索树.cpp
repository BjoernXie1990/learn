����һ��������������ͬʱ������С�߽�L?�����߽�?R��ͨ���޼�������������ʹ�����нڵ��ֵ��[L, R]�� (R>=L) ���������Ҫ�ı����ĸ��ڵ㣬���Խ��Ӧ�������޼��õĶ������������µĸ��ڵ㡣

ʾ�� 1:

����: 
    1
   / \
  0   2

  L = 1
  R = 2

���: 
    1
      \
       2
ʾ�� 2:

����: 
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

���: 
      3
     / 
   2   
  /
 1


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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == nullptr) return root;

        if(root->val > R)   return trimBST(root->left,L,R);

        if(root->val < L)   return trimBST(root->right,L,R);

        //���ڵ��ڷ�Χ��
        root->left = trimBST(root->left,L,R);
        root->right = trimBST(root->right,L,R);
        return root;
    }
};
