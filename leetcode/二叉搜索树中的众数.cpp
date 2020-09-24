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
    vector<int> ans;
    vector<int> findMode(TreeNode* root) {
        if(root == nullptr) return ans;

        TreeNode* pre = nullptr;
        int curN = 1;
        int maxN = 0;
        dfs(root,pre,curN,maxN);
        return ans;
    }

    void dfs(TreeNode* root,TreeNode*& pre,int& curN,int& maxN) {
        if(root == nullptr) return ;

        dfs(root->left,pre,curN,maxN);
        if(pre != nullptr) curN = (root->val == pre->val) ? curN+1 : 1;

        if(curN == maxN) {
            ans.push_back(root->val);
        } else if(curN > maxN) {
            ans.clear();
            maxN = curN;
            ans.push_back(root->val);
        }

        pre = root;
        dfs(root->right,pre,curN,maxN);
    }
};

����һ������ֵͬ�Ķ�����������BST�����ҳ� BST �е���������������Ƶ����ߵ�Ԫ�أ���

�ٶ� BST �����¶��壺

�������������������ֵС�ڵ��ڵ�ǰ����ֵ
�������������������ֵ���ڵ��ڵ�ǰ����ֵ
�����������������Ƕ���������
���磺
���� BST [1,null,2,2],

   1
    \
     2
    /
   2
����[2].

��ʾ�������������1�������迼�����˳��

���ף�����Բ�ʹ�ö���Ŀռ��𣿣������ɵݹ��������ʽ����ջ�Ŀ��������������ڣ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-mode-in-binary-search-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
