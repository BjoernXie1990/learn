����һ������ n ����1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ�����

���磬����12��1��12��Щ�����а���1 ��������1��10��11��12��1һ��������5�Ρ�

?

ʾ�� 1��

���룺n = 12
�����5
ʾ�� 2��

���룺n = 13
�����6
?

���ƣ�

1 <= n <?2^31


class Solution {
public:
    int countDigitOne1(int n) {
        int ans = 0;
        
        for(int i = 1; i <= n; i++)
        {
            int num = i;
            while(num)
            {
                if(num % 10 == 1)
                    ans++;
                num /= 10;
            }
        }

        return ans;
    }

    int countDigitOne(int n) {
        int ans = 0;
        long i = 1; //i��ʾ��һλ�����֣�i = 1��ʾ��λ��i = 10 ��ʾʮλ

        while(n / i != 0)
        {
            //��ǰλ�ĸ�λ����
            long high = n / (10 * i);
            //��ǰλ������
            long cur = (n / i) % 10;
            //��ǰλ�ĵ�λ����
            long low = n - (n / i) * i;

            if(cur == 0)
                ans += high * i;
            else if(cur == 1)
                ans += high * i + low + 1;
            else
                ans += (high + 1) * i;

            i *= 10;
        }
        return ans;
    }
};
