class Solution {
public:
    int minCharacters(string a, string b) {
        int f[300];
        int n = a.size(), m =  b.size();
        memset(f,0x00,sizeof f);
        for(auto& e : a) f[e] ++;
        for(auto& e : b) f[e] ++;
        
        int maxt = 0;
        for(int i = 1; i < 300; i++) if(f[i] > f[maxt]) maxt = i;
        int res = n + m - f[maxt];
        
        vector<vector<int> > tfi(26,vector<int> (2,0));
        vector<vector<int> > tfa(26,vector<int> (2,0));
        for(int i = 0;i < 26; i++) {
            for(auto& e : a) {
                tfi[i][0] += e > (i + 'a'); // ��� = i
                tfa[i][0] += e < (i + 'a'); // ��С = i
            }
            for(auto& e : b) {
                tfi[i][1] += e > (i + 'a');
                tfa[i][1] += e < (i + 'a');
            }
        }
        for(int i = 0; i < 26; i++)
            for(int j =i + 1 ;  j < 26; j++) {
                res = min(res,tfi[i][0] + tfa[j][1]);
                res = min(res,tfi[i][1] + tfa[j][0]);
            }
        return res;
    }
    
};

���������ַ��� a �� b �����߾���Сд��ĸ��ɡ�һ�������У�����Խ� a �� b �е� ��һ�ַ� �ı�Ϊ ��һСд��ĸ ��

����������Ŀ�������������������� ֮һ ��

a �е� ÿ����ĸ ����ĸ���� �ϸ�С�� b �е� ÿ����ĸ ��
b �е� ÿ����ĸ ����ĸ���� �ϸ�С�� a �е� ÿ����ĸ ��
a �� b �� �� ͬһ�� ��ĸ��ɡ�
���ش��Ŀ������� ���� ��������

?

ʾ�� 1��

���룺a = "aba", b = "caa"
�����2
���ͣ�����ÿ����������ѷ����ֱ��ǣ�
1) �� b ��Ϊ "ccc"��2 �β��������� a �е�ÿ����ĸ��С�� b �е�ÿ����ĸ��
2) �� a ��Ϊ "bbb" ���� b ��Ϊ "aaa"��3 �β��������� b �е�ÿ����ĸ��С�� a �е�ÿ����ĸ��
3) �� a ��Ϊ "aaa" ���� b ��Ϊ "aaa"��2 �β��������� a �� b ��ͬһ����ĸ��ɡ�
��ѵķ���ֻ��Ҫ 2 �β������������� 1 �������� 3����
ʾ�� 2��

���룺a = "dabadd", b = "cda"
�����3
���ͣ��������� 1 ����ѷ����ǽ� b ��Ϊ "eee" ��
?

��ʾ��

1 <= a.length, b.length <= 105
a �� b ֻ��Сд��ĸ���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
