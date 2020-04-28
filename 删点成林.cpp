//�����������ĸ��ڵ�?root������ÿ���ڵ㶼��һ����ͬ��ֵ��

//����ڵ�ֵ��?to_delete?�г��֣����ǾͰѸýڵ������ɾȥ�����õ�һ��ɭ�֣�һЩ���ཻ�������ɵļ��ϣ���

//����ɭ���е�ÿ����������԰�����˳����֯�𰸡�

//?

//ʾ����



//���룺root = [1,2,3,4,5,6,7], to_delete = [3,5]
//�����[[1,2,null,4],[6],[7]]
//?

//��ʾ��

//���еĽڵ������Ϊ?1000��
//ÿ���ڵ㶼��һ������?1 ��?1000?֮���ֵ���Ҹ�����ͬ��
//to_delete.length <= 1000
//to_delete ����һЩ��?1 ��?1000��������ͬ��ֵ��


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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        dfs(ans,root,to_delete,1);
        return ans;
    }

    void dfs(vector<TreeNode*>& ans, TreeNode*& root, vector<int>& to_delete,int is_add) {
        if(!root) return;

        vector<int>::iterator ret = find(to_delete.begin(),to_delete.end(),root->val);
        if(ret != to_delete.end()) {//��ǰ�ڵ���Ҫɾ�������ĺ��ӽڵ���Ҫ����
            dfs(ans,root->left,to_delete,1);
            dfs(ans,root->right,to_delete,1);
            root = NULL;
        }
        else {//��ǰ�ڵ㲻��Ҫɾ��,��ô���ĺ��ӽڵ�Ͳ���Ҫ����
            dfs(ans,root->left,to_delete,0);
            dfs(ans,root->right,to_delete,0);
            if(is_add) ans.push_back(root);
        }
    }
};
