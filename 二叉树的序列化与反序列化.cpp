���л��ǽ�һ�����ݽṹ���߶���ת��Ϊ�����ı���λ�Ĳ������������Խ�ת��������ݴ洢��һ���ļ������ڴ��У�ͬʱҲ����ͨ�����紫�䵽��һ���������������ȡ�෴��ʽ�ع��õ�ԭ���ݡ�

�����һ���㷨��ʵ�ֶ����������л��뷴���л������ﲻ�޶�������� / �����л��㷨ִ���߼�����ֻ��Ҫ��֤һ�����������Ա����л�Ϊһ���ַ������ҽ�����ַ��������л�Ϊԭʼ�����ṹ��

ʾ��:?

����Խ����¶�������

    1
   / \
  2   3
     / \
    4   5

���л�Ϊ "[1,2,3,null,null,4,5]"
��ʾ:?���� LeetCode Ŀǰʹ�õķ�ʽһ�£����������?LeetCode ���л��������ĸ�ʽ���㲢�Ǳ����ȡ���ַ�ʽ����Ҳ���Բ��������ķ������������⡣

˵��:?��Ҫʹ����ĳ�Ա / ȫ�� / ��̬�������洢״̬��������л��ͷ����л��㷨Ӧ������״̬�ġ�



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
       if(!root)    return "X";
       string le = "(" + serialize(root->left) + ")";
       string ri = "(" + serialize(root->right) + ")";
       return le + to_string(root->val) + ri;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int ptr = 0;
        return check(data,ptr);
    }

    TreeNode* check(string& data,int& ptr)
    {
        //cout<<data<<endl;
        if(data[ptr] == 'X')
        {
            ptr++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(0);
        root->left = SubTree(data,ptr);
        root->val = SToInt(data,ptr);
        root->right = SubTree(data,ptr);
        return root;
    }

    inline TreeNode* SubTree(string& data,int& ptr)
    {
        ptr++;// (
        TreeNode* root = check(data,ptr);
        ptr++;// )
        return root;
    }

    inline int SToInt(string& data,int& ptr)
    {
        int num = 0;
        int sgn = 1;
        if(data[ptr] == '-')
        {
            sgn = -1;
            ptr++;
        }
        while(isdigit(data[ptr]))
            num = num*10 + data[ptr++] - '0';
        return num * sgn;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
