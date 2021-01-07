class Solution {
public:
    bool isUnique(string astr) {
        int n = astr.size();
        if(n > 26) return false;

        int state = 0;
        for(int i = 0; i < n; i++) {
            int ch = astr[i] - 'a';
            if(state & (1 << ch)) {
                return false;
            } else {
                state |= (1 << ch);
            }
        }

        return true;
    }
};

ʵ��һ���㷨��ȷ��һ���ַ��� s �������ַ��Ƿ�ȫ����ͬ��

ʾ�� 1��

����: s = "leetcode"
���: false 
ʾ�� 2��

����: s = "abc"
���: true
���ƣ�

0 <= len(s) <= 100
����㲻ʹ�ö�������ݽṹ����ܼӷ֡�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/is-unique-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
