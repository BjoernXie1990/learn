����һ���ǿ��ַ��������а�����ĸ˳����ҵ�Ӣ�ĵ��ʱ�ʾ������0-9�����������ԭʼ�����֡�

ע��:

����ֻ����СдӢ����ĸ��
���뱣֤�Ϸ�������ת��Ϊԭʼ�����֣�����ζ���� "abc" �� "zerone" �������ǲ�����ġ�
�����ַ����ĳ���С�� 50,000��
ʾ�� 1:

����: "owoztneoer"

���: "012" (zeroonetwo)
ʾ�� 2:

����: "fviefuro"

���: "45" (fourfive)


class Solution {
public:
    string originalDigits(string s) {
        vector<string> dict{"zero","one","two","three","four","five","six","seven","eight","nine"};
        int rec[10] = {0};
        for(auto& ch : s)
        {
            if(ch == 'z')       rec[0]++;  //zero  -- o
            else if(ch == 'w')  rec[2]++;  //two   -- w
            else if(ch == 'u')  rec[4]++;  //four  -- u
            else if(ch == 'x')  rec[6]++;  //six   -- x
            else if(ch == 'g')  rec[8]++;  //eight -- g
            else if(ch == 'o')  rec[1]++;  //one   -- o - zero - two - four
            else if(ch == 'f')  rec[5]++;  //five  -- f - four
            else if(ch == 'v')  rec[7]++;  //seven -- v - five
            else if(ch == 'r')  rec[3]++;  //three -- r - zero - four
            else if(ch == 'i')  rec[9]++;  //nine  -- i - five - six - eight
        }

        rec[1] -= rec[0] + rec[2] + rec[4];
        rec[5] -= rec[4];
        rec[7] -= rec[5];
        rec[3] -= rec[0] + rec[4];
        rec[9] -= rec[5] + rec[6] + rec[8];

        string ans("");
        for(int i = 0; i <= 9; i++)
            for(int j = 0; j < rec[i]; j++)
                ans += (i + '0');
        return ans;
    }
};
