���ǴӶ������ĸ��ڵ� root?��ʼ�����������������

�ڱ����е�ÿ���ڵ㴦���������?D?���̻��ߣ�����?D?�Ǹýڵ����ȣ���Ȼ������ýڵ��ֵ��������ڵ�����Ϊ D������ֱ���ӽڵ�����Ϊ D + 1�����ڵ�����Ϊ 0����

����ڵ�ֻ��һ���ӽڵ㣬��ô��֤���ӽڵ�Ϊ���ӽڵ㡣

�����������?S����ԭ������������ڵ�?root��

?

ʾ�� 1��



���룺"1-2--3--4-5--6--7"
�����[1,2,5,3,4,6,7]
ʾ�� 2��



���룺"1-2--3---4-5--6---7"
�����[1,2,5,3,null,6,null,4,null,7]
ʾ�� 3��



���룺"1-401--349---90--88"
�����[1,401,null,349,88,90]
?

��ʾ��

ԭʼ���еĽڵ������� 1 �� 1000 ֮�䡣
ÿ���ڵ��ֵ���� 1 �� 10 ^ 9 ֮�䡣



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
private:
    string str = "";
    int len = 0;
public:
    TreeNode* recoverFromPreorder1(string S) {
        str = S;
        len = S.size();
        int idx = 0;
        return dfs(idx,0);
    }

    TreeNode* dfs(int& idx,int depth)
    {
        if(idx == len)  return nullptr;

        //�ҵ�һ�����֣�����¼�����ֵ����
        int tp = 0;
        while(idx < len && str[idx] == '-')
        {
            idx++;
            tp++;
        }

        //�����ǰ��� tp ������ depth ��������idx���ݵ�֮ǰ��λ��
        if(tp < depth)
        {
            idx -= tp;
            return nullptr;
        }
        
        //��ȡ����
        int num = 0;
        while(idx < len && str[idx] != '-')
            num = num * 10 + str[idx++] - '0';
        
        TreeNode* root = new TreeNode(num);
        root->left = dfs(idx,depth+1);
        root->right = dfs(idx,depth+1);

        return root;
    }

    //�ǵݹ�
    TreeNode* recoverFromPreorder(string s)
    {
        stack<TreeNode*> st;
        len = s.size();
        int idx = 0;

        while(idx < len)
        {
            //�ҵ�һ�����֡����ҵõ��������
            int tp = 0;
            while(idx < len && s[idx] == '-')
            {
                idx++;
                tp++;
            }
            //��ǰ����Ҫ����Ƚڵ�
            int depth = st.size();

            while(depth != tp && !st.empty())
            {
                st.pop();
                depth--;
            }

            //��ȡ�ڵ������
            //��ȡ����
            int num = 0;
            while(idx < len && s[idx] != '-')
                num = num * 10 + s[idx++] - '0';
            
            TreeNode* node = new TreeNode(num);
            if(!st.empty())  
            {
                TreeNode* top = st.top();
                if(top->left == nullptr)    top->left = node;
                else    top->right = node;
            }
            st.push(node);
        }
        TreeNode* root = new TreeNode();
        while(!st.empty())
        {
            root = st.top();
            st.pop();
        }
        return root;
    }
};
