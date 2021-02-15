class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f(255,0);
        for(auto& e : s1) f[e] ++;
        int le = 0;
        for(int i = 0; i < s2.size(); i++) {
            f[s2[i]] --;
            while(le <= i && f[s2[i]] < 0)
                f[s2[le ++]] ++;
            if(i - le + 1 == s1.size()) return true;
        }
        return false;
    }
};


���������ַ���?s1?��?s2��дһ���������ж� s2 �Ƿ���� s1?�����С�

���仰˵����һ���ַ���������֮һ�ǵڶ����ַ������Ӵ���

ʾ��1:

����: s1 = "ab" s2 = "eidbaooo"
���: True
����: s2 ���� s1 ������֮һ ("ba").
?

ʾ��2:

����: s1= "ab" s2 = "eidboaoo"
���: False
?

ע�⣺

������ַ���ֻ����Сд��ĸ
�����ַ����ĳ��ȶ��� [1, 10,000] ֮��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/permutation-in-string
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
