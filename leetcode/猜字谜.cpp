class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n = words.size(), m = puzzles.size();
        vector<int> res(m,0);

        unordered_map<int,int> mp;
        for(auto& e : words) {
            int mask = 0;
            for(auto& ch : e)
                mask |= (1 << (ch - 'a'));
            mp[mask] ++;
        }

        for(int i = 0; i < m; i++) {
            int mask = 0;
            for(auto& ch : puzzles[i])
                mask |= (1 << (ch - 'a'));
            
            for(int j = mask; j; j = (j - 1) & mask) {
                int t = j & (1 << (puzzles[i][0] - 'a'));
                if(t && mp.count(j))
                    res[i] += mp[j];
            }
        }

        return res;
    }
};


������˷����й����������һ��Ӣ�İ������С��Ϸ���������²¿��ɡ�

���յ�����?puzzle ���ַ�����ʽ���������һ������?word?��������������������ô���Ϳ��������յף�

����?word?�а�������?puzzle?�ĵ�һ����ĸ��
����?word?�е�ÿһ����ĸ������������?puzzle?���ҵ���
���磬������յ������� "abcdefg"����ô������Ϊ�յ׵ĵ����� "faced", "cabbage", �� "baggage"���� "beefed"��������ĸ "a"���Լ�?"based"�����е� "s" û�г����������У���������Ϊ�յס�
����һ��������?answer�������е�ÿ��Ԫ��?answer[i]?���ڸ����ĵ����б� words �п�����Ϊ��������?puzzles[i]?����Ӧ���յ׵ĵ�����Ŀ��

?

ʾ����

���룺
words = ["aaaa","asas","able","ability","actt","actor","access"], 
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
�����[1,1,3,2,4,0]
���ͣ�
1 �����ʿ�����Ϊ "aboveyz" ���յ� : "aaaa" 
1 �����ʿ�����Ϊ "abrodyz" ���յ� : "aaaa"
3 �����ʿ�����Ϊ "abslute" ���յ� : "aaaa", "asas", "able"
2 �����ʿ�����Ϊ?"absoryz" ���յ� : "aaaa", "asas"
4 �����ʿ�����Ϊ?"actresz" ���յ� : "aaaa", "asas", "actt", "access"
û�е��ʿ�����Ϊ?"gaswxyz" ���յף���Ϊ�б��еĵ��ʶ�������ĸ 'g'��
?

��ʾ��

1 <= words.length <= 10^5
4 <= words[i].length <= 50
1 <= puzzles.length <= 10^4
puzzles[i].length == 7
words[i][j], puzzles[i][j]?����СдӢ����ĸ��
ÿ��?puzzles[i]?���������ַ������ظ���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
