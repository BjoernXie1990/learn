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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(root == nullptr) return node;
        TreeNode* cur = root;
        TreeNode* parent = nullptr;
        while(cur != nullptr) {
            parent = cur;
            if(val > cur->val) cur = cur->right;
            else if(val < cur->val) cur = cur->left;
            else if(val == cur->val) return root;
        }

        
        
        if(val > parent->val) parent->right = node;
        else if(val < parent->val) parent->left = node;

        return root; 
    }
};

����������������BST���ĸ��ڵ��Ҫ�������е�ֵ����ֵ��������������� ���ز��������������ĸ��ڵ㡣 �������ݱ�֤����ֵ��ԭʼ�����������е�����ڵ�ֵ����ͬ��

ע�⣬���ܴ��ڶ�����Ч�Ĳ��뷽ʽ��ֻҪ���ڲ�����Ա���Ϊ�������������ɡ� ����Է���������Ч�Ľ����

?

����,?

��������������:

        4
       / \
      2   7
     / \
    1   3

�� �����ֵ: 5
����Է����������������:

         4
       /   \
      2     7
     / \   /
    1   3 5
���������Ҳ����Ч��:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4
?

��ʾ��

���������ϵĽڵ������� 0 �� 10^4 ֮��
ÿ���ڵ㶼��һ��Ψһ����ֵ��ȡֵ��Χ�� 0 �� 10^8
-10^8 <= val <= 10^8
��ֵ��ԭʼ�����������е�����ڵ�ֵ����ͬ

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/insert-into-a-binary-search-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
