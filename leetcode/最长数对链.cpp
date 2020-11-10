class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](const vector<int>& a,const vector<int>& b)->bool{
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1] < b[1];
        });

        int n = pairs.size();
        int f[n];
        memset(f,0x00,sizeof f);
        for(int i = 0; i < n; i++) {
            f[i] = 1;
            for(int j = 0; j < i; j++) {
                if(pairs[i][0] > pairs[j][1]) f[i] = max(f[i],f[j] + 1);
            }
        }

        return f[n-1];
    }
};

����?n?�����ԡ�?��ÿһ�������У���һ���������Ǳȵڶ�������С��

���ڣ����Ƕ���һ�ָ����ϵ�����ҽ���?b < c?ʱ������(c, d)?�ſ��Ը���?(a, b)?���档������������ʽ������һ����������

����һ�����Լ��ϣ��ҳ��ܹ��γɵ���������ĳ��ȡ��㲻��Ҫ�õ����е����ԣ���������κ�˳��ѡ�����е�һЩ���������졣

?

ʾ����

���룺[[1,2], [2,3], [3,4]]
�����2
���ͣ������������ [1,2] -> [3,4]
?

��ʾ��

�������Եĸ�����?[1, 1000] ��Χ�ڡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-length-of-pair-chain
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
