//����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ���?s ����󳤶�Ϊ 1000��

//ʾ�� 1��

//����: "babad"
//���: "bab"
//ע��: "aba" Ҳ��һ����Ч�𰸡�
//ʾ�� 2��

//����: "cbbd"
//���: "bb"



class Solution {
public:
    //��̬�滮 O(n * n)
    string longestPalindrome1(string s) {
        int len = s.size();
        //dp[i][j] ��ʾ��i��j�Ƿ���Թ��ɻ����ַ���
        vector<vector<bool>> dp(len,vector<bool>(len,false));
        //��ʼ��һ���ַ���λ�ã����Ƕ��ǻ����ַ���
        for(int i = 0; i < len; i++)
            dp[i][i] = true;

        //���ջ����ַ�������ʼλ��
        int start = 0;
        int end = 0;

        for(int j = 1; j < len; j++)
            for(int i = 0; i < j; i++) {
                if(s[i] == s[j]) {
                    //aba  aa  a   �������ΪС���������Ҵ��������ַ�����ȣ�һ�����Թ��ɻ���
                    if(j - i < 3)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i+1][j-1];//�ж������Ӵ��Ƿ��ǻ��ĵ�
                }
                else {
                    dp[i][j] = false;//��С��Χ
                }
                    
                //���dp[i][j]��true ����ʾ�ǻ����ַ���
                //���ҳ��ȱȼ�¼�ĳ��ȴ�ʱ����¼��ʼλ��
                if( dp[i][j] && ((end - start + 1) < (j - i + 1)) ) {
                    start = i;
                    end = j;
                }
            }
        
        return s.substr(start,end - start + 1);
    }
    //������ɢ  ʱ�临�Ӷ�O(N * N) --> ������ȫ������һ�����ַ�
    string longestPalindrome(string s) {
        int len = s.size();
        if(len < 2) return s;
        vector<int> ans(2,0);//��������Ӵ��Ŀ�ʼλ�úͳ���
        ans[0] = 0;
        ans[1] = 1;
        for(int i = 0; i < len; i++) 
            i = FindLongest(s,i,ans,len);
        return s.substr(ans[0],ans[1]);
    }

    int FindLongest(string s, int left, vector<int>& ans,int len) {
        int right = left;
        //ȷ���м䲿�ֵ�λ�ã��ж��� aa��  ����aba��
        while(right < len-1 && s[right+1] == s[left])
            right++;
        
        //��λ�м�λ�����һ���ַ�
        int end = right;
        while(left > 0 && right < len-1 && s[left-1] == s[right+1]) {
            left--;
            right++;
        }
        int now = right - left + 1;
        if(now > ans[1]) {
            ans[0] = left;
            ans[1] = now;
        }
        return end;
    }
};
