class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        for(int i = 0, j = 0; i < n; i ++) {
            if(s[i] == '0') continue;
            
            if(i == 0 || s[i - 1] == '1') {
                j = 1;
            } else {
                j ++;
            }
            
            if(j > 1) return false;
        }
        return true;
    }
};


����һ���������ַ��� s �����ַ��� ����ǰ���� ��

��� s ������ һ���������� '1' ��ɵ��ֶ� ������ true??? �����򣬷��� false ��

?

ʾ�� 1��

���룺s = "1001"
�����false
���ͣ��ַ����е� 1 û���γ�һ�������ֶΡ�
ʾ�� 2��

���룺s = "110"
�����true
?

��ʾ��

1 <= s.length <= 100
s[i]???? Ϊ '0' �� '1'
s[0] Ϊ '1'

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
