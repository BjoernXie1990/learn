class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = 0;
        int m = 0;
        int len1 = typed.size();
        int len2 = name.size();

        while(n < len1) {
            if(typed[n] == name[m]) {
                n++;
                m++;
            } else if(n > 0 && typed[n] == typed[n-1]){
                n++;
            } else return false;
        }

        return m == len2;
    }
};

�����������ʹ�ü���������������?name��ż�����ڼ����ַ�?c?ʱ���������ܻᱻ���������ַ����ܱ����� 1 �λ��Ρ�

�㽫�������������ַ�?typed���������Ӧ�Ŀ�����������ѵ����֣�����һЩ�ַ����ܱ�����������ô�ͷ���?True��

?

ʾ�� 1��

���룺name = "alex", typed = "aaleex"
�����true
���ͣ�'alex' �е� 'a' �� 'e' ��������
ʾ�� 2��

���룺name = "saeed", typed = "ssaaedd"
�����false
���ͣ�'e' һ����Ҫ���������Σ����� typed ������в���������
ʾ�� 3��

���룺name = "leelee", typed = "lleeelee"
�����true
ʾ�� 4��

���룺name = "laiden", typed = "laiden"
�����true
���ͣ����������е��ַ������Ǳ�Ҫ�ġ�
?

��ʾ��

name.length <= 1000
typed.length <= 1000
name ��?typed?���ַ�����Сд��ĸ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/long-pressed-name
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
