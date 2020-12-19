class Solution {
public:
    typedef pair<int,char> PIC;
    string longestDiverseString(int a, int b, int c) {
        vector<PIC> f(3);
        f[0] = {a,'a'};
        f[1] = {b,'b'};
        f[2] = {c,'c'};

        string ans("");
        while(f[0].first || f[1].first || f[2].first) {
            sort(f.rbegin(),f.rend());
            if(ans.empty() || ans.back() != f[0].second) {
                if(f[0].first-- > 0) 
                    ans += f[0].second;
                if(f[0].first-- > 0) 
                    ans += f[0].second;
            } else {
                if(f[1].first-- > 0)
                    ans += f[1].second;
                else break;
            }
        }

        return ans;
    }
};


����ַ����в������κ� 'aaa'��'bbb' �� 'ccc' �������ַ�����Ϊ�Ӵ�����ô���ַ�������һ���������ַ�������

������������ a��b ��c�����㷵�� ����һ�� ��������ȫ���������ַ��� s��

s ��һ�������ܳ��Ŀ����ַ�����
s �� ��� ��a ����ĸ 'a'��b?����ĸ 'b'��c ����ĸ 'c' ��
s ��ֻ���� 'a'��'b' ��'c' ������ĸ��
����������������ַ��� s ���뷵��һ�����ַ��� ""��

?

ʾ�� 1��

���룺a = 1, b = 1, c = 7
�����"ccaccbcc"
���ͣ�"ccbccacc" Ҳ��һ����ȷ�𰸡�
ʾ�� 2��

���룺a = 2, b = 2, c = 1
�����"aabbc"
ʾ�� 3��

���룺a = 7, b = 1, c = 0
�����"aabaa"
���ͣ����Ǹò���������Ψһ��ȷ�𰸡�
?

��ʾ��

0 <= a, b, c <= 100
a + b + c > 0

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-happy-string
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
