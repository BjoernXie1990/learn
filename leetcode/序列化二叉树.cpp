/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        int id = 0;
        return dfs(data,id);
    }

private:
    TreeNode* dfs(string& data,int& le) {
        if(data[le] == '#') {
            le++;
            return nullptr;
        }
        int val = 0;
        int flag = 1;
        if(data[le] == '-') {
            flag = -1;
            le++;
        }
        while(data[le] != ',') val = val * 10 + (data[le++]-'0');
        le++;
        val *= flag;

        
        TreeNode* root = new TreeNode(val);
        root->left = dfs(data,le);
        root->right = dfs(data,le);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

��ʵ�������������ֱ��������л��ͷ����л���������

ʾ��:?

����Խ����¶�������

    1
   / \
  2   3
     / \
    4   5

���л�Ϊ "[1,2,3,null,null,4,5]"

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
