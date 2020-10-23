class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        int dp[26];     // dp[i] ��ʾ�� i + 'a' ��β����������ַ����ĳ���
        memset(dp,0x00,sizeof dp);

        int cnt = 1;
        for(int i = 0; i < n; i++) {
            if(i > 0 && check(p[i-1],p[i])) cnt++;
            else cnt = 1;

            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], cnt);
        }

        int ans = 0;
        for(int i = 0; i < 26; i++) ans += dp[i];
        return ans;
    }

    bool check(char le,char ri) {
        if(le == 'z') return ri == 'a';
        return le + 1 == ri;
    }
};

���ַ��� s �����ǡ�abcdefghijklmnopqrstuvwxyz�������޻����ַ���������?s �������������ģ�"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".?

��������������һ���ַ��� p ������Ҫ�����ҳ� s ���ж��ٸ�Ψһ�� p �ķǿ��Ӵ��������ǵ�����������ַ��� p ������Ҫ����ַ���?s �� p �Ĳ�ͬ�ķǿ��Ӵ�����Ŀ��?

ע��: p?����Сд��Ӣ����ĸ��ɣ�p �Ĵ�С���ܳ��� 10000��

?

ʾ��?1:

����: "a"
���: 1
����: �ַ��� S ��ֻ��һ��"a"���ַ���
?

ʾ�� 2:

����: "cac"
���: 2
����: �ַ��� S �е��ַ�����cac��ֻ�������Ӵ���a������c����.
?

ʾ�� 3:

����: "zab"
���: 6
����: ���ַ��� S ���������Ӵ���z������a������b������za������ab������zab����.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/unique-substrings-in-wraparound-string
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
