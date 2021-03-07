class Solution {
public:
    int beautySum(string s) {
        vector<int> f(26,0);
        int res = 0;
        
        for(int i = 0; i < s.size(); i++) {
            f[s[i] - 'a'] ++;
            vector<int> t = f;
            
            for(int j = 0; j < i; j++) {
                int minN = INT_MAX, maxN = INT_MIN;
                for(int k = 0; k < 26; k++) {
                    if(t[k] == 0) continue;
                    minN = min(minN,t[k]);
                    maxN = max(maxN,t[k]);
                }
                t[s[j] - 'a'] --;
                res += maxN - minN;
                
                //cout << maxN - minN << " " << i << " " << j << endl;
            }
        }
        
        return res;
    }
};


һ���ַ����� ����ֵ?����Ϊ������Ƶ������ַ������Ƶ������ַ��ĳ��ִ���֮�

�ȷ�˵��"abaacc"?������ֵΪ?3 - 1 = 2?��
����һ���ַ���?s?�����㷵�����������ַ�����?����ֵ?֮�͡�

?

ʾ�� 1��

���룺s = "aabcb"
�����5
���ͣ�����ֵ��Ϊ����ַ������� ["aab","aabc","aabcb","abcb","bcb"] ��ÿһ���ַ���������ֵ��Ϊ 1 ��
ʾ�� 2��

���룺s = "aabcbaa"
�����17
?

��ʾ��

1 <= s.length <= 500
s?ֻ����СдӢ����ĸ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sum-of-beauty-of-all-substrings
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
