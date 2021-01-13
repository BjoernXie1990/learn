class Solution {
public:
    int maximumGain(string s, int x, int y) {      
        int n = s.size();
        int res = 0;
        if(x < y) {
            swap(x,y);
            for(auto& e : s) {
                if(e == 'a') e = 'b';
                else if(e == 'b') e = 'a';
            }
        }
        stack<int> a,b;
        
        for(int i = 0; i< n; i++) {
            if(s[i] != 'a' && s[i] != 'b') {
                while(b.size() && a.size()) {
                    int tb = b.top();b.pop();
                    int ta = a.top();a.pop();
                    if(ta > tb) res += y;
                    else res += x;
                }
                a = stack<int> ();
                b = stack<int> ();
                continue;
            }
            
            if(s[i] == 'a') a.push(i);
            else b.push(i);
            
            while(b.size() && a.size() && b.top() > a.top() ) {
                a.pop();
                b.pop();
                res += x;
            }
        }
        
        while(b.size() && a.size()) {
            int tb = b.top();b.pop();
            int ta = a.top();a.pop();
            if(ta > tb) res += y;
            else res += x;
        }
        return res;
    }
};

����һ���ַ���?s?����������?x ��?y?�������ִ���������ֲ�������Ρ�

ɾ�����ַ���?"ab"?���õ�?x?�֡�
�ȷ�˵����?"cabxbae"?ɾ�� ab?���õ�?"cxbae"?��
ɾ�����ַ���"ba"?���õ�?y?�֡�
�ȷ�˵����?"cabxbae"?ɾ�� ba?���õ�?"cabxe"?��
�뷵�ض� s?�ַ���ִ������������ɴ��ܵõ������÷֡�

?

ʾ�� 1��

���룺s = "cdbcbbaaabab", x = 4, y = 5
�����19
���ͣ�
- ɾ�� "cdbcbbaaabab" �мӴֵ� "ba" ���õ� s = "cdbcbbaaab" ���� 5 �֡�
- ɾ�� "cdbcbbaaab" �мӴֵ� "ab" ���õ� s = "cdbcbbaa" ���� 4 �֡�
- ɾ�� "cdbcbbaa" �мӴֵ� "ba" ���õ� s = "cdbcba" ���� 5 �֡�
- ɾ�� "cdbcba" �мӴֵ� "ba" ���õ� s = "cdbc" ���� 5 �֡�
�ܵ÷�Ϊ 5 + 4 + 5 + 5 = 19 ��
ʾ�� 2��

���룺s = "aabbaaxybbaabb", x = 5, y = 4
�����20
?

��ʾ��

1 <= s.length <= 105
1 <= x, y <= 104
s?ֻ����СдӢ����ĸ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-score-from-removing-substrings
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
