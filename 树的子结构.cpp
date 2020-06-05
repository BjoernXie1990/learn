�������ö�����A��B���ж�B�ǲ���A���ӽṹ��(Լ��������������һ�������ӽṹ)

B��A���ӽṹ�� �� A���г��ֺ�B��ͬ�Ľṹ�ͽڵ�ֵ��

����:
�������� A:

? ? ?3
? ? / \
? ?4 ? 5
? / \
?1 ? 2
�������� B��

? ?4?
? /
?1
���� true����Ϊ B �� A ��һ������ӵ����ͬ�Ľṹ�ͽڵ�ֵ��

ʾ�� 1��

���룺A = [1,2,3], B = [3,1]
�����false
ʾ�� 2��

���룺A = [3,4,5,1,2], B = [4,1]
�����true
���ƣ�

0 <= �ڵ���� <= 10000


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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B) return false;
        if(!A) return false;
        return isSame(A,B) ||
            isSubStructure(A->left,B) ||
            isSubStructure(A->right,B);
    }


    bool isSame(TreeNode* l,TreeNode* r)
    {
        if(!r) return true;

        if(!l) return false;

        if(l->val != r->val) return false;

        return isSame(l->left,r->left) && isSame(l->right,r->right);
    }
};
