class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        int m = word.size();

        int ans = 0;
        string s = "";
        for(int i = 1; m * i <= n; i++) {
            s += word;
            if(sequence.find(s) == -1) return ans;
            ans++;
        }

        return ans;
    }
};


����һ���ַ���?sequence?������ַ��� word?�����ظ�?k?���γɵ��ַ�����?sequence?��һ�����ַ�������ô����?word �� �ظ�ֵΪ k ������ word?�� ����ظ�ֵ?�ǵ���?word?��?sequence?�������ظ�ֵ�����?word?����?sequence?���Ӵ�����ô�ظ�ֵ?k?Ϊ 0 ��

����һ���ַ��� sequence?�� word?�����㷵�� ����ظ�ֵ?k ��

?

ʾ�� 1��

���룺sequence = "ababc", word = "ab"
�����2
���ͣ�"abab" �� "ababc" �����ַ�����
ʾ�� 2��

���룺sequence = "ababc", word = "ba"
�����1
���ͣ�"ba" �� "ababc" �����ַ������� "baba" ���� "ababc" �����ַ�����
ʾ�� 3��

���룺sequence = "ababc", word = "ac"
�����0
���ͣ�"ac" ���� "ababc" �����ַ�����
?

��ʾ��

1 <= sequence.length <= 100
1 <= word.length <= 100
sequence ��?word?��ֻ����СдӢ����ĸ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-repeating-substring
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
