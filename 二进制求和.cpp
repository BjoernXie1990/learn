���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����

����Ϊ �ǿ� �ַ�����ֻ��������?1?��?0��

?

ʾ��?1:

����: a = "11", b = "1"
���: "100"
ʾ��?2:

����: a = "1010", b = "1011"
���: "10101"
?

��ʾ��

ÿ���ַ��������ַ� '0' �� '1' ��ɡ�
1 <= a.length, b.length <= 10^4
�ַ���������� "0" ���Ͷ�����ǰ���㡣



class Solution {
public:
    string addBinary(string a, string b) {
        int pa = a.size() - 1;
        int pb = b.size() - 1;

        string ans = "";
        int cur = 0;
        while(~pa || ~pb || cur)
        {
            if(~pa) cur += a[pa--] - '0';

            if(~pb) cur += b[pb--] - '0';

            //cur��ȡֵ        0 1 2 3
            //��Ӧ��ǰλ������ 0 1 0 1
            //cur�仯�������  0 0 1 1
            ans += (cur & 1) ? "1" : "0";
            cur = (cur < 2) ? 0 : 1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
