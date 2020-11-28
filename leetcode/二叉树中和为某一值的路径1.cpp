/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> t;
    vector<vector<int> > FindPath(TreeNode* root,int e) {
        if(!root) return ans;
        
        dfs(root,e);
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    void dfs(TreeNode* root, int e) {
        if(root == nullptr) return ;
        e -= root->val;
        t.push_back(root->val);
        if(!root->left && !root->right) {
            if(e == 0) ans.push_back(t);
            t.pop_back();
            return ;
        }
        
        dfs(root->left,e);
        dfs(root->right,e);
        t.pop_back();
    }
};

����һ�Ŷ������ĸ��ڵ��һ�����������ֵ����ӡ���������н��ֵ�ĺ�Ϊ��������������·����·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
