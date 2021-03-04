class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        int res = 0;
        vector<int> f(n,1);
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>& a,const vector<int>& b)->bool{
            return a[0] < b[0];
        });

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    f[i] = max(f[i],f[j] + 1);
            }
            res = max(res,f[i]);
        }
        
        return res;
    }
};


����һ����ά�������� envelopes ������ envelopes[i] = [wi, hi] ����ʾ�� i ���ŷ�Ŀ�Ⱥ͸߶ȡ�

����һ���ŷ�Ŀ�Ⱥ͸߶ȶ�������ŷ���ʱ������ŷ�Ϳ��ԷŽ���һ���ŷ����ͬ����˹����һ����

����� ������ж��ٸ� �ŷ������һ�顰����˹���ޡ��ŷ⣨�����԰�һ���ŷ�ŵ���һ���ŷ����棩��

ע�⣺��������ת�ŷ⡣

?
ʾ�� 1��

���룺envelopes = [[5,4],[6,4],[6,7],[2,3]]
�����3
���ͣ�����ŷ�ĸ���Ϊ 3, ���Ϊ: [2,3] => [5,4] => [6,7]��
ʾ�� 2��

���룺envelopes = [[1,1],[1,1],[1,1]]
�����1
?

��ʾ��

1 <= envelopes.length <= 5000
envelopes[i].length == 2
1 <= wi, hi <= 104

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/russian-doll-envelopes
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
