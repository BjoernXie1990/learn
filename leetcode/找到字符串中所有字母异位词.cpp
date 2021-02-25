class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hash(26,0), cnt(26,0);
        for(int i = 0; i < p.size(); i++)
            cnt[p[i] - 'a'] ++;
        
        vector<int> res;
        int le = 0;

        for(int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] ++;
            while(le <= i && hash[s[i] - 'a'] > cnt[s[i] - 'a'])
                hash[s[le++] - 'a'] --;
            
            if(i - le + 1 == p.size())
                res.push_back(i - p.size() + 1);
        }

        return res;
    }
};


����һ���ַ���?s?��һ���ǿ��ַ���?p���ҵ�?s?��������?p?����ĸ��λ�ʵ��Ӵ���������Щ�Ӵ�����ʼ������

�ַ���ֻ����СдӢ����ĸ�������ַ���?s?�� p?�ĳ��ȶ������� 20100��

˵����

��ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����
�����Ǵ������˳��
ʾ��?1:

����:
s: "cbaebabacd" p: "abc"

���:
[0, 6]

����:
��ʼ�������� 0 ���Ӵ��� "cba", ���� "abc" ����ĸ��λ�ʡ�
��ʼ�������� 6 ���Ӵ��� "bac", ���� "abc" ����ĸ��λ�ʡ�
?ʾ�� 2:

����:
s: "abab" p: "ab"

���:
[0, 1, 2]

����:
��ʼ�������� 0 ���Ӵ��� "ab", ���� "ab" ����ĸ��λ�ʡ�
��ʼ�������� 1 ���Ӵ��� "ba", ���� "ab" ����ĸ��λ�ʡ�
��ʼ�������� 2 ���Ӵ��� "ab", ���� "ab" ����ĸ��λ�ʡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-all-anagrams-in-a-string
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
