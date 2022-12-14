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
    unordered_map<TreeNode*,int> mp;
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(fun(root->left) - fun(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int fun(TreeNode* root) {
        if(!root) return 0;
        if(mp.count(root)) return mp[root];

        int le = 0, ri = 0;
        le = fun(root->left);
        ri = fun(root->right);
        int res = max(le,ri) + 1;
        mp[root] = res;
        return res;
    }
};


输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

?

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回?false 。

?

限制：

1 <= 树的结点个数 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
