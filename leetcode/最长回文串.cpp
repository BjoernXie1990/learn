class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> f;
        for(auto& e : s) {
            f[e] ++;
        }

        int ans = 0;
        bool flag = false;
        for(auto& e : f) {
            int cnt = e.second;
            ans += (cnt / 2);
            if(cnt & 1)
                flag = true;
        }

        return ans * 2 + ((flag) ? 1 : 0);
    }
};


����һ��������д��ĸ��Сд��ĸ���ַ������ҵ�ͨ����Щ��ĸ����ɵ���Ļ��Ĵ���

�ڹ�������У���ע�����ִ�Сд������?"Aa"?���ܵ���һ�������ַ�����

ע��:
�����ַ����ĳ��Ȳ��ᳬ�� 1010��

ʾ�� 1:

����:
"abccccdd"

���:
7

����:
���ǿ��Թ������Ļ��Ĵ���"dccaccd", ���ĳ����� 7��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-palindrome
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
