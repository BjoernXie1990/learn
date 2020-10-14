class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int cnt[26];
        memset(cnt,0x00,sizeof cnt);
        for(auto ch : A[0]) cnt[ch - 'a']++;

        int n = A.size();
        int tmp[26];
        for(int i = 1; i < n; i++) {
            memset(tmp,0x00,sizeof tmp);

            for(auto ch : A[i]) tmp[ch - 'a']++;
            for(int j = 0; j < 26; j++) cnt[j] = min(cnt[j],tmp[j]);
        }

        vector<string> ans;
        for(int i = 0; i < 26; i++) {
            if(cnt[i] == 0) continue;
            string str(1, i + 'a');
            for(int j = 0; j < cnt[i]; j++) ans.push_back(str);
        }

        return ans;
    }
};


��������Сд��ĸ��ɵ��ַ������� A�������б��е�ÿ���ַ����ж���ʾ��ȫ���ַ��������ظ��ַ�����ɵ��б����磬���һ���ַ���ÿ���ַ����г��� 3 �Σ������� 4 �Σ�����Ҫ�����մ��а������ַ� 3 �Ρ�

����԰�����˳�򷵻ش𰸡�

?

ʾ�� 1��

���룺["bella","label","roller"]
�����["e","l","l"]
ʾ�� 2��

���룺["cool","lock","cook"]
�����["c","o"]
?

��ʾ��

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] ��Сд��ĸ

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-common-characters
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
