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
    using ll = long long;
    ll sum = 0, ans = 0;
    const int mod = 1e9 + 7;

    int maxProduct(TreeNode* root) {
        sum = dfs(root);
        dfs(root);

        return (int)(ans % mod);
    }

    ll dfs(TreeNode* root) {
        if(root == nullptr) return 0;
        ll le = dfs(root->left);
        ll ri = dfs(root->right);
        if(sum != 0) ans = MAX(ans,((sum - le) * le), ((sum - ri) * ri));
        return root->val + le + ri;
    }

    ll MAX(ll a,ll b,ll c) {
        return max(a,max(c,b));
    }
};

����һ�ö����������ĸ�Ϊ?root ������ɾ�� 1 ���ߣ�ʹ���������ѳ����������������������͵ĳ˻������ܴ�

���ڴ𰸿��ܻ�ܴ����㽫����� 10^9 + 7 ȡģ���ٷ��ء�

?

ʾ�� 1��



���룺root = [1,2,3,4,5,6]
�����110
���ͣ�ɾ����ɫ�ıߣ��õ� 2 ���������ͷֱ�Ϊ 11 �� 10 �����ǵĳ˻��� 110 ��11*10��
ʾ�� 2��



���룺root = [1,null,2,3,4,null,null,5,6]
�����90
���ͣ��Ƴ���ɫ�ıߣ��õ� 2 ���������ͷֱ��� 15 �� 6 �����ǵĳ˻�Ϊ 90 ��15*6��
ʾ�� 3��

���룺root = [2,3,9,10,7,8,6,5,4,11,1]
�����1025
ʾ�� 4��

���룺root = [1,1]
�����1
?

��ʾ��

ÿ���������?50000?���ڵ㣬��������?2?���ڵ㡣
ÿ���ڵ��ֵ��?[1, 10000]?֮�䡣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-product-of-splitted-binary-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
