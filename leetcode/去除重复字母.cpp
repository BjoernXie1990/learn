class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans("");
        int cnt[26];
        memset(cnt,0x00,sizeof cnt);
        for(auto& ch : s) cnt[ch - 'a']++;

        int n = s.size();
        vector<bool> vis(26,false);
        for(auto& ch : s) {
            if(!vis[ch - 'a']) {
                while(ans.size() && ans.back() > ch) {
                    if(cnt[ans.back() - 'a'] > 0) {
                        vis[ans.back() - 'a'] = false;
                        ans.pop_back();
                    } else {
                        break;
                    }
                }

                vis[ch - 'a'] = true;
                ans += ch;
            }

            cnt[ch - 'a']--;
        }

        return ans;
    }
};
����һ���ַ��� s ������ȥ���ַ������ظ�����ĸ��ʹ��ÿ����ĸֻ����һ�Ρ��豣֤ ���ؽ�����ֵ�����С��Ҫ���ܴ��������ַ������λ�ã���

ע�⣺������ 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters ��ͬ

?

ʾ�� 1��

���룺s = "bcabc"
�����"abc"
ʾ�� 2��

���룺s = "cbacdcbc"
�����"acdb"
?

��ʾ��

1 <= s.length <= 104
s ��СдӢ����ĸ���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-duplicate-letters
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
