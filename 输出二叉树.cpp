��һ�� m*n �Ķ�ά�ַ�����������������������������¹���

����?m?Ӧ�����ڸ����������ĸ߶ȡ�
����?n?Ӧ������������
���ڵ��ֵ�����ַ�����ʽ������Ӧ�����ڿɷ��õĵ�һ�����м䡣���ڵ����ڵ������лὫʣ��ռ仮��Ϊ�����֣����²��ֺ����²��֣�����Ӧ�ý���������������²��֣���������������²��֡����º����²���Ӧ������ͬ�Ĵ�С����ʹһ������Ϊ�ն���һ���ǿգ��㲻��ҪΪ�յ���������κζ�����������ҪΪ��һ�����������㹻�Ŀռ䡣Ȼ�����������������Ϊ������ҪΪ���������κοռ䡣
ÿ��δʹ�õĿռ�Ӧ����һ���յ��ַ���""��
ʹ����ͬ�Ĺ������������
ʾ�� 1:

����:
     1
    /
   2
���:
[["", "1", ""],
 ["2", "", ""]]
ʾ�� 2:

����:
     1
    / \
   2   3
    \
     4
���:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
ʾ�� 3:

����:
      1
     / \
    2   5
   / 
  3 
 / 
4 
���:
[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
ע��: �������ĸ߶��ڷ�Χ [1, 10] �С�


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
    int col;
    int height;
    vector<vector<string>> printTree(TreeNode* root) {
        height = GetHeight(root);
        if(height == 0) return {};
        col = (1 << height) - 1;
   
        vector<vector<string> > ans(height,vector<string> (col,""));
        
        dfs(ans,root,0,col/2);
        return ans;
    }

    void dfs(vector<vector<string> >& ans,TreeNode* root,int cur,int cnt)
    {
        if(!root) return;

        ans[cur][cnt] = to_string(root->val);
        //int nextlen = 1<<(height-1 - (cur + 1));
        //��ֹ���� (height-cur-2) Ϊ���������
        if(!root->left && !root->right) return;
        int nextlen = 1<<(height-cur-2);
        dfs(ans,root->left,cur+1,cnt-nextlen);

        dfs(ans,root->right,cur+1,cnt+nextlen);
    }


    int GetHeight(TreeNode* root)
    {
        if(!root) return 0;

        return 1 + max(GetHeight(root->left),
                    GetHeight(root->right));
    }

};
