/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        queue<TreeNode*> que;
        que.push(tree);

        vector<ListNode*> ans;
        if(tree == nullptr) return ans;
        ListNode* head = new ListNode(-1);
        while(!que.empty()) {
            int size = que.size();
            head->next = nullptr;
            ListNode* cur = head;

            while(size --) {
                TreeNode* f = que.front();
                que.pop();

                if(f->left) que.push(f->left);
                if(f->right) que.push(f->right);
                ListNode* t = new ListNode(f->val);
                cur->next = t;
                cur = cur->next;
            }
            ans.push_back(head->next);
        }

        return ans;
    }
};

����һ�ö����������һ���㷨����������ĳһ��������нڵ���������磬��һ���������Ϊ D����ᴴ���� D ������������һ������������ȵ���������顣

?

ʾ����

���룺[1,2,3,4,5,null,7,8]

        1
       /  \ 
      2    3
     / \    \ 
    4   5    7
   /
  8

�����[[1],[2,3],[4,5,7],[8]]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/list-of-depth-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
