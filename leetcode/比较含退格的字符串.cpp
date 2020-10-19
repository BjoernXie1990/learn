class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string le = GetStr(S);
        string ri = GetStr(T);

        return le == ri;
    }

    string GetStr(string& str) {
        string ans("");
        int cnt = 0;

        int n = str.size();
        for(int i = n-1; i >= 0; i--) {
            if(str[i] == '#') cnt ++;
            else {
                if(cnt == 0) ans += str[i];
                else if(cnt > 0) cnt --;
            }
        }

        return ans;
    }
};

���� S �� T �����ַ����������Ƿֱ����뵽�հ׵��ı��༭�����ж϶����Ƿ���ȣ������ؽ���� # �����˸��ַ���

ע�⣺����Կ��ı������˸��ַ����ı�����Ϊ�ա�

?

ʾ�� 1��

���룺S = "ab#c", T = "ad#c"
�����true
���ͣ�S �� T ������ ��ac����
ʾ�� 2��

���룺S = "ab##", T = "c#d#"
�����true
���ͣ�S �� T ������ ������
ʾ�� 3��

���룺S = "a##c", T = "#a#c"
�����true
���ͣ�S �� T ������ ��c����
ʾ�� 4��

���룺S = "a#c", T = "b"
�����false
���ͣ�S ���� ��c������ T ��Ȼ�� ��b����
?

��ʾ��

1 <= S.length <= 200
1 <= T.length <= 200
S �� T ֻ����Сд��ĸ�Լ��ַ� '#'��
?

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/backspace-string-compare
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
