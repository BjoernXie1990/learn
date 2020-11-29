class Solution {
public:
    bool isTransformable(string s, string t) {
        stack<int> st[10];
        for(int i = 0; i < s.size(); i++) 
            st[s[i] - '0'].push(i);
        
        for(int i = t.size() - 1; i >= 0; i--) {
            int p = t[i] - '0';
            if(st[p].empty())
                return false;
            
            for(int j = p + 1; j < 10; j++)
                if(!st[j].empty() && st[p].top() < st[j].top())
                    return false;
            st[p].pop();
        }

        return true;
    }
};


���������ַ���?s ��?t?������ͨ�����ɴ����²������ַ���?s?ת�����ַ���?t?��

ѡ�� s?��һ�� �ǿ�?���ַ����������������ַ��͵� ����?����
�ȷ�˵�����»�����ʾ�����ַ������в���������?"14234"?�õ�?"12344"?��

������Խ��ַ��� s?��� t?������ true?�����򣬷��� false?��

һ�� ���ַ���?����Ϊһ���ַ����������������ַ���

?

ʾ�� 1��

���룺s = "84532", t = "34852"
�����true
���ͣ�����԰����²����� s ת��Ϊ t ��
"84532" �����±� 2 ���±� 3��-> "84352"
"84352" �����±� 0 ���±� 2�� -> "34852"
ʾ�� 2��

���룺s = "34521", t = "23415"
�����true
���ͣ�����԰����²����� s ת��Ϊ t ��
"34521" -> "23451"
"23451" -> "23415"
ʾ�� 3��

���룺s = "12345", t = "12435"
�����false
ʾ�� 4��

���룺s = "1", t = "2"
�����false
?

��ʾ��

s.length == t.length
1 <= s.length <= 105
s ��?t?��ֻ���������ַ�����?'0'?��?'9' ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/check-if-string-is-transformable-with-substring-sort-operations
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
