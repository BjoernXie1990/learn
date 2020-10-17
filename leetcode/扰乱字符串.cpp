class Solution {
public:
    int cnt[26];
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;

        memset(cnt,0x00,sizeof cnt);
        int n = s1.size();
        for(int i = 0; i < n; i++) {
            cnt[s1[i] - 'a']++;
            cnt[s2[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++) if(cnt[i] != 0) return false;

        for(int i = 1; i < n; i++)
            if( (isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)) ) ||
                (isScramble(s1.substr(0,i),s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0,n-i))) )
                return true;
        
        return false;
    }
};

����һ���ַ���?s1�����ǿ��԰����ݹ�طָ�������ǿ����ַ������Ӷ������ʾΪ��������

��ͼ���ַ���?s1?=?"great"?��һ�ֿ��ܵı�ʾ��ʽ��

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
����������ַ����Ĺ����У����ǿ�����ѡ�κ�һ����Ҷ�ڵ㣬Ȼ�󽻻����������ӽڵ㡣

���磬���������ѡ��Ҷ�ڵ�?"gr"?���������������ӽڵ㣬������������ַ���?"rgeat"?��

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
���ǽ�?"rgeat��?����?"great"?��һ�������ַ�����

ͬ���أ�������Ǽ��������ڵ�?"eat"?��?"at"?���ӽڵ㣬���������һ���µ������ַ���?"rgtae"?��

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
���ǽ�?"rgtae��?����?"great"?��һ�������ַ�����

��������������ȵ��ַ��� s1 ��?s2���ж�?s2?�Ƿ���?s1?�������ַ�����

ʾ��?1:

����: s1 = "great", s2 = "rgeat"
���: true
ʾ��?2:

����: s1 = "abcde", s2 = "caebd"
���: false

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/scramble-string
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
