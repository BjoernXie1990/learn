�ҵ������ַ�������Сд�ַ���ɣ��е���Ӵ� T ��?Ҫ��?T?�е�ÿһ�ַ����ִ����������� k ����� T?�ĳ��ȡ�

ʾ�� 1:

����:
s = "aaabb", k = 3

���:
3

��Ӵ�Ϊ "aaa" ������ 'a' �ظ��� 3 �Ρ�
ʾ�� 2:

����:
s = "ababbc", k = 2

���:
5

��Ӵ�Ϊ "ababb" ������ 'a' �ظ��� 2 �Σ� 'b' �ظ��� 3 �Ρ�
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(k <= 1)  return s.size();
        if(s.empty() || s.size() < k)   return 0;

        vector<int> arr(26,0);
        for(auto& ch : s)
            arr[ch-'a']++;
        
        int p = 0;
        while(p < s.size() && arr[s[p] - 'a'] >= k)  p++;
        //s  ȫ���������
        if(p == s.size())   return s.size();

        int left = longestSubstring(s.substr(0,p),k);
        while(p < s.size() && arr[s[p] - 'a'] < k) p++;
        int right = longestSubstring(s.substr(p),k);

        return max(right,left);
    }
};
