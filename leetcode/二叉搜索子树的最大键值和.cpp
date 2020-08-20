����һ����?root?Ϊ����?������?�����㷵�� ����?������������������ֵ�͡�

�����������Ķ������£�

����ڵ���������еļ�ֵ��?С��?�˽ڵ�ļ�ֵ��
����ڵ���������еļ�ֵ�� ����?�˽ڵ�ļ�ֵ��
����ڵ�������������������Ƕ�����������
?

ʾ�� 1��



���룺root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
�����20
���ͣ���ֵΪ 3 �������Ǻ����Ķ�����������
ʾ�� 2��



���룺root = [4,3,null,1,2]
�����2
���ͣ���ֵΪ 2 �ĵ��ڵ������Ǻ����Ķ�����������
ʾ�� 3��

���룺root = [-4,-2,-5]
�����0
���ͣ����нڵ��ֵ��Ϊ�����������Ķ���������Ϊ�ա�
ʾ�� 4��

���룺root = [2,1,3]
�����6
ʾ�� 5��

���룺root = [5,4,8,3,null,6,3]
�����7
?

��ʾ��

ÿ���������?40000?���ڵ㡣
ÿ���ڵ�ļ�ֵ��?[-4 * 10^4?, 4 * 10^4] ֮�䡣


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct node 
    {
        int _val;
        bool _isBST;
        int _minVal;
        int _maxVal;

        node(int val,int minVal,int maxVal,bool isBST)
            :_val(val),_minVal(minVal),_maxVal(maxVal),_isBST(isBST)
            {}
    };

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        dfs(root,ans);
        return ans;
    }

    node dfs(TreeNode* root,int& ans)
    {
        if(root == nullptr)
            return node(0,INT_MAX,INT_MIN,true);
        node left = dfs(root->left,ans);
        node right = dfs(root->right,ans);

        bool isBST = left._isBST && right._isBST && (root->val > left._maxVal) && (root->val < right._minVal);
        if(isBST == false)
            return node(0,INT_MAX,INT_MIN,false);
        
        //��ǰ�ڵ��Ƕ���������
        int sum = root->val + left._val + right._val;
        ans = max(sum,ans);
        return node(sum,min(root->val,left._minVal),max(root->val,right._maxVal),true);
    }
};
