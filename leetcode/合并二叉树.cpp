class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr && t2 == nullptr) return nullptr;
        if((t1 == nullptr) + (t2 == nullptr) == 1) return t1 == nullptr ? t2 : t1;
        TreeNode* root = new TreeNode(0);

        if(t1 != nullptr) root->val += t1->val;
        if(t2 != nullptr) root->val += t2->val;
        root->left = mergeTrees(t1->left,t2->left);
        root->right = mergeTrees(t1->right,t2->right);
        return root;
    }
};


���������������������㽫�����е�һ�����ǵ���һ����ʱ��������������һЩ�ڵ����ص���

����Ҫ�����Ǻϲ�Ϊһ���µĶ��������ϲ��Ĺ�������������ڵ��ص�����ô�����ǵ�ֵ�����Ϊ�ڵ�ϲ������ֵ������Ϊ?NULL �Ľڵ㽫ֱ����Ϊ�¶������Ľڵ㡣

ʾ��?1:

����: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
���: 
�ϲ������:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
ע��:?�ϲ�������������ĸ��ڵ㿪ʼ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/merge-two-binary-trees
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
