class Solution {
public:
    string interpret(string command) {
        string ans("");
        for(int i = 0; i < command.size(); i++) {
            if(command[i] == 'G') ans += "G";
            else if(command[i + 1] == ')') {
                i++;
                ans += "o";
            } else {
                i += 3;
                ans += "al";
            }
        }

        return ans;
    }
};

�������һ�����Խ����ַ��� command �� Goal ������ ��command �� "G"��"()" ��/�� "(al)" ��ĳ��˳����ɡ�Goal �������Ὣ "G" ����Ϊ�ַ��� "G"��"()" ����Ϊ�ַ��� "o" ��"(al)" ����Ϊ�ַ��� "al" ��Ȼ�󣬰�ԭ˳�򽫾����͵õ����ַ������ӳ�һ���ַ�����

�����ַ��� command ������ Goal ������ �� command �Ľ��ͽ����

?

ʾ�� 1��

���룺command = "G()(al)"
�����"Goal"
���ͣ�Goal ��������������Ĳ���������ʾ��
G -> G
() -> o
(al) -> al
������ӵõ��Ľ���� "Goal"
ʾ�� 2��

���룺command = "G()()()()(al)"
�����"Gooooal"
ʾ�� 3��

���룺command = "(al)G(al)()()G"
�����"alGalooG"
?

��ʾ��

1 <= command.length <= 100
command �� "G"��"()" ��/�� "(al)" ��ĳ��˳�����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/goal-parser-interpretation
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
