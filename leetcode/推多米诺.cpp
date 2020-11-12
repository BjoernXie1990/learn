class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int le = 0, ri = n - 1;

        for(int i = 0; i < n; i++) {
            if(dominoes[i] == '.') continue;

            if(dominoes[i] == 'L') {
                for(int j = i - 1; j >= 0 && dominoes[j] == '.'; j--) dominoes[j] = 'L';
                continue;
            }

            // dominoes[i] == 'R'
            int len = 0;    // 'R' -> 'L' �м����
            for(int j = i + 1; j < n && dominoes[j] == '.'; j++) {
                dominoes[j] = 'R';
                len++;
            }
            int next = i + len + 1;     // ѭ��ֹͣ��λ��
            if(next == n) break;
            if(dominoes[next] == 'R') continue;

            // ������ 'L'
            int pos = i + len / 2 + 1;
            if(len % 2 == 1) {
                dominoes[pos++] = '.';
            } 
            while(pos < next) dominoes[pos++] = 'L';
            i = next;
        }

        return dominoes;
    }
};


һ������ N �Ŷ���ŵ���ƣ����ǽ�ÿ�Ŷ���ŵ���ƴ�ֱ������

�ڿ�ʼʱ������ͬʱ��һЩ����ŵ��������������ơ�



ÿ��һ�룬������ߵĶ���ŵ���ƻ��ƶ���������ڵĶ���ŵ���ơ�

ͬ���أ������ұߵĶ���ŵ����Ҳ���ƶ����������Ҳ�����ڶ���ŵ���ơ�

���ͬʱ�ж���ŵ��������һ�Ŵ�ֱ�����Ķ���ŵ���Ƶ����ߣ���������ƽ�⣬ �ù�����Ȼ���ֲ��䡣

�����������ԣ����ǻ���Ϊ�����½��Ķ���ŵ���Ʋ�������������½����Ѿ��½��Ķ���ŵ����ʩ�Ӷ��������

������ʾ��ʼ״̬���ַ��� "S" ������� i �Ŷ���ŵ���Ʊ�������ߣ��� S[i] = 'L'������� i �Ŷ���ŵ���Ʊ������ұߣ��� S[i] = 'R'������� i �Ŷ���ŵ����û�б��ƶ����� S[i] = '.'��

���ر�ʾ����״̬���ַ�����

ʾ�� 1��

���룺".L.R...LR..L.."
�����"LL.RR.LLRRLL.."
ʾ�� 2��

���룺"RR.L"
�����"RR.L"
˵������һ�Ŷ���ŵ����û�и��ڶ���ʩ�Ӷ��������
��ʾ��

0 <= N <= 10^5
��ʾ����ŵ����״̬���ַ���ֻ���� 'L'��'R'; �Լ� '.';

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/push-dominoes
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
