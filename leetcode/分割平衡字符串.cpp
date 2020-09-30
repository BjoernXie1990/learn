class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int numR = 0;
        int numL = 0;

        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') numR++;
            else if (s[i] == 'L') numL++;

            if(numR == numL) 
                ans++;
        }

        return ans;
    }
};

��һ����ƽ���ַ������У�'L' �� 'R' �ַ�����������ͬ�ġ�

����һ��ƽ���ַ���?s�����㽫���ָ�ɾ����ܶ��ƽ���ַ�����

���ؿ���ͨ���ָ�õ���ƽ���ַ��������������

?

ʾ�� 1��

���룺s = "RLRRLLRLRL"
�����4
���ͣ�s ���Էָ�Ϊ "RL", "RRLL", "RL", "RL", ÿ�����ַ����ж�������ͬ������ 'L' �� 'R'��
ʾ�� 2��

���룺s = "RLLLLRRRLR"
�����3
���ͣ�s ���Էָ�Ϊ "RL", "LLLRRR", "LR", ÿ�����ַ����ж�������ͬ������ 'L' �� 'R'��
ʾ�� 3��

���룺s = "LLLLRRRR"
�����1
���ͣ�s ֻ�ܱ���ԭ�� "LLLLRRRR".
?

��ʾ��

1 <= s.length <= 1000
s[i] = 'L' �� 'R'
�ָ�õ���ÿ���ַ�����������ƽ���ַ�����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/split-a-string-in-balanced-strings
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
