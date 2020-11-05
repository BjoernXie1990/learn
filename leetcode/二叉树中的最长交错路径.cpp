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
    int ans = 0;
    int longestZigZag(TreeNode* root) {
        dfs(root,0,0);

        return ans;
    }

    // root�ĸ��׽ڵ㣬������������root�ĳ���Ϊ l ,������������root�ĳ���Ϊr
    void dfs(TreeNode* root,int l,int r) {
        if(root == nullptr) {
            ans = max(ans,max(l,r) - 1);    // -1 ��ȥ��ʱ�����ָ��
            return ;
        }

        dfs(root->left,r + 1, 0);
        dfs(root->right,0,l + 1);
    }
};


����һ����?root?Ϊ���Ķ��������������еĽ���·���������£�

ѡ��������� ����?�ڵ��һ������������ң���
���ǰ������Ϊ�ң���ô�ƶ�����ǰ�ڵ�ĵ����ӽڵ㣬�����ƶ����������ӽڵ㡣
�ı�ǰ����������һ����ұ���
�ظ��ڶ����͵�������ֱ�����������޷������ƶ���
����·���ĳ��ȶ���Ϊ�����ʹ��Ľڵ���Ŀ - 1�������ڵ��·������Ϊ 0 ����

���㷵�ظ�������� ����·��?�ĳ��ȡ�

?

ʾ�� 1��



���룺root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
�����3
���ͣ���ɫ�ڵ�Ϊ���������·������ -> �� -> �ң���
ʾ�� 2��



���룺root = [1,1,1,null,1,null,null,1,1,null,1]
�����4
���ͣ���ɫ�ڵ�Ϊ���������·������ -> �� -> �� -> �ң���
ʾ�� 3��

���룺root = [1]
�����0
?

��ʾ��

ÿ���������?50000?���ڵ㡣
ÿ���ڵ��ֵ��?[1, 100] ֮�䡣
ͨ������4,582�ύ����9,272

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-zigzag-path-in-a-binary-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
