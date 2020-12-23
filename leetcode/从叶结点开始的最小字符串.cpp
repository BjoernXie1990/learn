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
    string ans = "";
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        return ans;
    }

    void dfs(TreeNode* root,string s) {
        if(!root) return;
        s += (char)(root->val + 'a');
        if(!root->left && !root->right) {
            reverse(s.begin(),s.end());
            if(ans > s || ans == "") 
                ans = s;
            
            return;
        }

        dfs(root->left,s);
        dfs(root->right,s);
    }
};


����һ�Ÿ����Ϊ?root?�Ķ����������е�ÿһ����㶼��һ����?0 ��?25?��ֵ���ֱ������ĸ?'a' ��?'z'��ֵ?0 ����?'a'��ֵ?1?����?'b'���������ơ�

�ҳ����ֵ�����С���ַ��������ַ������������һ��Ҷ��㿪ʼ��������������

��С��ʿ���ַ������κν϶̵�ǰ׺���ֵ����϶��ǽ�С�ģ����磬���ֵ�����?"ab" ��?"aba"?ҪС��Ҷ�����ָû���ӽ��Ľ�㡣��

?

ʾ�� 1��



���룺[0,1,2,3,4,3,4]
�����"dba"
ʾ�� 2��



���룺[25,1,3,1,3,0,2]
�����"adz"
ʾ�� 3��



���룺[2,2,1,null,1,0,null,0]
�����"abc"
?

��ʾ��

�������Ľ��������?1 ��?8500?֮�䡣
���е�ÿ����㶼��һ������?0?��?25?֮���ֵ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/smallest-string-starting-from-leaf
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
