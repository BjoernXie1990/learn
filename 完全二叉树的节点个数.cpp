
����һ����ȫ����������������Ľڵ������

˵����

��ȫ�������Ķ������£�����ȫ�������У�������ײ�ڵ����û�����⣬����ÿ��ڵ������ﵽ���ֵ������������һ��Ľڵ㶼�����ڸò�����ߵ�����λ�á�����ײ�Ϊ�� h �㣬��ò���� 1~?2h?���ڵ㡣

ʾ��:

����: 
    1
   / \
  2   3
 / \  /
4  5 6

���: 6

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
    int countNodes1(TreeNode* root) {
        if(root == nullptr) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    int countNodes(TreeNode* root)
    {
        TreeNode* cur = root;
        int h = GetDepth(root);
        int num = 0;//���һ��Ľڵ���
        int lev = 1;

        while(cur)
        {
            TreeNode* tmp = cur->right;
            if(tmp && lev + GetDepth(tmp) == h)
            {
                cur = cur->right;
                num += pow(2,h-lev-1);
            }
            else
            {
                cur = cur->left;
            }
            lev++;
        }
        return num + pow(2,h-1);
    }

    int GetDepth(TreeNode* root)
    {
        int ans = 0;
        while(root != nullptr)
        {
            root = root->left;
            ans++;
        }
        return ans;
    }
};
