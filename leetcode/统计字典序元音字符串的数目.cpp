class Solution {
public:
    int countVowelStrings(int n) {
        int f[5];
        memset(f,0x00,sizeof f);
        for(int i = 0; i <5; i++) f[i] = 1;
        
        for(int i = 1; i < n; i++) {
            int t[5];
            memset(t,0x00,sizeof t);
            
            for(int k = 0; k < 5; k++)
                for(int j = k; j < 5; j++) t[j] += f[k];
            
            for(int k = 0; k <5; k++) f[k] = t[k];
        }
            
        int ans = 0;
        for(int i = 0; i < 5; i++) ans += f[i];
        return ans;
    }
};

����һ������ n���뷵�س���Ϊ n ������Ԫ�� (a, e, i, o, u) ����Ұ� �ֵ������� ���ַ���������

�ַ��� s �� �ֵ������� ��Ҫ���㣺����������Ч�� i��s[i] ����ĸ���е�λ�������� s[i+1] ��ͬ���� s[i+1] ֮ǰ��

?

ʾ�� 1��

���룺n = 1
�����5
���ͣ�����Ԫ����ɵ� 5 ���ֵ����ַ���Ϊ ["a","e","i","o","u"]
ʾ�� 2��

���룺n = 2
�����15
���ͣ�����Ԫ����ɵ� 15 ���ֵ����ַ���Ϊ
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"]
ע�⣬"ea" ���Ƿ���������ַ�������Ϊ 'e' ����ĸ���е�λ�ñ� 'a' ����
ʾ�� 3��

���룺n = 33
�����66045
?

��ʾ��

1 <= n <= 50?

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/count-sorted-vowel-strings
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
