����һ���ǿյ��ַ������ж����Ƿ����������һ���Ӵ��ظ���ι��ɡ��������ַ���ֻ����СдӢ����ĸ�����ҳ��Ȳ�����10000��

ʾ�� 1:

����: "abab"

���: True

����: �������ַ��� "ab" �ظ����ι��ɡ�
ʾ�� 2:

����: "aba"

���: False
ʾ�� 3:

����: "abcabcabcabc"

���: True

����: �������ַ��� "abc" �ظ��Ĵι��ɡ� (�������ַ��� "abcabc" �ظ����ι��ɡ�)

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str = (s + s).substr(1,s.size()*2 - 2);
        return str.find(s) != -1;
    }
};
