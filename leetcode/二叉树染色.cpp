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
    int maxValue(TreeNode* root, int k) {
        vector<int> f = dfs(root,k);
        int res = 0;
        for(int i = 0 ; i <= k; i ++)
            res = max(res,f[i]);
        
        return res;
    }

private:
    vector<int> dfs(TreeNode* root,int k) {
        vector<int> res(k + 1);
        if(root == nullptr)
            return res;
        
        vector<int> le = dfs(root->left,k);
        vector<int> ri = dfs(root->right,k);

        for(int i = 0; i < k; i ++)
            for(int j = 0; j + i + 1 <= k; j ++)
                res[i + j + 1] = max(res[i + j + 1], root->val + le[i] + ri[j]);
        
        for(int i = 0; i <= k; i ++)
            for(int j = 0; j <= k; j ++)
                res[0] = max(res[0],le[i] + ri[j]);
        
        return res;
    }
};


С����һ�������Ϊ root �Ķ�����ģ�ͣ���ʼ���н���Ϊ��ɫ����������ɫȾ�ϸ�ģ�ͽ��Ⱦɫ��ģ�͵�ÿ�������һ�� val ��ֵ��С�۳������ۿ��ǣ�ϣ������������ÿ����ɫ�������ֵĽ��������ܳ��� k ����������Ⱦ����ɫ�Ľ���ֵ�ܺ�����Ƕ��٣�

ʾ�� 1��

���룺root = [5,2,3,4], k = 2

�����12

���ͣ���� 5��3��4 Ⱦ����ɫ��������ļ�ֵ 5+3+4=12


ʾ�� 2��

���룺root = [4,1,3,9,null,null,2], k = 2

�����16

���ͣ���� 4��3��9 Ⱦ����ɫ��������ļ�ֵ 4+3+9=16


��ʾ��

1 <= k <= 10
1 <= val <= 10000
1 <= ������� <= 10000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/er-cha-shu-ran-se-UGC
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
