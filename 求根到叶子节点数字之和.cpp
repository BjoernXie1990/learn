����һ��������������ÿ����㶼���һ��?0-9?�����֣�ÿ���Ӹ���Ҷ�ӽڵ��·��������һ�����֡�

���磬�Ӹ���Ҷ�ӽڵ�·�� 1->2->3 �������� 123��

����Ӹ���Ҷ�ӽڵ����ɵ���������֮�͡�

˵��:?Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ�� 1:

����: [1,2,3]
    1
   / \
  2   3
���: 25
����:
�Ӹ���Ҷ�ӽڵ�·�� 1->2 �������� 12.
�Ӹ���Ҷ�ӽڵ�·�� 1->3 �������� 13.
��ˣ������ܺ� = 12 + 13 = 25.
ʾ�� 2:

����: [4,9,0,5,1]
    4
   / \
  9   0
?/ \
5   1
���: 1026
����:
�Ӹ���Ҷ�ӽڵ�·�� 4->9->5 �������� 495.
�Ӹ���Ҷ�ӽڵ�·�� 4->9->1 �������� 491.
�Ӹ���Ҷ�ӽڵ�·�� 4->0 �������� 40.
��ˣ������ܺ� = 495 + 491 + 40 = 1026.


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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root,ans,0);
        return ans;
    }

    void dfs(TreeNode* root,int& ans,int num)
    {
        if(root == nullptr)
            return;
        
        num = num * 10 + root->val;
        //�Ƿ�ΪҶ�ӽڵ�
        if(!root->left && !root->right)
        {
            ans += num;
            return;
        }

        dfs(root->left,ans,num);
        dfs(root->right,ans,num);

    }
};
