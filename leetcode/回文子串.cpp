����һ���ַ�������������Ǽ�������ַ������ж��ٸ������Ӵ���

���в�ͬ��ʼλ�û����λ�õ��Ӵ�����ʹ������ͬ���ַ���ɣ�Ҳ�ᱻ������ͬ���Ӵ���

?

ʾ�� 1��

���룺"abc"
�����3
���ͣ����������Ӵ�: "a", "b", "c"
ʾ�� 2��

���룺"aaa"
�����6
���ͣ�6�������Ӵ�: "a", "a", "a", "aa", "aa", "aaa"
?

��ʾ��

������ַ������Ȳ��ᳬ�� 1000 ��

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            ans += check(s,n,i,i);
            ans += check(s,n,i,i+1);
        }
            
        return ans;
    }

    int check(string& s,int n,int le,int ri)
    {
        int ret = 0;
        while(le >= 0 && ri <= n-1 && s[le] == s[ri])
        {
            ret++;
            le--;
            ri++;
        }

        return ret;
    }
};
