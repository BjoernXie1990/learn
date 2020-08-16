����һ���и��ڵ�Ķ��������ҵ��������Ҷ�ڵ������������ȡ�

����һ�£�

Ҷ�ڵ� �Ƕ�������û���ӽڵ�Ľڵ�
���ĸ��ڵ��?���?Ϊ?0�����ĳһ�ڵ�����Ϊ?d���������ӽڵ����Ⱦ���?d+1
������Ǽٶ� A ��һ��ڵ�?S?�� ����������ȣ�S?�е�ÿ���ڵ㶼���� A Ϊ���ڵ�������У��� A?����ȴﵽ�������¿��ܵ����ֵ��
?

ʾ�� 1��

���룺root = [1,2,3]
�����[1,2,3]
���ͣ� 
�����Ҷ����ֵΪ 2 �� 3 �Ľڵ㡣
��ЩҶ�ӵ������ͬ������ֵΪ 1 �Ľڵ㡣
���صĴ�Ϊ���л��� TreeNode ���󣨲������飩"[1,2,3]" ��
ʾ�� 2��

���룺root = [1,2,3,4]
�����[4]
ʾ�� 3��

���룺root = [1,2,3,4,5]
�����[2,4,5]
?

��ʾ��

��������н���?1 �� 1000 ���ڵ㡣
����ÿ���ڵ��ֵ���� 1 �� 1000 ֮�䡣

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
    unordered_map<TreeNode*,int> map_t;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == nullptr) return nullptr;

        int le = depth(root->left);
        int ri = depth(root->right);
        if(le == ri)    return root;

        return le < ri ?  lcaDeepestLeaves(root->right) : lcaDeepestLeaves(root->left);
    }

    int depth(TreeNode* root)
    {
        if(root == nullptr) return 0;
        if(map_t.count(root) > 0)   return map_t[root];

        int le = depth(root->left);
        int ri = depth(root->right);
        return 1 + max(le, ri);
    }
};
