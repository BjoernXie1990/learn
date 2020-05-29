//���ϴδ����һ���ֵ�֮���һȦ���ݺ�С͵�ַ�����һ���µĿ����Եĵ������������ֻ��һ����ڣ����ǳ�֮Ϊ�������� ���ˡ�����֮�⣬ÿ����������ֻ��һ��������������֮������һ�����֮�󣬴�����С͵��ʶ��������ط������з��ݵ�����������һ�ö��������� �������ֱ�������ķ�����ͬһ�����ϱ���٣����ݽ��Զ�������

//�����ڲ���������������£�С͵һ���ܹ���ȡ����߽�

//ʾ�� 1:

//����: [3,2,3,null,3,null,1]

//     3
//    / \
//   2   3
//    \   \ 
//     3   1

//���: 7 
//����:?С͵һ���ܹ���ȡ����߽�� = 3 + 3 + 1 = 7.
//ʾ�� 2:

//����: [3,4,5,1,3,null,1]

//?    3
//    / \
//   4   5
//  / \   \ 
// 1   3   1

//���: 9
//����:?С͵һ���ܹ���ȡ����߽��?= 4 + 5 = 9.

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
    int rob(TreeNode* root) {
        vector<int> ret = dfs(root);
        return max(ret[0],ret[1]);
    }

    vector<int> dfs(TreeNode* root)
    {
        vector<int> cur(2,0);
        if(!root) return cur;
        
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        //͵��ǰ�ĸ��ڵ�
        cur[1] = root->val + left[0] + right[0];
        //��͵��ǰλ��
        cur[0] = max(left[1],left[0]) + max(right[0],right[1]);
        return cur;
    }
};
