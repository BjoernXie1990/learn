class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int> > res;
        s += "A";
        int n = s.size();
        if(n < 3) return res;
        int le = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] != s[i - 1]) {
                int len = i - le;
                if(len >= 3) res.push_back({le,i-1});
                le = i;
            }
        }
        return res; 
    }
};

��һ����Сд��ĸ���ɵ��ַ��� s �У�������һЩ��������ͬ�ַ������ɵķ��顣

���磬���ַ��� s = "abbxxxxzyy"?�У��ͺ��� "a", "bb", "xxxx", "z" �� "yy" ������һЩ���顣

������������� [start, end] ��ʾ������ start �� end �ֱ��ʾ�÷������ʼ����ֹλ�õ��±ꡣ�����е� "xxxx" �����������ʾΪ [3,6] ��

���ǳ����а������ڻ�������������ַ��ķ���Ϊ �ϴ���� ��

�ҵ�ÿһ�� �ϴ���� �����䣬����ʼλ���±����˳������󣬷��ؽ����

?

ʾ��?1��

���룺s = "abbxxxxzzy"
�����[[3,6]]
���ͣ�"xxxx" ��һ����ʼ�� 3 ����ֹ�� 6 �Ľϴ���顣
ʾ�� 2��

���룺s = "abc"
�����[]
���ͣ�"a","b" �� "c" �����Ƿ���Ҫ��Ľϴ���顣
ʾ�� 3��

���룺s = "abcdddeeeeaabbbcd"
�����[[3,5],[6,9],[12,14]]
���ͣ��ϴ����Ϊ "ddd", "eeee" �� "bbb"
ʾ�� 4��

���룺s = "aba"
�����[]
?
��ʾ��

1 <= s.length <= 1000
s ����СдӢ����ĸ

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/positions-of-large-groups
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
