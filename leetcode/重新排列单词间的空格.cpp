class Solution {
public:
    string reorderSpaces(string text) {
        string ans("");
        int n = text.size();
        int num = 0;
        for(auto& ch : text) if(ch == ' ') num++;
        
        int word = 0;
        int p = 0;
        while(p < n) {
            if(text[p] == ' ') {
                p++;
                continue;
            }
            // char
            while(p < n && text[p] != ' ')
                p++;
            word++;
        }
        int cnt = 0;
        if(word == 1) {
            cnt = 0;
        }else {
            cnt = num / (word - 1);
        }
            
        int tail = num - cnt * (word - 1);
        p = 0;
        while(p < n) {
            if(text[p] == ' ') {
                p++;
                continue;
            }
            //word
            while(p < n && text[p] != ' ') 
                ans += text[p++];
            
            //space
            for(int i = 0; i < cnt; i++)
                ans += ' ';
        }
        for(int i = ans.size()-1; i >= 0; i--) {
            if(ans[i] != ' ') break;
            ans.erase(ans.begin() + i);
        }
        //tail
        for(int i = 0; i < tail; i++)
            ans += ' ';
        return ans;
    }
};

����һ���ַ��� text �����ַ��������ɱ��ո��Χ�ĵ�����ɡ�ÿ��������һ�����߶��СдӢ����ĸ��ɣ�������������֮�����ٴ���һ���ո���Ŀ����������֤ text ���ٰ���һ������ ��

�����������пո�ʹÿ�����ڵ���֮��Ŀո���Ŀ�� ��� ���������� ��� ����Ŀ�������������ƽ���������пո��� ������Ŀո�������ַ���ĩβ ����Ҳ��ζ�ŷ��ص��ַ���Ӧ����ԭ text �ַ����ĳ�����ȡ�

���� �������пո����ַ��� ��

?

ʾ�� 1��

���룺text = "  this   is  a sentence "
�����"this   is   a   sentence"
���ͣ��ܹ��� 9 ���ո�� 4 �����ʡ����Խ� 9 ���ո�ƽ�����䵽���ڵ���֮�䣬���ڵ��ʼ�ո���Ϊ��9 / (4-1) = 3 ����
ʾ�� 2��

���룺text = " practice   makes   perfect"
�����"practice   makes   perfect "
���ͣ��ܹ��� 7 ���ո�� 3 �����ʡ�7 / (3-1) = 3 ���ո���� 1 ������Ŀո񡣶���Ŀո���Ҫ�����ַ�����ĩβ��
ʾ�� 3��

���룺text = "hello   world"
�����"hello   world"
ʾ�� 4��

���룺text = "  walks  udp package   into  bar a"
�����"walks  udp  package  into  bar  a "
ʾ�� 5��

���룺text = "a"
�����"a"
?

��ʾ��

1 <= text.length <= 100
text ��СдӢ����ĸ�� ' ' ���
text �����ٰ���һ������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/rearrange-spaces-between-words
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
