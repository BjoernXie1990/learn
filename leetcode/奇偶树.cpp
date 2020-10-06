/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root == nullptr) return true;
        
        vector<TreeNode*> que;
        que.push_back(root);
        
        int cnt = 0;
        while(que.empty() == false) {
            int size = que.size();
            if(check(que,cnt) == false) return false;
            cnt++;
            
            vector<TreeNode*> tmp;
            for(int i = 0; i < size; i++) {
                TreeNode* f = que[i];
                if(f->left != nullptr) tmp.push_back(f->left);
                if(f->right != nullptr) tmp.push_back(f->right);
            }
            que = tmp;
        }
        
        return true;
    }
    
    bool check(vector<TreeNode*>& que,int cnt) {
        // ji ou
        int n = que.size();
        for(int i = 0; i < n; i++) if(que[i]->val%2 == cnt%2) return false;
        
        // di zeng 
        if(cnt%2 == 0) {
            for(int i = 1; i < n; i++) if(que[i]->val <= que[i-1]->val) return false;
        } else {
            for(int i = 1; i < n; i++) if(que[i]->val >= que[i-1]->val) return false;
        }
        return true;
    }
};

���һ�ö���������������������������Գ�Ϊ ��ż�� ��

���������ڵ����ڲ��±�Ϊ 0 �������ӽڵ����ڲ��±�Ϊ 1 ��������ڵ����ڲ��±�Ϊ 2 ���������ơ�
ż���±� ���ϵ����нڵ��ֵ���� �� �����������Ұ�˳�� �ϸ����
�����±� ���ϵ����нڵ��ֵ���� ż �����������Ұ�˳�� �ϸ�ݼ�
����������ĸ��ڵ㣬���������Ϊ ��ż�� ���򷵻� true �����򷵻� false ��

?

ʾ�� 1��



���룺root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
�����true
���ͣ�ÿһ��Ľڵ�ֵ�ֱ��ǣ�
0 �㣺[1]
1 �㣺[10,4]
2 �㣺[3,7,9]
3 �㣺[12,8,6,2]
���� 0 ��� 2 ���ϵĽڵ�ֵ�����������ϸ�������� 1 ��� 3 ���ϵĽڵ�ֵ����ż�����ϸ�ݼ����������һ����ż����
ʾ�� 2��



���룺root = [5,4,2,3,3,7]
�����false
���ͣ�ÿһ��Ľڵ�ֵ�ֱ��ǣ�
0 �㣺[5]
1 �㣺[4,2]
2 �㣺[3,3,7]
2 ���ϵĽڵ�ֵ�������ϸ�����������������ⲻ��һ����ż����
ʾ�� 3��



���룺root = [5,9,1,3,5,7]
�����false
���ͣ�1 ���ϵĽڵ�ֵӦΪż����
ʾ�� 4��

���룺root = [1]
�����true
ʾ�� 5��

���룺root = [11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]
�����true
?

��ʾ��

���нڵ����ڷ�Χ [1, 105] ��
1 <= Node.val <= 106

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/even-odd-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
