class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n != m) return false;

        int cntn[26],cntm[26];
        memset(cntn,0x00,sizeof cntn);
        memset(cntm,0x00,sizeof cntm);
        for(auto ch : word1) cntn[ch - 'a'] ++;
        for(auto ch : word2) cntm[ch - 'a'] ++;

        for(int i = 0; i < 26; i++)
            if(((cntm[i] == 0) + (cntn[i] == 0)) == 1) return false;
            //if((cntn[i] == 0 && cntm[i] != 0) || (cntn[i] != 0 && cntm[i] == 0)) return false;


        sort(cntn,cntn + 26);
        sort(cntm,cntm +26);
        for(int i = 0; i < 26; i++) if(cntm[i] != cntn[i]) return false;
        return true;
    }
};


�������ʹ�����²�����һ���ַ����õ���һ���ַ���������Ϊ�����ַ��� �ӽ� ��

���� 1�������������� ���� �ַ���
���磬abcde -> aecdb
���� 2����һ�� ���� �ַ���ÿ�γ���ת��Ϊ��һ�� ���� �ַ���������һ���ַ�ִ����ͬ�Ĳ�����
���磬aacabb -> bbcbaa������ a ת��Ϊ b �������е� b ת��Ϊ a ��
����Ը�����Ҫ������һ���ַ������ʹ�������ֲ�����

���������ַ�����word1 �� word2 ����� word1 �� word2 �ӽ� ���ͷ��� true �����򣬷��� false ��

?

ʾ�� 1��

���룺word1 = "abc", word2 = "bca"
�����true
���ͣ�2 �β����� word1 ��� word2 ��
ִ�в��� 1��"abc" -> "acb"
ִ�в��� 1��"acb" -> "bca"
ʾ�� 2��

���룺word1 = "a", word2 = "aa"
�����false
���ͣ�����ִ�ж��ٴβ��������޷��� word1 �õ� word2 ����֮��Ȼ��
ʾ�� 3��

���룺word1 = "cabbba", word2 = "abbccc"
�����true
���ͣ�3 �β����� word1 ��� word2 ��
ִ�в��� 1��"cabbba" -> "caabbb"
ִ�в��� 2��"caabbb" -> "baaccc"
ִ�в��� 2��"baaccc" -> "abbccc"
ʾ�� 4��

���룺word1 = "cabbba", word2 = "aabbss"
�����false
���ͣ�����ִ�ж��ٴβ��������޷��� word1 �õ� word2 ����֮��Ȼ��
?

��ʾ��

1 <= word1.length, word2.length <= 105
word1 �� word2 ������СдӢ����ĸ

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/determine-if-two-strings-are-close
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
