class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     * ����ţţ�ܺȵ����ľ�
     * @param m int���� �Ƶ���
     * @param n int���� ţţ���ֽ�
     * @return int����
     */
    int countWine(int m, int n) {
        // write code here
        
        int ans = n / m;
        int p1 = ans;
        int p2 = ans;
        
        while(p1 >= 2 || p2 >= 4) {
            int sum = p1 / 2 + p2 / 4;
            ans += sum;
            p1 = sum + p1 % 2;
            p2 = sum + p2 % 4;
        }
        
        return ans;
    }
};

���ӣ�https://ac.nowcoder.com/acm/problem/212807
��Դ��ţ����

ţţ��һ���ƹ��ǳ����Ⱦƣ�һƿ��mԪǮ��������ƿ���Ի�һƿ�ƣ��ĸ�ƿ�ǿ��Ի�һƿ�ƣ������� n ԪǮ���������Ժȶ���ƿ�ƣ�
��ע��û�н�����ܣ������ղ������һƿ�ơ�������þ�ƿ�һ��黹�Ĳ�����
ʾ��1
����
����
2,12
����ֵ
����
19
˵��
ţţ�ܼƿ��Ժ�19ƿ��
��ע:
0 < m < 100
0 < n < 2000
