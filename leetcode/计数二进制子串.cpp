����һ���ַ���?s�����������ͬ����0��1�ķǿ�(����)���ַ�����������������Щ���ַ����е�����0������1���������һ��ġ�

�ظ����ֵ��Ӵ�Ҫ�������ǳ��ֵĴ�����

ʾ�� 1 :

����: "00110011"
���: 6
����: ��6���Ӵ�������ͬ����������1��0����0011������01������1100������10������0011�� �� ��01����

��ע�⣬һЩ�ظ����ֵ��Ӵ�Ҫ�������ǳ��ֵĴ�����

���⣬��00110011��������Ч���Ӵ�����Ϊ���е�0����1��û�������һ��
ʾ�� 2 :

����: "10101"
���: 4
����: ��4���Ӵ�����10������01������10������01�������Ǿ�����ͬ����������1��0��
ע�⣺

s.length?��1��50,000֮�䡣
s?ֻ������0����1���ַ���


class Solution {
public:
    int countBinarySubstrings1(string s) {
        int n = s.size();
        vector<pair<char,int> > sums;
        sums.push_back({s[0],1});

        for(int i = 1; i < n; i++)
            if(s[i] == sums.back().first)
                sums.back().second++;
            else
                sums.push_back({s[i],1});
        
        int ans = 0;
        for(int i = 1; i < sums.size(); i++)
            ans += min(sums[i].second,sums[i-1].second);
        return ans;
    }

    int countBinarySubstrings(string s)
    {
        int n = s.size();
        int le = 0;
        int ri = 1;
        int ans = 0;

        for(int i = 1; i < n; i++)
        {
            if(s[i] == s[i-1])
                ri++;
            else
            {
                le = ri;
                ri = 1;
            }

            if(le >= ri)    ans++;
        }
        return ans;
    }
};
