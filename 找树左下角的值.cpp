//����һ�������������������һ���ҵ�����ߵ�ֵ��

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
    int findBottomLeftValue(TreeNode* root) {
        int ans = root->val;
        int maxdepth = 1;
        dfs(root,ans,1,maxdepth);
        return ans;
    }

    void dfs(TreeNode* root, int& ans, int depth, int& maxdepth){
        if(!root) return;
        //�����·���һ�����������ȱ���������
        // if(root->left) {
        //     if(depth == maxdepth) {
        //         ans = root->left->val;
        //         maxdepth++;
        //     }
        //     dfs(root->left,ans,depth+1,maxdepth);
        // }

        // if(root->right) {
        //     if(depth == maxdepth) {
        //         ans = root->right->val;
        //         maxdepth++;
        //     }
        //     dfs(root->right,ans,depth+1,maxdepth);
        // }

        if(!root->left && !root->right && depth > maxdepth) {
            maxdepth = depth;
            ans = root->val;
        }
        dfs(root->left,ans,depth+1,maxdepth);
        dfs(root->right,ans,depth+1,maxdepth);
        
    }
};
//��ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ����һ�ö����������ľ���һ������ô���ǶԳƵġ�

//���磬������?[1,2,2,3,4,4,3] �ǶԳƵġ�

//? ? 1
//? ?/ \
//? 2 ? 2
//?/ \ / \
//3 ?4 4 ?3
//�����������?[1,2,2,null,3,null,3] ���Ǿ���ԳƵ�:

//? ? 1
//? ?/ \
//? 2 ? 2
//? ?\ ? \
//? ?3 ? ?3

//?

//ʾ�� 1��

//���룺root = [1,2,2,3,4,4,3]
//�����true
//ʾ�� 2��

//���룺root = [1,2,2,null,3,null,3]
//�����false


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        return Fun(root->left, root->right);
    }

    bool Fun(TreeNode* Treeleft, TreeNode* Treeright) {
        if(!Treeright && !Treeleft) return true;
        if(!Treeleft || !Treeright) return false;

        //�����ڵ㶼�Ƿǿսڵ�
        if(Treeleft->val != Treeright->val) return false;
        return Fun(Treeleft->left, Treeright->right) &&
                Fun(Treeleft->right, Treeright->left);
    }
};
