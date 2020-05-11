//һ��������ĸ?A-Z ����Ϣͨ�����·�ʽ�����˱��룺

//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//����һ��ֻ�������ֵķǿ��ַ������������뷽����������

//ʾ�� 1:

class Solution {
public:
    int ans;
    int len;
    int numDecodings(string s) {
        ans = 0;
        len = s.size();
        //dfs(s,0);
        vector<int> dp(len,0);//��ʾ��iλ�õ��ַ�����ʱ�����ƥ�䷽ʽ
        dp[0] = s[0]=='0'?0:1;
        for(int i = 1; i < len; i++)
        {
            char n = s[i];
            char left = s[i-1];
            int num = (left-'0')* 10 + n-'0';
            if(n != '0') dp[i] += dp[i-1];//0�����ǵ���һ���ַ�

            if(left == '1' || (left=='2' && n<='6'))
                if(i >= 2) dp[i] += dp[i-2];
                else dp[i]++;
        }
        return dp[len-1];
    }
    //���ѳ�ʱ
    void dfs(string& s,int index)
    {
        if(s[index] == '0')
            return;
        if(index >= len)
        {
            ans++;
            return;
        }

        //ѡ��һλ
        dfs(s,index+1);

        if(index+1 >= len) return;
        //ѡ����λ
        int num = (s[index]-'0')* 10 + s[index+1]-'0';
        if(num >=1 && num<=26)
            dfs(s,index+2);
    }
};
