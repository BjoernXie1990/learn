class Solution {
public:
    int countMatches(vector<vector<string>>& items, string s, string t) {
        int res = 0;
        for(auto& e : items) {
            if(s == "type" && e[0] == t) res ++;
            else if(s == "color" && e[1] == t) res ++;
            else if(s == "name" && e[2] == t) res++;
        }
        return res;
    }
};


����һ������ items ������?items[i] = [typei, colori, namei] �������� i ����Ʒ�����͡���ɫ�Լ����ơ�

�����һ���������ַ���?ruleKey �� ruleValue ��ʾ�ļ�������

����� i ����Ʒ��������������֮һ������Ϊ����Ʒ������ļ������� ƥ�� ��

ruleKey == "type" �� ruleValue == typei ��
ruleKey == "color" �� ruleValue == colori ��
ruleKey == "name" �� ruleValue == namei ��
ͳ�Ʋ����� ƥ������������Ʒ���� ��

?

ʾ�� 1��

���룺items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
�����1
���ͣ�ֻ��һ����Ʒƥ��������������Ʒ�� ["computer","silver","lenovo"] ��
ʾ�� 2��

���룺items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
�����2
���ͣ�ֻ��������Ʒƥ�����������������Ʒ�ֱ��� ["phone","blue","pixel"] �� ["phone","gold","iphone"] ��ע�⣬["computer","silver","phone"] δƥ���������
?

��ʾ��

1 <= items.length <= 104
1 <= typei.length, colori.length, namei.length, ruleValue.length <= 10
ruleKey ���� "type"��"color" �� "name"
�����ַ�������Сд��ĸ���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/count-items-matching-a-rule
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
