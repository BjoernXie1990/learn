class Solution {
public:
    string evaluate(string s, vector<vector<string>>& t) {
        unordered_map<string,string> mp;
        for(auto& e : t) {
            mp[e[0]] = e[1];
        }
        
        string res("");
        int i = 0;
        while(i < s.size()) {
            if(s[i] == '(') {
                string t("");
                i++;
                while(s[i] != ')')
                    t += s[i ++];
                
                i ++;
                if(mp.count(t)) {
                    res += mp[t];
                } else {
                    res += "?";
                }
                
                continue;
            }
            res += s[i ++];
            
        }
        
        return res;
    }
};


����һ���ַ���?s?��������һЩ���Ŷԣ�ÿ�������а���һ�� �ǿ�?�ļ���

�ȷ�˵���ַ���?"(name)is(age)yearsold"?�У���?����?���Ŷԣ��ֱ������?"name" ��?"age"?��
��֪��������Ӧ��ֵ����Щ��ϵ�ɶ�ά�ַ�������?knowledge?��ʾ������?knowledge[i] = [keyi, valuei]?����ʾ��?keyi?��Ӧ��ֵΪ?valuei?��

����Ҫ�滻 ����?�����Ŷԡ������滻һ�����Ŷԣ����������ļ�Ϊ?keyi?ʱ������Ҫ��

��?keyi?�������ö�Ӧ��ֵ?valuei?�滻��
����� knowledge?���޷���֪ĳ������Ӧ��ֵ������Ҫ��?keyi?���������ʺ�?"?"?�滻������Ҫ���ţ���
knowledge?��ÿ�������ֻ�����һ�Ρ�s?�в�����Ƕ�׵����š�

���㷵���滻 ����?���ŶԺ�Ľ���ַ�����

?

ʾ�� 1��

���룺s = "(name)is(age)yearsold", knowledge = [["name","bob"],["age","two"]]
�����"bobistwoyearsold"
���ͣ�
�� "name" ��Ӧ��ֵΪ "bob" �����Խ� "(name)" �滻Ϊ "bob" ��
�� "age" ��Ӧ��ֵΪ "two" �����Խ� "(age)" �滻Ϊ "two" ��
ʾ�� 2��

���룺s = "hi(name)", knowledge = [["a","b"]]
�����"hi?"
���ͣ����ڲ�֪���� "name" ��Ӧ��ֵ�������� "?" �滻 "(name)" ��
ʾ�� 3��

���룺s = "(a)(a)(a)aaa", knowledge = [["a","yes"]]
�����"yesyesyesaaa"
���ͣ���ͬ�ļ��� s �п��ܻ���ֶ�Ρ�
�� "a" ��Ӧ��ֵΪ "yes" �����Խ����е� "(a)" �滻Ϊ "yes" ��
ע�⣬����������� "a" ����Ҫ���滻��
ʾ�� 4��

���룺s = "(a)(b)", knowledge = [["a","b"],["b","a"]]
�����"ba"
?

��ʾ��

1 <= s.length <= 105
0 <= knowledge.length <= 105
knowledge[i].length == 2
1 <= keyi.length, valuei.length <= 10
s?ֻ����СдӢ����ĸ��Բ����?'('?��?')'?��
s?��ÿһ����Բ����?'('?���ж�Ӧ����Բ����?')'?��
s?��ÿ�������ڵļ�������Ϊ�ա�
s?�в�����Ƕ�����Ŷԡ�
keyi?��?valuei?ֻ����СдӢ����ĸ��
knowledge?�е�?keyi?�����ظ���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/evaluate-the-bracket-pairs-of-a-string
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
