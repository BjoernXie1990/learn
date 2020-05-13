//����һ����������������ڵ�ֵ�ľ���β�α����������ȴ������ң��ٴ������������һ��������Դ����ƣ������֮�佻����У���

//���磺
//����������?[3,9,20,null,null,15,7],

//    3
//   / \
//  9  20
//    /  \
//   15   7
//���ؾ���β�α������£�

//[
//  [3],
//  [20,9],
//  [15,7]
//]




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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        stack<TreeNode*> st;
        st.push(root);
        vector<vector<int> > ans;

        int ret = 1; //1,0  �������ң�������������״̬
        while(!st.empty())
        {
            int size = st.size();
            stack<TreeNode*> tmp;
            vector<int> t;
            
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = st.top();
                st.pop();

                if(ret&1)//��������
                {
                    if(node->left) tmp.push(node->left);
                    if(node->right) tmp.push(node->right);
                }
                else
                {
                    if(node->right) tmp.push(node->right);
                    if(node->left) tmp.push(node->left);
                }

                t.push_back(node->val);
            }
            ret = !ret;//��һ�δ�������
            ans.push_back(t);
            st=tmp;
        }
        return ans;
    }
};
