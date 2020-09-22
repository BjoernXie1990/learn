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
    int minCameraCover(TreeNode* root) {
        if(root == nullptr) return 0;

        if(dfs(root) == 2) ans++;

        return ans;
    }

    // 0 �ýڵ㰲װ������
    // 1 �ýڵ㱻����
    // 2 �ýڵ�û�б�����
    int dfs(TreeNode* root) {
        if(root == nullptr) return 1;
        int le = dfs(root->left);
        int ri = dfs(root->right);

        if(le == 2 || ri == 2) {    //���ں��ӽڵ�û�б����ӣ��ýڵ�Ӽ�����
            ans++;
            return 0;
        } else if(le == 0 || ri == 0) { //���ӽڵ㰲װ���������ýڵ�Ϊ������״̬
            return 1;
        }

        return 2;
    }
};

����һ�������������������Ľڵ��ϰ�װ����ͷ��

�ڵ��ϵ�ÿ����Ӱͷ�����Լ����丸����������ֱ���Ӷ���

�������������нڵ��������С����ͷ������

?

ʾ�� 1��



���룺[0,0,null,0,0]
�����1
���ͣ���ͼ��ʾ��һ̨����ͷ���Լ�����нڵ㡣
ʾ�� 2��



���룺[0,0,null,0,null,0,null,null,0]
�����2
���ͣ���Ҫ������������ͷ�������������нڵ㡣 ��ͼ��ʾ������ͷ���õ���Чλ��֮һ��

��ʾ��

�������Ľڵ����ķ�Χ��?[1, 1000]��
ÿ���ڵ��ֵ���� 0��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/binary-tree-cameras
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
