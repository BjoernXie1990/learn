//700. �����������е�����
//����������������BST���ĸ��ڵ��һ��ֵ�� ����Ҫ��BST���ҵ��ڵ�ֵ���ڸ���ֵ�Ľڵ㡣 �����Ըýڵ�Ϊ���������� ����ڵ㲻���ڣ��򷵻� NULL��

//���磬

//��������������:

//        4
//       / \
//      2   7
//     / \
//    1   3

//��ֵ: 2
//��Ӧ�÷�����������:

//      2     
//     / \   
//    1   3
//������ʾ���У����Ҫ�ҵ�ֵ�� 5������Ϊû�нڵ�ֵΪ 5������Ӧ�÷��� NULL��

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* searchBST(struct TreeNode* root, int val){
    if(!root)
        return NULL;
    
    if(root->val == val)
        return root;
    else if(root->val < val)//���ڵ�ֵС��Val,��˵�����������������
        return searchBST(root->right,val);
    //���ڵ�ֵ������Val,��˵�����������������
    return searchBST(root->left,val);
}
