����һ�������ƴ�?s? ��һ��ֻ���� 0 �� 1 ���ַ����������ǿ��Խ� s?�ָ�� 3 �� �ǿ�?�ַ��� s1, s2, s3 ��s1 + s2 + s3 = s����

���㷵�طָ�?s?�ķ����������� s1��s2 �� s3 ���ַ� '1' ����Ŀ��ͬ��

���ڴ𰸿��ܴܺ��뽫���� 10^9 + 7 ȡ��󷵻ء�

?

ʾ�� 1��

���룺s = "10101"
�����4
���ͣ��ܹ��� 4 �ַ����� s �ָ�ɺ��� '1' ��Ŀ��ͬ���������ַ�����
"1|010|1"
"1|01|01"
"10|10|1"
"10|1|01"
ʾ�� 2��

���룺s = "1001"
�����0
ʾ�� 3��

���룺s = "0000"
�����3
���ͣ��ܹ��� 3 �ַָ� s �ķ�����
"0|0|00"
"0|00|0"
"00|0|0"
ʾ�� 4��

���룺s = "100100010100110"
�����12
?

��ʾ��

s[i] == '0'?����?s[i] == '1'
3 <= s.length <= 10^5


class Solution {
public:
    const int mod = 1e9 + 7;
    int numWays(string s) {
        int n = s.size();
        int sum = 0;
        long ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') sum++;
        }
        if(sum == 0){
            for(int i = 1; i <= n-2; i++){
                ans = (ans + i) % mod;
            }
            return ans;
        }
        
        if(sum % 3 != 0)    return 0;
        
        int num = sum / 3;
        int tmp = 0;
        int le = 0;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '1') tmp++;
            le = i;
            if(tmp == num) break;
        }
        tmp = 0;
        int ri = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '1') tmp++;
            ri = i;
            if(tmp == num)  break;
        }
        
        int le_n = 0;
        for(int i = le+1; i < n; i++) {
            le_n++;
            if(s[i] == '1')   break;
        }
        int ri_n = 0;
        for(int i = ri-1; i >= 0; i--) {
            ri_n++;
            if(s[i] == '1')   break;
        }
        
        for(int i = 1; i <= le_n; i++){
            ans =(ri_n + ans) % mod;
        }
        return ans;
    }
};
