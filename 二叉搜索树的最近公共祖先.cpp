//����һ������������, �ҵ�����������ָ���ڵ������������ȡ�

//�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����

//���磬�������¶���������:? root =?[6,2,8,0,4,7,9,null,null,3,5]



//?

//ʾ�� 1:

//����: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
//���: 6 
//����: �ڵ� 2 �ͽڵ� 8 ��������������� 6��
//ʾ�� 2:

//����: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
//���: 2
//����: �ڵ� 2 �ͽڵ� 4 ��������������� 2, ��Ϊ���ݶ�������������Ƚڵ����Ϊ�ڵ㱾��
//?

//˵��:

//���нڵ��ֵ����Ψһ�ġ�
//p��q Ϊ��ͬ�ڵ��Ҿ������ڸ����Ķ����������С�



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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        //���p,q�����ߣ���ôroot������С����
        if(root->val >= p->val && root->val <= q->val ||
            root->val >= q->val && root->val <= p->val)
            return root;

        //qp ���������������߶���������
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left && right) return root;

        return left ? left : right; 
    }
};
