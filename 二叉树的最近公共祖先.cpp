//����һ��������, �ҵ�����������ָ���ڵ������������ȡ�

//�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����

//���磬�������¶�����:? root =?[3,5,1,6,2,0,8,null,null,7,4]



//?

//ʾ�� 1:

//����: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
//���: 3
//����: �ڵ� 5 �ͽڵ� 1 ��������������ǽڵ� 3��
//ʾ��?2:

//����: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
//���: 5
//����: �ڵ� 5 �ͽڵ� 4 ��������������ǽڵ� 5����Ϊ���ݶ�������������Ƚڵ����Ϊ�ڵ㱾��
//?

//˵��:

//���нڵ��ֵ����Ψһ�ġ�
//p��q Ϊ��ͬ�ڵ��Ҿ������ڸ����Ķ������С�

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
    //�������
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        //���ڵ�ΪNULL
        if(!root) return NULL;

        //���ڵ����p q�е�һ��
        if(root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        //���p,q�ڸ��ڵ����������
        if(left && right) return root;

        //���ҽڵ� һ��һ��  ���߶���NULL��ô���ҵ�
        return left ? left:right;
    }

    //��ϣ�洢
    unordered_map<int, TreeNode*> before;
    unordered_map<int, bool> visit;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        before[root->val] = NULL;
        dfs(root);

        while(p)
        {
            visit[p->val] = true;
            p = before[p->val];
        }

        while(q)
        {
            if(visit[q->val]) return q;
            q = before[q->val];
        }

        return NULL;
    }  

    void dfs(TreeNode* root)
    {
        if(!root) return;

        if(root->left)
        {
            before[root->left->val] = root;
            dfs(root->left);
        }

        if(root->right)
        {
            before[root->right->val] = root;
            dfs(root->right);
        }
    }
};
