/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head) return true;
        if(!root) return false;
        if(dfs(head,root)) return true;

        return isSubPath(head,root->left) || isSubPath(head,root->right);
    }

    bool dfs(ListNode* head,TreeNode* root) {
        if(!head) return true;
        if(!root) return false;

        if(head->val != root->val)  return false;

        return dfs(head->next,root->left) || dfs(head->next,root->right);
    }
};

����һ����?root?Ϊ���Ķ�������һ��?head?Ϊ��һ���ڵ������

����ڶ������У�����һ��һֱ���µ�·������ÿ�������ֵǡ��һһ��Ӧ��?head?Ϊ�׵�������ÿ���ڵ��ֵ����ô���㷵�� True �����򷵻� False ��

һֱ���µ�·������˼�ǣ�������ĳ���ڵ㿪ʼ��һֱ�������µ�·����

?

ʾ�� 1��



���룺head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
�����true
���ͣ�������ɫ�Ľڵ㹹�����������Ӧ����·����
ʾ�� 2��



���룺head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
�����true
ʾ�� 3��

���룺head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
�����false
���ͣ��������в�����һһ��Ӧ�����·����
?

��ʾ��

�������������е�ÿ���ڵ��ֵ������?1 <= node.val?<= 100?��
��������Ľڵ���Ŀ��?1?��?100?֮�䡣
�����������Ľڵ���Ŀ��?1?��?2500?֮�䡣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/linked-list-in-binary-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
