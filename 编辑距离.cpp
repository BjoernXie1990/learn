//������������?word1 ��?word2������������?word1?ת����?word2 ��ʹ�õ����ٲ�����?��

//����Զ�һ�����ʽ����������ֲ�����

//����һ���ַ�
//ɾ��һ���ַ�
//�滻һ���ַ�
//?

//ʾ��?1��

//���룺word1 = "horse", word2 = "ros"
//�����3
//���ͣ�
//horse -> rorse (�� 'h' �滻Ϊ 'r')
//rorse -> rose (ɾ�� 'r')
//rose -> ros (ɾ�� 'e')
//ʾ��?2��

//���룺word1 = "intention", word2 = "execution"
//�����5
//���ͣ�
//intention -> inention (ɾ�� 't')
//inention -> enention (�� 'i' �滻Ϊ 'e')
//enention -> exention (�� 'n' �滻Ϊ 'x')
//exention -> exection (�� 'n' �滻Ϊ 'c')
//exection -> execution (���� 'u')



class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1));

        //��ʼ����һ�У���Ҫת�����ִ�λ��
        for(int i = 0; i <= len2; i++)
            dp[0][i] = i;
        //��ʼ����һ�У���ת�����Ӵ����ַ�λ��
        for(int i = 0; i <= len1; i++)
            dp[i][0] = i;

        for(int i = 1; i <= len1; i++)
            for(int j = 1; j <= len2; j++)
            {
                //��������ַ�ƥ����������ֵΪ0
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else//�ַ����䣬����ɾ������С�Ĳ���
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
                //dp[i-1][j-1] -- �޸Ĳ���
                //dp[i-1][j]  -- ɾ������
                //dp[i][j-1]  -- �������
            }
        
        return dp[len1][len2];
    }
};
