class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sh[128] = {0}, th[128] = {0};
        int n = s.size(), m = t.size();

        for(int i = 0; i < n; i++) {
            if(sh[s[i]] != th[t[i]])
                return false;
            sh[s[i]] = i + 1;
            th[t[i]] = i + 1;
            
        }

        return true;
    }
};


���������ַ���?s?��?t���ж������Ƿ���ͬ���ġ�

���?s?�е��ַ����Ա��滻�õ�?t?����ô�������ַ�����ͬ���ġ�

���г��ֵ��ַ�����������һ���ַ��滻��ͬʱ�����ַ���˳�������ַ�����ӳ�䵽ͬһ���ַ��ϣ����ַ�����ӳ���Լ�����

ʾ�� 1:

����: s = "egg", t = "add"
���: true
ʾ�� 2:

����: s = "foo", t = "bar"
���: false
ʾ�� 3:

����: s = "paper", t = "title"
���: true
˵��:
����Լ���?s?�� t ������ͬ�ĳ��ȡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/isomorphic-strings
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
