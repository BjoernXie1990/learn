class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int n = destination[0];
        int m = destination[1];
        int len = n + m;

        // �����
        int C[len][len];
        memset(C,0x00,sizeof C);
        C[0][0] = 1;
        for(int i = 1; i < len; i++){
            C[i][0] = 1;
            for(int j = 1; j <= i; j++) C[i][j] = C[i-1][j-1] + C[i-1][j];
        }

        string ans("");
        for(int i = 0; i < len; i++)
            if(m > 0) {
                int num = C[n + m - 1][m - 1];
                if(k > num) {
                    ans += 'V';     // ��ǰλ����һ�������
                    --n;
                    k -= num;
                } else {
                    ans += 'H';
                    --m;
                }
            } else {
                ans += 'V';
                --n;
            }
        
        return ans;
    }
};

Bob վ�ڵ�Ԫ�� (0, 0) ����Ҫǰ��Ŀ�ĵ� destination ��(row, column) ����ֻ���� �� ���� �� �ߡ������Ϊ Bob �ṩ���� ָ�� ������������Ŀ�ĵ� destination ��

ָ�� ���ַ�����ʾ������ÿ���ַ���

'H' ����ζ��ˮƽ�����ƶ�
'V' ����ζ����ֱ�����ƶ�
�ܹ�Ϊ Bob ������Ŀ�ĵ� destination ��ָ������ж��֣����磬���Ŀ�ĵ� destination �� (2, 3)��"HHHVV" �� "HVHVH" ������Ч ָ�� ��

Ȼ����Bob �����ޡ���Ϊ�������������� k������Ҫ��ѭ ���ֵ������к�ĵ� k ����Сָ�� �ĵ���ǰ��Ŀ�ĵ� destination ��k? �ı�� �� 1 ��ʼ ��

����һ���������� destination ��һ������ k �����㷵�ؿ���Ϊ Bob �ṩǰ��Ŀ�ĵ�?destination ������ ���ֵ������к�ĵ� k ����Сָ�� ��

?

ʾ�� 1��



���룺destination = [2,3], k = 1
�����"HHHVV"
���ͣ���ǰ�� (2, 3) �����е���ָ�� ���ֵ������к� ������ʾ��
["HHHVV", "HHVHV", "HHVVH", "HVHHV", "HVHVH", "HVVHH", "VHHHV", "VHHVH", "VHVHH", "VVHHH"].
ʾ�� 2��



���룺destination = [2,3], k = 2
�����"HHVHV"
ʾ�� 3��



���룺destination = [2,3], k = 3
�����"HHVVH"
?

��ʾ��

destination.length == 2
1 <= row, column <= 15
1 <= k <= nCr(row + column, row)������ nCr(a, b) ��ʾ����������� a ����Ʒ��ѡ b ����Ʒ�Ĳ�ͬ��������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/kth-smallest-instructions
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
